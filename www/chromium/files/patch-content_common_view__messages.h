--- content/common/view_messages.h.orig	2017-03-09 20:04:32 UTC
+++ content/common/view_messages.h
@@ -246,7 +246,7 @@ IPC_STRUCT_TRAITS_BEGIN(content::Rendere
   IPC_STRUCT_TRAITS_MEMBER(plugin_fullscreen_allowed)
   IPC_STRUCT_TRAITS_MEMBER(use_video_overlay_for_embedded_encrypted_video)
   IPC_STRUCT_TRAITS_MEMBER(network_contry_iso)
-#if defined(OS_LINUX)
+#if defined(OS_LINUX) || defined(OS_BSD)
   IPC_STRUCT_TRAITS_MEMBER(system_font_family_name)
 #endif
 #if defined(OS_WIN)
