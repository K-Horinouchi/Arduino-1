//おかしなところがあったら教えてください。
#include <PS3BT.h>
#include <usbhub.h>
#include <Servo.h>
#ifdef dobogusinclude
#include <spi4teensy3.h>
#endif

USB Usb;
BTD Btd(&Usb);
PS3BT PS3(&Btd);
int i=1;

void setup() {
    Serial.begin(115200);
  while (!Serial); // Wait for serial port to connect - used on Leonardo, Teensy and other boards with built-in USB CDC serial connection
  if (Usb.Init() == -1) {
    Serial.println("頑張ってます");
    while (1); //halt
  }
  Serial.println("接続中");
}

void loop() {
  Usb.Task();
  if(PS3.PS3Connected){
    i=1;
    if(PS3.getButtonPress(CIRCLE)){
      Serial.println("○"); 
    }
    if(PS3.getButtonPress(CROSS)){
      Serial.println("☓");
    }
    if(PS3.getButtonPress(TRIANGLE)){
      Serial.println("△");
    }
    if(PS3.getButtonPress(SQUARE)){
      Serial.println("□");
    }
    if(PS3.getButtonPress(UP)){
      Serial.println("↑");
    }
    if(PS3.getButtonPress(DOWN)){
      Serial.println("↓");
    }
    if(PS3.getButtonPress(RIGHT)){
      Serial.println("→");
    }
    if(PS3.getButtonPress(LEFT)){
      Serial.println("←");
    }
    if(PS3.getButtonPress(L1)){
      Serial.println("L1");
    }
    if(PS3.getButtonPress(L2)){
      Serial.println("L2");
    }
    if(PS3.getButtonPress(R1)){
      Serial.println("←");
    }
    if(PS3.getButtonPress(R2)){
      Serial.println("R2");
    }
    // いらないところは消してください
    else{
      
    }
  }
  else{
    if(i==1){
      Serial.println("接続できてません");
      i=0;
    }
  }
}

//#include<math.h>
//dig = atan2(PS3.getAnalogHat(LeftHatY)-127.5,PS3.getAnalogHat(LeftHatX)-127.5) * 180.0 / PI+180;      アナログパッドを倒した角度。　アナログパッドを使ったら変な動きをしたことがあったので入れてません。
