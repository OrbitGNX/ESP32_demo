/*==========================================================================================
                               ESP32 DEV BOARD INFO
============================================================================================
Description:
  This Arduino sketch prints a detailed software information about an ESP32 microcontroller.
  * Chip Info         - Model name, hardware revision, number of CPU cores, and clock frequency
  * Flash Memory      - Total flash storage size (in MB) and speed (in MHz)
  * RAM/Heap          - Free and total heap memory available at boot
  * SDK Version       - The underlying ESP-IDF/Arduino SDK version string
  * MAC Address       - The device's Wi-Fi station MAC address
  * Wireless Features - Whether the chip supports Wi-Fi(BGN), Classic Bluetooth, and BLE

  Design Engineer:
    Gyro Madrona

  Date:
    29 Mar 2026
------------------------------------------------------------------------------------------*/
#include <Arduino.h>
#include <esp_system.h>
#include <esp_chip_info.h>

void setup() {
  Serial.begin(115200);

  // Chip Info
  esp_chip_info_t chip_info;
  esp_chip_info(&chip_info);

  Serial.print("Chip Model: ");
  Serial.println(ESP.getChipModel());

  Serial.print("Chip Revision: ");
  Serial.println(chip_info.revision);

  Serial.print("CPU Cores: ");
  Serial.println(chip_info.cores);

  Serial.print("CPU Frequency: ");
  Serial.print(ESP.getCpuFreqMHz());
  Serial.println(" MHz");

  // Flash Memory
  Serial.print("Flash Size: ");
  Serial.print(ESP.getFlashChipSize()/(1024*1024)); // divides by 1,048,576 to convert to MB
  Serial.println(" MB");

  Serial.print("Flash Speed: ");
  Serial.print(ESP.getFlashChipSpeed()/1000000);
  Serial.println(" MHz");

  // RAM / Heap
  Serial.print("Free Heap: ");
  Serial.print(ESP.getFreeHeap());
  Serial.println(" bytes");

  Serial.print("Total Heap: ");
  Serial.print(ESP.getHeapSize());
  Serial.println(" bytes");

  // SDK & IDF Version
  Serial.print("Arduino Version: ");
  Serial.println(ESP.getSdkVersion());

  // MAC Address
  uint8_t mac[6];
  esp_read_mac(mac, ESP_MAC_WIFI_STA);
  // % - Start of format specifier
  // 0 - Pad with zeros
  // 2 - Minimum width of 2 characters
  // X - Print as uppercase hexadecimal
  Serial.printf("MAC Address: %02x:%02X:%02X:%02X:%02X:%02X\n",
                mac[0],mac[1],mac[2],mac[3],mac[4],mac[6]);

  // Features
  Serial.print("WiFi: ");
  Serial.println((chip_info.features & CHIP_FEATURE_WIFI_BGN)? "Yes":"No");

  Serial.print("Bluetooth: ");
  Serial.println((chip_info.features & CHIP_FEATURE_BT)? "Yes":"No");

  Serial.print("BLE: ");
  Serial.println((chip_info.features & CHIP_FEATURE_BLE)? "Yes":"No");

}

void loop() {
  
}