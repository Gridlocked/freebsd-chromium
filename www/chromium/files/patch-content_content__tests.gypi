--- content/content_tests.gypi.orig	2016-05-11 19:02:21 UTC
+++ content/content_tests.gypi
@@ -1310,6 +1310,15 @@
                 'renderer/media/video_track_recorder_unittest.cc',
               ],
             }],
+            ['OS == "freebsd"', {
+              'sources!': [
+                'browser/download/file_metadata_unittest_linux.cc',
+                'browser/geolocation/wifi_data_provider_linux_unittest.cc',
+                'browser/renderer_host/media/media_stream_dispatcher_host_unittest.cc',
+                'browser/renderer_host/media/media_stream_manager_unittest.cc',
+                'browser/renderer_host/media/media_stream_ui_controller_unittest.cc'
+              ]
+            }],
             # Avoid windows due to non-availability of cursor resources in test.
             ['OS != "linux"', {
               'sources!': [
