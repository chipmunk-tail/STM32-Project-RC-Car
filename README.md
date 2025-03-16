# 자율주행 RC CAR


<img src="src_img/20250219_22525602.jpg" alt="smart_stick" width="500">

<br/>

## 개요
STM32와 블루투스를 이용해 원격으로 조작하는 RC카 제작 개인 프로젝트

<br/>

## 목적


**1차 프로젝트 - RC CAR + 스마트폰**

- 스마트폰 어플과 블루투스를 이용하여 RC카 원격 제어

<br/>

**2차 프로젝트 - RC CAR + 조이스틱 컨트롤러**

- HC-06를 이용하여 RC카 원격 제어
- 2개의 모듈로 마스터 - 슬레이브간 통신

<br/>

## 프로젝트 내용

### 1차 프로젝트 - RC CAR + 스마트폰

- STM32
  - RC카 본체용 : STM32F411RET6
  - 컨트롤러 용 : 스마트폰 어플

스마트폰 어플에서 블루투스 시리얼을 이용해 특정 '문자'를 보내면, STM32에서 수신 후 문자에 따라 작동하는 무선 조종 기능 구현

<img src="src_img/tracktracerRC_controllerv01_1.drawio.png" alt="smart_stick" width="500">



<br/>

### 2차 프로젝트 - RC CAR + 조이스틱 컨트롤러

- STM32
  - RC카 본체용 : STM32F411RET6
  - 컨트롤러 용 : SMT32F103C8T6 + 조이스틱 모듈

기존 스마트폰 사용시 PWM을 이용한 모터 속도 제어가 힘들기 때문에, 

조이스틱값의 아날로그 신호를 읽어서 1 ~ 4단계로 나눈 후 STM32에 송신, 속도 조절이 가능한 무선 조종 기능 구현



<br/>

## 고찰 및 문제점

### 1. DMA값 갱신 문제


<img src="src_img/tracktracerRC_controllerv01_2.drawio.png" alt="smart_stick" width="500">


조이스틱의 아날로그 신호를 MCU가 직접 읽지 않고 DMA를 이용해서 값을 메모리에 갱신하는 방법을 사용했는데, UART로 송신하는 루프로 가기 전 다시 DMA가 갱신되서 UART 통신 전 무한루프에 빠지는 문제가 발생하였다.

- 해결방안으론 센서 값을 받으면 DMA를 비활성화 => URAT 송신 후 다시 활성화 하는 방식으로 해결

이 해결방법은 임시방편으로 원래는 DMA값을 갱신하는 사이클을 맞춰야 하는데 해당 


