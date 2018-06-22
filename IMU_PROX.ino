/*
 # Product: 6 DOF Sensor-MPU6050 
 # SKU    : SEN0142 
 # Description:     
 # To read  accel/gyro data from 6 DOF Sensor 
*/

#include "Wire.h"                 
#include "I2Cdev.h"
#include "MPU6050.h"
#include "Adafruit_VCNL4010.h"

#define LED_PIN 13

Adafruit_VCNL4010 vcnl;
MPU6050 accelgyro;  

int16_t ax, ay, az;  // define accel as ax,ay,az
int16_t gx, gy, gz;  // define gyro as gx,gy,gz
bool blinkState = false;

void setup() {
  Wire.begin();          // join I2C bus   
  Serial.begin(9600);    //  initialize serial communication
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();  

  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");
  
  if (! vcnl.begin()){
    Serial.println("Sensor not found :(");
    while (1);
  }
  Serial.println("Found VCNL4010");
  pinMode(LED_PIN, OUTPUT);  // configure LED pin
}

void loop() {
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);  // read measurements from device

  // display tab-separated accel/gyro x/y/z values
  Serial.print("a/g:         ");
  Serial.print(ax); 
  Serial.print("         ");
  Serial.print(ay); 
  Serial.print("         ");
  Serial.print(az); 
  Serial.print("         ");
  Serial.print(gx); 
  Serial.print("         ");
  Serial.print(gy); 
  Serial.print("         ");
  Serial.println(gz);

  Serial.print("Ambient: "); Serial.println(vcnl.readAmbient());
  Serial.print("Proximity: "); Serial.println(vcnl.readProximity());
  // blink LED to indicate activity
  blinkState = !blinkState;
  digitalWrite(LED_PIN, blinkState);
}
