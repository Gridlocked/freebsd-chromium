--- ui/events/devices/x11/device_data_manager_x11.cc.orig	Tue Mar 10 23:41:42 2015
+++ ui/events/devices/x11/device_data_manager_x11.cc	Wed Mar 11 07:22:50 2015
@@ -681,6 +681,8 @@
 }
 
 void DeviceDataManagerX11::DisableDevice(unsigned int deviceid) {
+  NOTIMPLEMENTED();
+#if !defined(OS_BSD) ///XXXROBERT
   blocked_devices_.set(deviceid, true);
   // TODO(rsadam@): Support blocking touchscreen devices.
   std::vector<KeyboardDevice> keyboards = keyboard_devices();
@@ -694,6 +696,7 @@ void DeviceDataManagerX11::DisableDevice(unsigned int 
     keyboards.erase(it);
     DeviceDataManager::OnKeyboardDevicesUpdated(keyboards);
   }
+#endif
 }
 
 void DeviceDataManagerX11::EnableDevice(unsigned int deviceid) {
