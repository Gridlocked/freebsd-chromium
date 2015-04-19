--- gpu/config/gpu_info_collector_linux.cc.orig	Tue Mar 10 23:41:41 2015
+++ gpu/config/gpu_info_collector_linux.cc	Wed Mar 11 07:22:50 2015
@@ -77,6 +77,10 @@
 CollectInfoResult CollectPCIVideoCardInfo(GPUInfo* gpu_info) {
   DCHECK(gpu_info);
 
+#if defined(OS_BSD)
+  return (CollectMesaCardInfo(gpu_info));
+#endif
+
 #if !defined(USE_LIBPCI)
   return kCollectInfoNonFatalFailure;
 #else
