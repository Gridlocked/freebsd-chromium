--- content/browser/power_usage_monitor_impl.cc.orig.port	Wed Mar 11 22:02:40 2015
+++ content/browser/power_usage_monitor_impl.cc	Wed Mar 11 22:02:54 2015
@@ -18,6 +18,8 @@
 #include "content/public/browser/power_usage_monitor.h"
 #include "content/public/browser/render_process_host.h"
 
+#include <math.h>
+
 namespace content {
 
 namespace {
