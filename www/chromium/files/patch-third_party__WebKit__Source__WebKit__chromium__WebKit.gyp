--- third_party/WebKit/Source/WebKit/chromium/WebKit.gyp.orig	2013-07-15 19:48:12.000000000 +0300
+++ third_party/WebKit/Source/WebKit/chromium/WebKit.gyp	2013-07-15 19:48:46.000000000 +0300
@@ -646,7 +646,7 @@
                       },
                     },
                 }],
-                ['OS == "linux"', {
+                ['OS == "linux" or os_bsd == 1', {
                     'dependencies': [
                         '<(DEPTH)/build/linux/system.gyp:fontconfig',
                     ],
