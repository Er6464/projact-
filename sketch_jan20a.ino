#include <Bonezegei_DHT11.h>

// สำหรับ Arduino UNO เราจะใช้ขา Digital Pin 2
#define DHTPIN 2 

Bonezegei_DHT11 dht(DHTPIN);

void setup() {
  // สำหรับ UNO แนะนำใช้ Baud rate 9600 หรือ 115200 ก็ได้
  // ในที่นี้เลือก 9600 เพื่อความเสถียรมาตรฐานของ UNO
  Serial.begin(9600);
  dht.begin();
  
  // หัวข้อกราฟสำหรับ Serial Plotter (แสดงที่มุมบน)
  Serial.println("Humidity(%) Temperature(C)");
}

void loop() {
  // คำสั่งอ่านข้อมูลจากเซนเซอร์
  dht.getData();

  // ดึงค่าอุณหภูมิและความชื้นออกมา
  int temp = dht.getTemperature();
  int hum = dht.getHumidity();

  // ตรวจสอบค่าที่อ่านได้ (ถ้าสายหลุดหรือเซนเซอร์เสียมักจะได้ค่า 0)
  // พิมพ์ค่าออกทาง Serial โดยคั่นด้วยช่องว่าง เพื่อให้ Plotter แยกเส้นกราฟ
  Serial.print(hum);   // เส้นกราฟที่ 1
  Serial.print(" ");   // เว้นวรรค
  Serial.println(temp); // เส้นกราฟที่ 2 และขึ้นบรรทัดใหม่

  // DHT11 ต้องการเวลาพักระหว่างการอ่านค่าอย่างน้อย 2 วินาที
  delay(2000); 
}