![Arduino](https://img.shields.io/badge/Arduino-C++-blue)
![Platform](https://img.shields.io/badge/Platform-Embedded-orange)
![Status](https://img.shields.io/badge/Status-Student_Project-success)



# 🌫️ Dust & Humidity Monitoring Project

โปรเจกต์นี้เป็น **เครื่องตรวจจับฝุ่นละออง (PM2.5) และความชื้นในอากาศ**  
พัฒนาเพื่อใช้ตรวจสอบคุณภาพอากาศในพื้นที่ใกล้ตัว เช่น ห้องเรียน บ้าน หรือหอพัก  
เหมาะสำหรับนักเรียนและผู้ที่สนใจด้านอิเล็กทรอนิกส์และ IoT

---

## 🎯 Objective
- ตรวจวัดค่าฝุ่น PM2.5 และความชื้นในอากาศแบบ **เรียลไทม์**
- แสดงผลข้อมูลให้ผู้ใช้งานเข้าใจง่าย
- เพิ่มการรับรู้เกี่ยวกับคุณภาพอากาศและผลกระทบต่อสุขภาพ

---

## ⚠️ Pain Point
- **ฝุ่นและความชื้นไม่สามารถมองเห็นได้ด้วยตาเปล่า**
- ข้อมูลจากแอปทั่วไป ==ไม่ตรงกับพื้นที่จริง==
- อุปกรณ์ตรวจวัดคุณภาพอากาศส่วนใหญ่ ==มีราคาสูง==
- ผู้ใช้งานไม่รู้ว่า ==ควรป้องกันตัวเองเมื่อใด==

---

## 🛠️ Tools & Components
- Microcontroller ESP8266 
- Dust Sensor (PM2.5)
- Humidity Sensor  DHT11 
- Power Supply

---

## 📊 Features
- แสดงค่าฝุ่น PM2.5 แบบเรียลไทม์
- แสดงค่าความชื้นในอากาศ
- แจ้งเตือนเมื่อค่าฝุ่นหรือความชื้นเกินค่าที่กำหนด
- เหมาะสำหรับใช้งานภายในอาคาร

---

## 🧠 Benefits
- ช่วยให้ผู้ใช้งาน ตัดสินใจดูแลสุขภาพได้ดีขึ้น
- เพิ่มความตระหนักเรื่องคุณภาพอากาศ
- เป็นพื้นฐานในการต่อยอดสู่ระบบ IoT หรือ Smart Home

---

## 🚀 Future Development
- เชื่อมต่อแอปหรือเว็บแสดงผล
- บันทึกข้อมูลย้อนหลัง (Data Logging)
- เพิ่มการแจ้งเตือนผ่าน Line / Notification
- เพิ่มเซนเซอร์วัดอุณหภูมิหรือก๊าซอื่น ๆ


---

## Sketch

<img src="https://github.com/user-attachments/assets/9360a2cb-fc3b-493a-9cf1-c686b1d91319"
     width="600"
     alt="Project Screenshot" />



---

## การต่อวงจอน


<img width="450" height="443" alt="Screenshot 2026-01-20 225930" src="https://github.com/user-attachments/assets/3c16dbe2-4bba-4014-b382-0ad6c2a05bb5" />

> [Wokwi](https://wokwi.com/projects/453679490226097153)



VCC  -> 3.3V

GND  -> GND

SDA  -> D4


---

## 🔏that cannot be done

<img src="https://github.com/user-attachments/assets/0fb990db-f247-4b04-8bb4-13370c286249" width="600">  <img src="https://github.com/user-attachments/assets/7f33e10c-d822-4f56-a7ee-465f01dba902" width="600">

 บอร์ดพังเเละ library ของผู้ผลิตไม่มีให้ Downloads เเล้ว



```com
https://wokwi.com/projects/453679490226097153
