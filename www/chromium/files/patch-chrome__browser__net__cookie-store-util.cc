--- chrome/browser/net/cookie_store_util.cc.orig.port	Tue Mar 10 23:41:40 2015
+++ chrome/browser/net/cookie_store_util.cc	Wed Mar 11 07:22:50 2015
@@ -120,7 +120,7 @@ net::CookieMonsterDelegate* CreateCookieDelegate(Profi
       new ChromeCookieMonsterDelegate(profile));
 }
 
-#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_MACOSX) || defined(OS_LINUX) || defined(OS_BSD)
 namespace {
 
 // Use the operating system's mechanisms to encrypt cookies before writing
