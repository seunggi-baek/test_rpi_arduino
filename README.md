# test_rpi_arduino
## 참조 링크
https://www.youtube.com/watch?v=jU_b8WBTUew&t=2674s
영어로 되어 있어서 보기 힘들다면 크롬 확장프로그램 (Video CC Translator) 설치해서 보면 어느정도 번역이 되기 때문에 추천함

## Step1. Arduino IDE Install
sudo apt install arduino

uname -m 을 통한 os 종류 확인
armv7l or x86_64 뭐가 됐든 apt 를 통해 설치하는게 가장 좋음

## Step2. Serial Communication
UART 통신 
라즈베리 (Python -> pyserial)
아두이노 (C++ -> Serial)

## Step3. RPi Software Setup
sudo apt install python3-pip
pip3 install pyserial
(라즈비안에 이미 설치되어 있었음)

## Step4. Initiate Serial Communication
python : first_communication.py
arduino : first_communication.ino

## Step5. Send data from Arduino to Raspberry Pi
## Step6. Send data from Raspberry Pi to Arduino
python : first2.py
arduino : first2.ino

## Step7. Create a bidirectional communication
python : first3.py
arduino : first3.ino

## ADD Sample (Pin을 이용한 UART 통신 - 2채널 단방향 레벨변환컨버터 이용)
arduino : serial-arduino-uart.ino
라즈베리파이 : vcc(2), gnd(6), tx(8), rx(10)
아두이노 : vcc(5v), gnd(gnd), tx(3), rx(2)
2채널 단방향 레벨변환 컨버터 
 - 라즈베리파이 : vcc(chan2-TXI), gnd(LV-GND), tx(chan1-TXI), rx(chan1-RXO)
 - 아두이노 : vcc(chan2-TXO), gnd(HV-GND), tx(chan1-RXI), rx(chan1-TXO)
 

