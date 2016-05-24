--- chrome/chrome_browser_extensions.gypi.orig	2016-05-11 19:02:17 UTC
+++ chrome/chrome_browser_extensions.gypi
@@ -1023,6 +1023,11 @@
         '<@(chrome_browser_extensions_enabled_sources)',
       ],
       'conditions': [
+        ['os_bsd==1', {
+         'sources/': [
+            ['exclude', '^browser/extensions/api/image_writer_private/removable_storage_provider_linux.cc'],
+         ],
+        }],
         ['chromeos==1', {
           'dependencies': [
             '../build/linux/system.gyp:dbus',
@@ -1065,7 +1070,7 @@
             '../ui/views/views.gyp:views',
           ],
         }],
-        ['OS=="linux"', {
+        ['OS=="linux" or os_bsd==1', {
           'conditions': [
             ['use_aura==1', {
               'dependencies': [