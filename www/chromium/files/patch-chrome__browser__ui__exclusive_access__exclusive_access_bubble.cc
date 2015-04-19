--- chrome/browser/ui/exclusive_access/exclusive_access_bubble.cc.orig.port	Wed Mar 11 07:33:06 2015
+++ chrome/browser/ui/exclusive_access/exclusive_access_bubble.cc	Wed Mar 11 07:33:16 2015
@@ -18,7 +18,7 @@
 
 // NOTE(koz): Linux doesn't use the thick shadowed border, so we add padding
 // here.
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
 const int ExclusiveAccessBubble::kPaddingPx = 8;
 #else
 const int ExclusiveAccessBubble::kPaddingPx = 15;
