
#include "DHT.h"
#include <Wire.h> 
#include <LiquidCrystal_I2C.h>

// --- ตั้งค่าอุปกรณ์ ---
#define DHTPIN 4          // กำหนดไว้ที่พิน 4 ตามที่ต้องการ
#define DHTTYPE DHT22     

// จอ LCD Address 0x27
LiquidCrystal_I2C lcd(0x27, 16, 2);

// สร้างตัวอักษรพิเศษรูปวงกลมองศา (Degree Symbol)
byte degreeChar[] = {
  0b00110,
  0b01001,
  0b01001,
  0b00110,
  0b00000,
  0b00000,
  0b00000,
  0b00000
};

void setup() {
  Serial.begin(115200);
  
  lcd.init();
  lcd.backlight();
  
  // สร้างตัวอักษรพิเศษไว้ในหน่วยความจำ LCD
  lcd.createChar(0, degreeChar);
  
  lcd.setCursor(0, 0);
  lcd.print(" SIMULATOR MODE ");
  lcd.setCursor(0, 1);
  lcd.print(" RANDOM SENSING ");
  delay(2000);
  lcd.clear();

  // กำหนด Seed สำหรับการสุ่มให้ค่าเปลี่ยนไปเรื่อยๆ ทุกครั้งที่เปิดเครื่อง
  randomSeed(analogRead(0));
}

void loop() {
  // --- เปลี่ยนจากการอ่านค่าจริง เป็นการสุ่มค่า ---
  // สุ่มอุณหภูมิในช่วง 20.0 ถึง 40.0 องศา
  float t = random(200, 401) / 10.0;
  
  // สุ่มความชื้นในช่วง 40 ถึง 90 เปอร์เซ็นต์
  float h = random(400, 901) / 10.0;

  // --- 1. การส่งข้อมูลสำหรับ SERIAL PLOTTER (เน้นวาดกราฟ) ---
  Serial.print("Temperature_C:");
  Serial.print(t);
  Serial.print(",");
  
  Serial.print("Humidity_RH:");
  Serial.print(h);
  Serial.print(",");
  
  Serial.print("Heat_Alert_Level:");
  Serial.print(35.0); 
  Serial.print(",");
  
  Serial.print("Min_Scale:");
  Serial.print(0);
  Serial.print(",");
  Serial.print("Max_Scale:");
  Serial.println(100);

  // --- 2. การแสดงผลบนจอ LCD ---
  lcd.setCursor(0, 0);
  lcd.print("T: ");
  lcd.print(t, 1);
  lcd.write(0);
  lcd.print("C  ");
  
  lcd.print("H: ");
  lcd.print(h, 0);
  lcd.print("% ");

  lcd.setCursor(0, 1);
  if (t > 35.0) {
    lcd.print("> ALERT: TOO HOT");
  } else {
    lcd.print("> SYSTEM NORMAL ");
  }

  // ปรับ delay เพื่อให้กราฟขยับต่อเนื่อง
  delay(1000); 
}