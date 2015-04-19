--- gpu/command_buffer/service/async_pixel_transfer_manager_egl.cc.orig	Fri Dec 26 19:54:36 2014
+++ gpu/command_buffer/service/async_pixel_transfer_manager_egl.cc	Fri Dec 26 19:54:53 2014
@@ -89,7 +89,7 @@
  public:
   TransferThread() : base::Thread(kAsyncTransferThreadName) {
     Start();
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     SetPriority(base::kThreadPriority_Background);
 #endif
   }
@@ -467,14 +467,14 @@
 
 void AsyncPixelTransferDelegateEGL::WaitForTransferCompletion() {
   if (state_->TransferIsInProgress()) {
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     g_transfer_thread.Pointer()->SetPriority(base::kThreadPriority_Display);
 #endif
 
     state_->WaitForTransferCompletion();
     DCHECK(!state_->TransferIsInProgress());
 
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     g_transfer_thread.Pointer()->SetPriority(base::kThreadPriority_Background);
 #endif
   }
