--- chrome/common/chrome_paths_internal.h.orig	2017-03-09 20:04:29 UTC
+++ chrome/common/chrome_paths_internal.h
@@ -39,7 +39,7 @@ void GetUserCacheDirectory(const base::F
 // Get the path to the user's documents directory.
 bool GetUserDocumentsDirectory(base::FilePath* result);
 
-#if defined(OS_WIN) || defined(OS_LINUX)
+#if defined(OS_WIN) || defined(OS_LINUX) || defined(OS_BSD)
 // Gets the path to a safe default download directory for a user.
 bool GetUserDownloadsDirectorySafe(base::FilePath* result);
 #endif
