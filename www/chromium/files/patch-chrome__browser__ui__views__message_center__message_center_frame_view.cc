--- chrome/browser/ui/views/message_center/message_center_frame_view.cc.orig.port	Sat Jul 19 03:27:25 2014
+++ chrome/browser/ui/views/message_center/message_center_frame_view.cc	Sat Jul 19 03:30:52 2014
@@ -12,7 +12,7 @@
 namespace message_center {
 
 MessageCenterFrameView::MessageCenterFrameView() {
-#if defined(OS_LINUX) && !defined(OS_CHROMEOS)
+#if (defined(OS_LINUX) || defined(OS_BSD)) && !defined(OS_CHROMEOS)
   const int kBorderWidth = 1;
   SetBorder(views::Border::CreateSolidBorder(
       kBorderWidth, message_center::kMessageCenterBorderColor));
