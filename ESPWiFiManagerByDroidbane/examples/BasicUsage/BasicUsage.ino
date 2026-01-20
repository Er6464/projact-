/**
 * Örnek Kullanım: ESPWiFiManagerByDroidbane Kütüphanesi
 * 
 * Bu örnek, ESP8266 cihazınızın Wi-Fi bağlantısını otomatik olarak
 * yönetmek veya bir erişim noktası (AP) modunda kurulum yapabilmek
 * için ESPWiFiManagerByDroidbane kütüphanesini göstermektedir.
 * 
 * Özellikler:
 *  - Kaydedilmiş Wi-Fi bilgileri varsa otomatik bağlanır.
 *  - Bağlanamazsa belirtilen AP SSID ile AP modunu başlatır.
 *  - HTTP server üzerinden Wi-Fi ve sistem yönetimi yapılabilir.
 *
 * HTTP Endpointler:
 *  1. POST http://<ESP_IP>/wifi
 *     - Parametreler: ssid, password
 *     - Açıklama: Yeni Wi-Fi bilgilerini kaydeder ve cihazı yeniden başlatır.
 *
 *  2. POST http://<ESP_IP>/wifi-update
 *     - Parametreler: yok
 *     - Açıklama: Kayıtlı Wi-Fi bilgilerini siler ve cihazı yeniden başlatır.
 *
 *  3. POST http://<ESP_IP>/restart
 *     - Parametreler: yok
 *     - Açıklama: Cihazı yeniden başlatır.
 *
 *  4. POST http://<ESP_IP>/message
 *     - Parametreler: message
 *     - Açıklama: Kullanıcı tarafından tanımlanan callback fonksiyonuna
 *       gelen mesajı iletir (log, MQTT, vs.).
 *
 * Kullanım:
 *  1. onMessage() ile mesaj callback fonksiyonunu tanımlayın.
 *  2. begin() ile Wi-Fi ve HTTP server başlatın.
 *  3. getIP() ile cihazın IP adresini alın (Wi-Fi veya AP moduna göre).
 *  4. loop() içinde server.handleClient() çağrısını yapın.
 *
 * Not: Bu örnek ESP8266 içindir. ESP32 için uyarlama gerekebilir.
 */
#include <ESPWiFiManagerByDroidbane.h>

// Wi-Fi name in setup mode.
ESPWiFiManagerByDroidbane ESPWiFiManagerByDroidbane("ESP_Setup");

void setup() {
    Serial.begin(115200);

    ESPWiFiManagerByDroidbane.onMessage([](const String& msg) {
        Serial.println("Kütüphaneden gelen mesaj: " + msg);
        // code... (ex: reading, log, etc.)
    });


    // Automatic Wi-Fi connection or setup mode start.
    ESPWiFiManagerByDroidbane.begin();

    // Print the device IP address.
    Serial.print("Device IP: ");
    Serial.println(ESPWiFiManagerByDroidbane.getIP());
}

void loop() {
    // Listen for HTTP requests.
    wifiManaESPWiFiManagerByDroidbaneger.loop();
}
