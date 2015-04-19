--- gpu/config/gpu_info_collector_linux.h.orig	Wed Feb 18 17:58:41 2015
+++ gpu/config/gpu_info_collector_linux.h	Wed Feb 18 17:59:22 2015
@@ -6,11 +6,14 @@
 #define GPU_CONFIG_GPU_INFO_COLLECTOR_LINUX_H_
 
 #include <string>
+#include "gpu/config/gpu_info_collector.h"
 
 namespace gpu {
 
 // Queries for the driver version. Returns an empty string on failure.
 std::string CollectDriverVersionNVidia();
+
+CollectInfoResult CollectMesaCardInfo(GPUInfo *);
 
 }  // namespace gpu
 

