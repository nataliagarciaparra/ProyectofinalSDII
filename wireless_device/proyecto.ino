#include <Wire.h>
#include <stdio.h>
#include <MPU6050.h>
#include <BluetoothSerial.h>
#include <ArduinoJson.h>
BluetoothSerial SerialBT;
MPU6050 mpu;
#define BOTON 13

int flag = 0;

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  Serial.begin(9600);
  mpu.initialize();
  SerialBT.begin("natalia");
  Serial.println("Bluetooth iniciado");
  pinMode(BOTON,INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(BOTON),miISR,FALLING);
}

void loop() {
  // put your main code here, to run repeatedly:
    Serial.print("La aceleracion en X es:");
    Serial.println(px());
    Serial.print("La aceleracion en Y es:");
    Serial.println(py());
    Serial.print("La aceleracion en Z es:");
    Serial.println(pz());
    Serial.print("La posicion en X es:");
    Serial.println(gx());
    Serial.print("La posicion en Y es:");
    Serial.println(gy());
    Serial.print("La posicion en Z es:");
    Serial.println(gz());

    sendData();
    flag=0;
    delay(400); 
}

float px() {
int16_t a, b, a1;
float b1;

Wire.beginTransmission(0x68); 
Wire.write(0x3B);
Wire.endTransmission();
Wire.requestFrom(0x68, 2); 
while(!Wire.available()); 
a= Wire.read();
while(!Wire.available()) ;
b= Wire.read();
a1=(a<<8)|b;
b1=((a1*2.0)/32707.0);

return b1;
}

float py() {
int16_t c, d, c1;
float d1;

Wire.beginTransmission(0x68); 
Wire.write(0x3D);
Wire.endTransmission(); 
Wire.requestFrom(0x68, 2); 
while(!Wire.available()); 
c= Wire.read();
while(!Wire.available()) ;
d= Wire.read();
c1=(c<<8)|d;
d1=((c1*2.0)/32707.0);

return d1;
}

float pz() {
int16_t e, f, e1;
float f1;

Wire.beginTransmission(0x68); 
Wire.write(0x3F);
Wire.endTransmission(); 
Wire.requestFrom(0x68, 2); 
while(!Wire.available()); 
e= Wire.read();
while(!Wire.available()) ;
f= Wire.read();
e1=(e<<8)|f;
f1=((e1*2.0)/32707.0);

return f1;
}

int16_t gx() {
int16_t g,h,g1;
float h1;

Wire.beginTransmission(0x68); 
Wire.write(0x43);
Wire.endTransmission(); 
Wire.requestFrom(0x68, 2); 
while(!Wire.available()); 
g= Wire.read();
while(!Wire.available()) ;
h= Wire.read();
g1=(g<<8)|h;
h1=((g1*250.0)/32707.0);

return h1;
}

int16_t gy() {
int16_t i,j,i1;
float j1;

Wire.beginTransmission(0x68); 
Wire.write(0x45);
Wire.endTransmission(); 
Wire.requestFrom(0x68, 2); 
while(!Wire.available()); 
i= Wire.read();
while(!Wire.available()) ;
j= Wire.read();
i1=(i<<8)|j;
j1=((i1*250.0)/32707.0);

return j1;
}

int16_t gz() {
int16_t k,l,k1;
float l1;

Wire.beginTransmission(0x68); 
Wire.write(0x47);
Wire.endTransmission(); 
Wire.requestFrom(0x68, 2); 
while(!Wire.available()); 
k= Wire.read();
while(!Wire.available()) ;
l= Wire.read();
k1=(k<<8)|l;
l1=((k1*250.0)/32707.0);

return l1;
}

void sendData() {
  StaticJsonDocument<200> jsonDoc;  // Tamaño del documento JSON

  // Agregar datos al objeto JSON
  jsonDoc["posx"]=px();
  jsonDoc["posy"]=py();
  jsonDoc["posz"]=pz();
  jsonDoc["girx"]=gx();
  jsonDoc["giry"]=gy();
  jsonDoc["girz"]=gz();
  jsonDoc["flag"]=flag;

  // Serializar el objeto JSON en una cadena
  String jsonString;
  serializeJson(jsonDoc, jsonString);

  // Enviar la cadena JSON a través de Bluetooth
  SerialBT.println(jsonString);
}



void miISR() {
//transmitir datos al dispositivo
  flag = 1;
}