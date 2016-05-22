--- content/browser/gpu/gpu_internals_ui.cc.orig	Thu Apr 14 14:01:47 2016
+++ content/browser/gpu/gpu_internals_ui.cc	Thu Apr 14 14:02:13 2016
@@ -37,7 +37,7 @@
 #include "third_party/angle/src/common/version.h"
 #include "ui/gl/gpu_switching_manager.h"
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include <X11/Xlib.h>
 #endif
 #if defined(OS_WIN)
@@ -45,7 +45,7 @@
 #include "ui/gfx/win/physical_size.h"
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include "ui/base/x/x11_util.h"
 #include "ui/gfx/x/x11_atom_cache.h"
 #endif
@@ -198,7 +198,7 @@ base::DictionaryValue* GpuInfoAsDictionaryValue() {
                                              gpu_info.gl_ws_version));
   basic_info->Append(NewDescriptionValuePair("Window system binding extensions",
                                              gpu_info.gl_ws_extensions));
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
   basic_info->Append(NewDescriptionValuePair("Window manager",
                                              ui::GuessWindowManagerName()));
   {