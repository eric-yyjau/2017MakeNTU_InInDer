# 20170224~0225 MakeNTU

## Out product
- Send messages in accidents
	- LinkIt + Gyro sensor
	- Gyro: Sense the car pose
	- LinkIt: Send messages

- Avoid motorcycle accidents
	- Arduino + Sonar sensor + Servo motor
	- Sonar: Sense motorcycles
	- Servo: Temporarily lock the door

- Avoid bumping when turning 
	- Arduino + Infrared sensor + Sonar sensor
	- Infrared & Sonar: Detect people
	- LED: Show notifications

---

- 汽車安全守護者
  - 車門安全裝置
    - 木頭架起車體
    - 超音波測距儀--是否有人接近
    - 有人接近，門會增加阻尼
    - 沒有人接近，門會鬆開，可以自由開啟
    - 步進馬達控制角度
  - Ａ柱防撞裝置
    - Ａ柱視線死角
    - 超音波測距儀、紅外線動作偵測器，偵測人或物是否擋住車體
    - 擋住則給驚嘆號提示
    - LED_matrix (arduino MaxMatrix)
    - LCD_display fail…
  - 翻車通報系統
    - 陀螺儀測定加速度
    - 若車體翻倒（加速度方向設定Threshold)，則緊急處理
      - 上傳GPS位置到MediaTek Cloud Sandbox(MCS)
      - 自動傳訊息給親友與附近醫護單位
      - 車聯網--通知附近車輛
    - Linkit + GPS module + sim card(should use number to ‘char’ ) + wifi
- Also want to try
  - ARM
  - learn linkit
  - Azure

## Codes
- Arduino
	- Include the code for the functions and some testings
- python
	- Include testings of opencv for detection


## Videos and slides

[Video 1](https://youtu.be/ONthKmxY9yQ)

[Video 2](https://youtu.be/0vBwJiEpOKs)

[Slides](https://github.com/eric-yyjau/2017MakeNTU_InInDer/blob/master/ININDER.pdf)

[Press](https://www.slideshare.net/YiLinJuang/makentu) p.13

## References
- [arduino + i2c](https://www.i2cdevlib.com/devices/mpu6050#source)
- [gyro tutorial](http://ming-shian.blogspot.tw/2014/05/arduino21mpu6050row-data.html)
- [Arduino + MPU-6050](http://ming-shian.blogspot.tw/2014/05/arduino21mpu6050row-data.html)
- [led_matrix](https://brainy-bits.com/blogs/tutorials/scroll-text-using-the-max7219-led-dot-matrix)
- [MCS](https://mcs.mediatek.com/)

