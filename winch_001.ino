//winch mechanism control
//35 kgcm servo with fs-iA10B rx with FS-i6 Arduino nano
#include <Servo.h> 
Servo btn_srv;

const int btn_srv_pin = 9;
const int ch6_pin = 10;
const int ch6_min = 1000;
const int ch6_max = 2000;
const int ch6_mid = 1500;
const int ch6_diff = 200;

const int extention_us   = 2200;
const int contraction_us = 800;
const int neutral_us     = 1500;
const int dt = 500; //500ms delay
const int dt2 = 10000;


int ch6_val;

void setup() {
  pinMode(ch6_pin,INPUT);
  btn_srv.attach(btn_srv_pin);
  btn_srv.writeMicroseconds(neutral_us);
  delay(dt2);
}

void loop() {
   ch6_val = pulseIn(ch6_pin,HIGH);
   if(ch6_val >= (ch6_min - ch6_diff) && ch6_val <= (ch6_min + ch6_diff))
   {
    btn_srv.writeMicroseconds(contraction_us);
   }
   else if(ch6_val >= (ch6_max - ch6_diff) && ch6_val <= (ch6_max + ch6_diff))
   {
    btn_srv.writeMicroseconds(extention_us);
   }
   else
   {
    btn_srv.writeMicroseconds(neutral_us);
   }

   delay(dt);

}
