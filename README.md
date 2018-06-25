# IMU_PROXIMITY
Arduino sketch for IMU (MPU6050) and proximity sensors (VCNL4010)

## Requirements
### Hardware:
* Arduino nano
* MPU6050 IMU Sensor(6 Dof)
* Adafruit VCNL4010 IR Proximity & Temperature Sensor
### Software:
* Arduino IDE
* [Arduino VCNL4010 Library](https://github.com/adafruit/Adafruit_VCNL4010)
* [MPU6050 Library](https://maker.pro/files/MPU6050.zip)
## Wiring Guide
![alt-text](https://github.com/EE3-DTPRJ-Robot-Intelligence/IMU_PROXIMITY/blob/master/IMU_PROX_WIRING.jpg?raw=true)

## About
This program runs both sensors sharing the same I2C bus. OUtput is a sting containing acceleration, gyro, proximity and temperature.
