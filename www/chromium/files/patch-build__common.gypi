--- ./build/common.gypi.orig	2014-06-30 21:01:10.000000000 +0200
+++ ./build/common.gypi	2014-07-08 20:00:40.000000000 +0200
@@ -101,7 +101,8 @@
             #
             # TODO(erg): Merge this into the previous block once compiling with
             # aura safely implies including ash capabilities.
-            ['OS=="linux"', {
+            # XXX(rene): enable on FreeBSD too
+            ['OS=="linux" or OS=="freebsd"', {
               'use_aura%': 1,
             }],
 
@@ -622,7 +623,7 @@
         }],
 
         # DBus usage.
-        ['OS=="linux" and embedded==0', {
+        ['(OS=="linux" or OS=="freebsd") and embedded==0', {
           'use_dbus%': 1,
         }, {
           'use_dbus%': 0,
@@ -896,7 +897,7 @@
         # except when building Android WebView.
         # TODO(jshin): Handle 'use_system_icu' on Linux (Chromium).
         # Set the data reduction proxy origin for Android Webview.
-        ['android_webview_build==0', {
+        ['android_webview_build==0 and OS!="freebsd" and OS!="openbsd"', {
           'icu_use_data_file_flag%' : 1,
           'spdy_proxy_auth_origin%': '',
           'data_reduction_proxy_probe_url%': '',
@@ -1106,6 +1107,9 @@
     # able to turn it off for various reasons.
     'linux_disable_pie%': 0,
 
+    'os_ver%': 0,
+    'use_system_libjpeg%': 0,
+
     # The release channel that this build targets. This is used to restrict
     # channel-specific build options, like which installer packages to create.
     # The default is 'all', which does no channel-specific filtering.
@@ -3960,6 +3964,13 @@
         'ldflags': [
           '-Wl,--no-keep-memory',
         ],
+        'ldflags!': [
+          '-ldl',
+          '-pie',
+        ],
+        'libraries!': [
+          '-ldl',
+        ],
       },
     }],
     # Android-specific options; note that most are set above with Linux.
