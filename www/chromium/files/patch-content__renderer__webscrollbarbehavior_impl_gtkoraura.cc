--- content/renderer/webscrollbarbehavior_impl_gtkoraura.cc.orig	Tue Mar 10 23:29:11 2015
+++ content/renderer/webscrollbarbehavior_impl_gtkoraura.cc	Wed Mar 18 20:01:29 2015
@@ -13,7 +13,7 @@
       blink::WebScrollbarBehavior::Button mouseButton,
       bool shiftKeyPressed,
       bool altKeyPressed) {
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   if (mouseButton == blink::WebScrollbarBehavior::ButtonMiddle)
     return true;
 #endif
@@ -49,7 +49,7 @@
   // On most platforms, we should snap iff the event is outside our calculated
   // rect.  On Linux, however, we should not snap for events off the ends, but
   // not the sides, of the rect.
-#if (defined(OS_LINUX) && !defined(OS_CHROMEOS))
+#if (defined(OS_BSD) || defined(OS_LINUX)) && !defined(OS_CHROMEOS)
   return isHorizontal ?
       (eventPoint.y < noSnapRect.y() || eventPoint.y >= noSnapRect.bottom()) :
       (eventPoint.x < noSnapRect.x() || eventPoint.x >= noSnapRect.right());
