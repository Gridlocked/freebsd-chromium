--- net/base/network_change_notifier.cc.orig	2017-03-09 20:04:35 UTC
+++ net/base/network_change_notifier.cc
@@ -533,7 +533,6 @@ NetworkChangeNotifier* NetworkChangeNoti
 #elif defined(OS_MACOSX)
   return new NetworkChangeNotifierMac();
 #else
-  NOTIMPLEMENTED();
   return NULL;
 #endif
 }
