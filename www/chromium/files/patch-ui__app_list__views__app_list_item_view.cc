--- ui/app_list/views/app_list_item_view.cc.orig	Tue Mar 10 23:41:42 2015
+++ ui/app_list/views/app_list_item_view.cc	Wed Mar 11 07:22:50 2015
@@ -67,7 +67,7 @@
   const gfx::FontList& font_list = rb.GetFontList(kItemTextFontStyle);
 // The font is different on each platform. The font size is adjusted on some
 // platforms to keep a consistent look.
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   // Reducing the font size by 2 makes it the same as the Windows font size.
   const int kFontSizeDelta = -2;
   return font_list.DeriveWithSizeDelta(kFontSizeDelta);
