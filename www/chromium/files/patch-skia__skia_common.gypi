--- ./skia/skia_common.gypi.orig	2014-06-30 21:01:22.000000000 +0200
+++ ./skia/skia_common.gypi	2014-07-07 15:12:49.000000000 +0200
@@ -66,7 +66,7 @@
     }],
 
     #Settings for text blitting, chosen to approximate the system browser.
-    [ 'OS == "linux"', {
+    [ 'OS == "linux" or os_bsd == 1', {
       'defines': [
         'SK_GAMMA_EXPONENT=1.2',
         'SK_GAMMA_CONTRAST=0.2',
