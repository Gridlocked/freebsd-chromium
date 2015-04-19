--- gpu/gpu_config.gypi.orig	Sat Dec  6 11:47:02 2014
+++ gpu/gpu_config.gypi	Sat Dec  6 11:47:29 2014
@@ -65,12 +65,12 @@
         '../third_party/amd/amd_videocard_info_win.cc',
       ],
     }],
-    ['OS=="linux" and use_libpci==1 and (use_x11==1 or use_ozone==1)', {
+    ['(OS=="linux" or os_bsd==1) and use_libpci==1 and (use_x11==1 or use_ozone==1)', {
       'dependencies': [
         '../build/linux/system.gyp:libpci',
       ],
     }],
-    ['OS=="linux" and use_x11==1', {
+    ['(OS=="linux" or os_bsd==1) and use_x11==1', {
       'dependencies': [
         '../build/linux/system.gyp:x11',
         '../build/linux/system.gyp:xext',

