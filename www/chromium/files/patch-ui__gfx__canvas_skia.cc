--- ui/gfx/canvas_skia.cc.orig	Wed Dec  3 03:13:29 2014
+++ ui/gfx/canvas_skia.cc	Sat Dec  6 11:34:27 2014
@@ -287,7 +287,7 @@
     Range range = StripAcceleratorChars(flags, &adjusted_text);
     bool elide_text = ((flags & NO_ELLIPSIS) == 0);
 
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
     // On Linux, eliding really means fading the end of the string. But only
     // for LTR text. RTL text is still elided (on the left) with "...".
     if (elide_text) {
