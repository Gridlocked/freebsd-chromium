--- media/audio/audio_input_controller.cc.orig	Sat Dec  6 14:44:50 2014
+++ media/audio/audio_input_controller.cc	Sat Dec  6 14:44:57 2014
@@ -13,6 +13,8 @@
 #include "media/base/scoped_histogram_timer.h"
 #include "media/base/user_input_monitor.h"
 
+#include <math.h>
+
 using base::TimeDelta;
 
 namespace {
