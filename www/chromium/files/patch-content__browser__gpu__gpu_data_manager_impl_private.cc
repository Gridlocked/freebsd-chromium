--- content/browser/gpu/gpu_data_manager_impl_private.cc.orig	2016-05-11 15:02:20.000000000 -0400
+++ content/browser/gpu/gpu_data_manager_impl_private.cc	2016-05-19 20:20:30.622995000 -0400
@@ -486,8 +486,10 @@
   gpu_info.gl_renderer = gl_renderer;
   gpu_info.gl_version = gl_version;
 
+#if !defined(OS_FREEBSD)
   gpu::IdentifyActiveGPU(&gpu_info);
   gpu::CollectDriverInfoGL(&gpu_info);
+#endif
 
   UpdateGpuInfo(gpu_info);
   UpdateGpuSwitchingManager(gpu_info);
@@ -529,10 +531,12 @@
     // Also declare the driver_vendor to be osmesa to be able to specify
     // exceptions based on driver_vendor==osmesa for some blacklist rules.
     gpu_info.driver_vendor = gfx::kGLImplementationOSMesaName;
+#ifndef __FreeBSD__
   } else {
     TRACE_EVENT0("startup",
       "GpuDataManagerImpl::Initialize:CollectBasicGraphicsInfo");
     gpu::CollectBasicGraphicsInfo(&gpu_info);
+#endif
 
     if (command_line->HasSwitch(switches::kGpuTestingVendorId) &&
         command_line->HasSwitch(switches::kGpuTestingDeviceId)) {
@@ -631,7 +635,9 @@
     return;
 
   bool was_info_available = IsCompleteGpuInfoAvailable();
+#ifndef __FreeBSD__
   gpu::MergeGPUInfo(&gpu_info_, gpu_info);
+#endif
   if (IsCompleteGpuInfoAvailable()) {
     complete_gpu_info_already_requested_ = true;
   } else if (was_info_available) {
