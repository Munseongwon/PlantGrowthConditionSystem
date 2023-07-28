# PlantGrowthConditionSystem
### 아두이노 모듈을 활용한 미니 식물 성장 조건 감지 시스템
<img src='식물성장조건감지시스템(윗면도).png' alt='mainScreen' width="1280px" height="500px"/>

## 프로젝트 요약
> 2인 팀 프로젝트
> 2021.11.16 - 2021.12.7   
 
> **자라나라 나무나무 조 프로젝트(2인)**
* 버튼 모듈을 이용하여 누른 상태에서는 성장감지시스템 작동 뗀 상태에서는 시스템 종료 구현
* 조도센서와 토양수분감지센서를 통해 빛의 양, 수분의 양 체크하도록 구현
* dht11 센서(온습도 센서)를 통해 온,습도 정도를 시리얼 모니터로 출력할 수 있도록 구현
* 식물의 현재 성장 상태를 3색 LED 불빛, LCD 문자 출력을 통해 감지 
<br>

## 프로젝트 로직
<img src='smarthome logic.png' alt='mainScreen' height="500px"/>

## 담당 역할
### 무드등 제어
![Langauge:C++](https://img.shields.io/badge/Language-C++-red) ![platform:Arduino](https://img.shields.io/badge/Platform-Arduino-red)
* 3색 LED 모듈과 turnOnOffLights 메서드를 사용하여 외출 시 혹은 외출 하지 않을 시의 기능 구현
* 블루투스 모듈(hm10)과 앱을 연동하여 문자(무드등: a,b)입력에 따른 무드등 제어 구현
### 스마트 주차장
![Langauge:C++](https://img.shields.io/badge/Language-C++-red) ![platform:Arduino](https://img.shields.io/badge/Platform-Arduino-red)
* 서보모터 및 초음파 센서, LCD를 활용하여 감지거리에 따른 주차장 개폐
* LCD를 통해 현재 차의 출입 여부 확인
* 서보 모터에 5초간의 딜레이와 10도씩 증가를 통한 사물의 유무 확인
### 식물 성장 감지 시스템
![Langauge:C++](https://img.shields.io/badge/Language-C++-red) ![platform:Arduino](https://img.shields.io/badge/Platform-Arduino-red)
* 3색 led를 통해 식물의 성장 조건에 입각한 수분 및 습도 확인

## 결과 영상
