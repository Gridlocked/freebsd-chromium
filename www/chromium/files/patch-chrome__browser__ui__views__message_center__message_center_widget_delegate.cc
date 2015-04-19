--- chrome/browser/ui/views/message_center/message_center_widget_delegate.cc.orig.port	Wed Sep 10 01:47:12 2014
+++ chrome/browser/ui/views/message_center/message_center_widget_delegate.cc	Wed Sep 10 22:05:40 2014
@@ -97,7 +97,7 @@ void MessageCenterWidgetDelegate::OnWidgetActivationCh
   // immediately after the mouse exists from the bubble, which is a really bad
   // experience. Disable hiding until the bug around the focus is fixed.
   // TODO(erg, pkotwicz): fix the activation issue and then remove this ifdef.
-#if !defined(OS_LINUX)
+#if !defined(OS_LINUX) && !defined(OS_BSD)
   if (!active) {
     tray_->SendHideMessageCenter();
   }
