--- third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc.orig	2017-03-09 20:05:29 UTC
+++ third_party/webrtc/modules/rtp_rtcp/source/forward_error_correction.cc
@@ -13,6 +13,7 @@
 #include <string.h>
 
 #include <algorithm>
+#include <cstdlib>
 #include <iterator>
 #include <utility>
 
