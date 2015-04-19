--- content/common/gpu/gpu_memory_manager.h.orig	Sat Jul 19 05:41:40 2014
+++ content/common/gpu/gpu_memory_manager.h	Sat Jul 19 05:44:26 2014
@@ -28,7 +28,7 @@
 class CONTENT_EXPORT GpuMemoryManager :
     public base::SupportsWeakPtr<GpuMemoryManager> {
  public:
-#if defined(OS_ANDROID) || (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if defined(OS_ANDROID) || (defined(OS_LINUX) && !defined(OS_CHROMEOS)) || defined(OS_BSD)
   enum { kDefaultMaxSurfacesWithFrontbufferSoftLimit = 1 };
 #else
   enum { kDefaultMaxSurfacesWithFrontbufferSoftLimit = 8 };
