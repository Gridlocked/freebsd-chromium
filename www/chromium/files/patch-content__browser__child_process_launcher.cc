--- content/browser/child_process_launcher.cc.orig	2015-01-21 20:28:16 UTC
+++ content/browser/child_process_launcher.cc
@@ -121,7 +121,7 @@
   // Notifies the client about the result of the operation.
   // Runs on the UI thread.
   void Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::Process process);
@@ -132,7 +132,7 @@
                                              bool background);
 
   static void TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       bool zygote,
 #endif
       base::Process process);
@@ -145,7 +145,7 @@
 #if defined(OS_ANDROID)
   // The fd to close after creating the process.
   base::ScopedFD ipcfd_;
-#elif defined(OS_POSIX) && !defined(OS_MACOSX)
+#elif defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
   bool zygote_;
 #endif
   bool starting_;
@@ -159,7 +159,7 @@
       client_thread_id_(BrowserThread::UI),
       termination_status_(base::TERMINATION_STATUS_NORMAL_TERMINATION),
       exit_code_(RESULT_CODE_NORMAL_EXIT),
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
       zygote_(false),
 #endif
       starting_(true),
@@ -239,7 +239,7 @@
 }
 
 void ChildProcessLauncher::Context::UpdateTerminationStatus(bool known_dead) {
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   if (zygote_) {
     termination_status_ = ZygoteHostImpl::GetInstance()->
         GetTerminationStatus(process_.Handle(), known_dead, &exit_code_);
@@ -247,7 +247,7 @@
     termination_status_ =
         base::GetKnownDeadTerminationStatus(process_.Handle(), &exit_code_);
   } else {
-#elif defined(OS_MACOSX)
+#elif defined(OS_MACOSX) || defined(OS_BSD)
   if (known_dead) {
     termination_status_ =
         base::GetKnownDeadTerminationStatus(process_.Handle(), &exit_code_);
@@ -317,7 +317,9 @@
   base::EnvironmentMap env = delegate->GetEnvironment();
   base::ScopedFD ipcfd = delegate->TakeIpcFd();
 #elif defined(OS_POSIX)
+#if !defined(OS_BSD)
   bool use_zygote = delegate->ShouldUseZygote();
+#endif
   base::EnvironmentMap env = delegate->GetEnvironment();
   base::ScopedFD ipcfd = delegate->TakeIpcFd();
 #endif
@@ -375,7 +377,7 @@
   // We need to close the client end of the IPC channel to reliably detect
   // child termination.
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   GetContentClient()->browser()->GetAdditionalMappedFilesForChildProcess(
       *cmd_line, child_process_id, files_to_register.get());
   if (use_zygote) {
@@ -390,7 +392,7 @@
         files_to_register->GetMappingWithIDAdjustment(
             base::GlobalDescriptors::kBaseDescriptor);
 
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
     if (process_type == switches::kRendererProcess) {
       const int sandbox_fd =
           RenderSandboxHostLinux::GetInstance()->GetRendererSocket();
@@ -457,7 +459,7 @@
       client_thread_id, FROM_HERE,
       base::Bind(&Context::Notify,
                  this_object.get(),
-#if defined(OS_POSIX) && !defined(OS_MACOSX)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_BSD)
                  use_zygote,
 #endif
                  base::Passed(&process)));
@@ -465,7 +467,7 @@
 }
 
 void ChildProcessLauncher::Context::Notify(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     bool zygote,
 #endif
     base::Process process) {
@@ -478,7 +480,7 @@
   if (!process_.IsValid())
     LOG(ERROR) << "Failed to launch child process";
 
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
   zygote_ = zygote;
 #endif
   if (client_) {
@@ -504,7 +506,7 @@
   BrowserThread::PostTask(
       BrowserThread::PROCESS_LAUNCHER, FROM_HERE,
       base::Bind(&Context::TerminateInternal,
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
                 zygote_,
 #endif
                 base::Passed(&process_)));
@@ -522,7 +524,7 @@
 
 // static
 void ChildProcessLauncher::Context::TerminateInternal(
-#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID)
+#if defined(OS_POSIX) && !defined(OS_MACOSX) && !defined(OS_ANDROID) && !defined(OS_BSD)
     bool zygote,
 #endif
     base::Process process) {
@@ -536,7 +538,7 @@
   process.Terminate(RESULT_CODE_NORMAL_EXIT);
   // On POSIX, we must additionally reap the child.
 #if defined(OS_POSIX)
-#if !defined(OS_MACOSX)
+#if !defined(OS_MACOSX) && !defined(OS_BSD)
   if (zygote) {
     // If the renderer was created via a zygote, we have to proxy the reaping
     // through the zygote process.
