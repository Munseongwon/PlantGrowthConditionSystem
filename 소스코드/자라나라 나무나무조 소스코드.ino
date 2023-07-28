#include <Adafruit_Sensor.h>
#include <DHT.h>
#include <DHT_U.h>

#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include "DHT.h"

#define DHTPIN 8
#define DHTTYPE DHT11

DHT dht(DHTPIN, DHTTYPE);

LiquidCrystal_I2C lcd(0x27, 16, 2); //lcd1602A 설정

#define red 5 // red led 5번핀 설정
#define green 6 // green led 6번핀 설정
#define blue 7 // blue led 7번핀 설정

const int buttonPin = 4; //button1 4번핀에 설정하고 변하지 않는 상수로 선언(on--> 식물 생장 측정 시작)

int buttonState = 0; // button의 상태값을 초기화

void setup() {

  lcd.init();  //lcd 초기화
  lcd.backlight(); // lcd 배경 불 켜기
  lcd.print("Sensor Start!"); // lcd 맨 윗부분 좌표(0,0)에 Moisture Sensor 글자 출력
  Serial.begin(9600);

  dht.begin(); //dht11센서 작동
  pinMode(red, OUTPUT);
  pinMode(green, OUTPUT);
  pinMode(blue, OUTPUT);
  pinMode(buttonPin, INPUT_PULLUP);
}

//물,빛의 양 적정하거나 온도와 습도 역시 적정할 때, green_led 켜짐(1초간 깜빡거림 설정)
void Enough() {
  lcd.clear();
  lcd.backlight();
  lcd.display();
  lcd.setCursor(0, 0);
  lcd.print("Enough");
  delay(1000);
  digitalWrite(green, HIGH);
  delay(1000);
  digitalWrite(green, LOW);
  delay(1000);
}


//물의 양 또는 빛의 양이 너무 많고, 온도와 습도가 너무 높을 때, blue_led 켜짐(1초간 깜빡거림 설정)
void High() {
  lcd.clear();
  lcd.backlight();
  lcd.display();
  lcd.setCursor(0, 0);
  lcd.print("Many");
  delay(1000);
  digitalWrite(blue, HIGH);
  delay(1000);
  digitalWrite(blue, LOW);
  delay(1000);
}


// 물의 양 또는 빛의 양이 너무 적거나, 온도와 습도가 너무 낮을 때, red_led 켜짐(1초간 깜빡거림 설정)
void Low() {
  lcd.clear();
  lcd.backlight();
  lcd.display();
  lcd.setCursor(0, 0);
  lcd.print("Little");
  delay(1000);
  digitalWrite(red, HIGH);
  delay(1000);
  digitalWrite(red, LOW);
  delay(1000);
}

//button 2번이 눌린다면 화면 종료, led 역시 빛나지 않는다.
 void finish() {
  lcd.clear();
  lcd.noBacklight();
  lcd.noDisplay();
  digitalWrite(red, LOW);
  digitalWrite(green, LOW);
  digitalWrite(blue, LOW);
}

void loop() {
  int water = analogRead(A1);  // 수분의 양 변수값을 a1핀을 통해 읽어들인다(0~1023)
  int light = analogRead(A2);  // 조도의 양에 대한 변수값을 a2핀을 통해 읽어들인다(0~1023)
  int h = dht.readHumidity();  //습도 값을 dht11센서로부터 h변수에 저장
  int t = dht.readTemperature(); //온도 값을 dht11센서로부터 t변수에 저장
  buttonState = digitalRead(buttonPin);
  /*buttonState1 = 0*/
  //물의 양이 적정하거나, 조도의 양 적절,온도 적절,습도 적절
  if(buttonState == LOW){
    if ( (t >= 21 && t < 30) && (h >= 20 && h < 40) && (water >= 200 && water <= 499) && (light >= 400 && light <= 900)) {
      Serial.println(water);
      Serial.println(light);
      Serial.println(h);
      Serial.println(t);
      Enough();
    }

    // 물의 양이 너무 많거나, 빛의 양이 너무 많거나 온도가 높거나, 습도가 너무 높을 때 --> 모두 높다고 표시
     else if ((t >= 30) || (h >= 41) || (water >= 500 && water <= 999) && (light > 900)) {
      Serial.println(water);
      Serial.println(light);
      Serial.println(h);
      Serial.println(t);
      High();
    }

    // 물의 양이 적거나, 빛의 양이 너무 적거나 온도가 낮거나, 습도가 너무 낮을 때
    else if ((t < 21) || (h < 20) || (water < 200) && (light < 400)) {
      Serial.println(water);
      Serial.println(light);
      Serial.println(h);
      Serial.println(t);
      Low();
    }
  }
  //button이 떼진 상태이면 동작을 멈춘다.
  else{
    finish();
  }
 }
