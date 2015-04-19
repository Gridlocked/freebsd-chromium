--- content/browser/gpu/gpu_internals_ui.cc.orig.port	Sun Feb 15 10:56:09 2015
+++ content/browser/gpu/gpu_internals_ui.cc	Sun Feb 15 10:56:33 2015
@@ -4,7 +4,7 @@
 
 #include "content/browser/gpu/gpu_internals_ui.h"
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include <X11/Xlib.h>
 #endif
 
@@ -40,7 +40,7 @@
 #include "ui/base/win/shell.h"
 #endif
 
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
 #include "ui/base/x/x11_util.h"
 #include "ui/gfx/x/x11_atom_cache.h"
 #endif
@@ -172,7 +172,7 @@ base::DictionaryValue* GpuInfoAsDictionaryValue() {
                                              gpu_info.gl_ws_version));
   basic_info->Append(NewDescriptionValuePair("Window system binding extensions",
                                              gpu_info.gl_ws_extensions));
-#if defined(OS_LINUX) && defined(USE_X11)
+#if (defined(OS_BSD) || defined(OS_LINUX)) && defined(USE_X11)
   basic_info->Append(NewDescriptionValuePair("Window manager",
                                              ui::GuessWindowManagerName()));
   {
