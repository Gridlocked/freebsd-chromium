--- gpu/command_buffer/service/async_pixel_transfer_manager_share_group.cc.orig	Fri Dec 26 19:54:22 2014
+++ gpu/command_buffer/service/async_pixel_transfer_manager_share_group.cc	Fri Dec 26 19:54:30 2014
@@ -46,7 +46,7 @@
       : base::Thread(kAsyncTransferThreadName),
         initialized_(false) {
     Start();
-#if defined(OS_ANDROID) || defined(OS_LINUX)
+#if defined(OS_ANDROID) || defined(OS_LINUX) || defined(OS_BSD)
     SetPriority(base::kThreadPriority_Background);
 #endif
   }
