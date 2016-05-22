--- chrome/browser/extensions/external_provider_impl.cc.orig.port	Sat Apr 16 12:36:50 2016
+++ chrome/browser/extensions/external_provider_impl.cc	Sat Apr 16 12:37:08 2016
@@ -645,7 +645,7 @@ void ExternalProviderImpl::CreateExternalProviders(
                                  Manifest::EXTERNAL_PREF_DOWNLOAD,
                                  oem_extension_creation_flags)));
   }
-#elif defined(OS_LINUX)
+#elif defined(OS_LINUX) || defined(OS_BSD)
   if (!profile->IsLegacySupervised()) {
     provider_list->push_back(
         linked_ptr<ExternalProviderInterface>(
@@ -687,7 +687,7 @@ void ExternalProviderImpl::CreateExternalProviders(
                 bundled_extension_creation_flags)));
 
     // Define a per-user source of external extensions.
-#if defined(OS_MACOSX) || (defined(OS_LINUX) && defined(CHROMIUM_BUILD))
+#if defined(OS_MACOSX) || ((defined(OS_LINUX) || defined(OS_BSD)) && defined(CHROMIUM_BUILD))
     provider_list->push_back(
         linked_ptr<ExternalProviderInterface>(
             new ExternalProviderImpl(