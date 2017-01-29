#include <SoftwareSerial.h>

SoftwareSerial data(10, 11); // RX, TX
float gas_sensor,suhu,suhu_sensor;
String isi = "";
String gas="Gas aman";
char terima;

int jumlah =0;
int sensor;

void setup() {
  data.begin (115200);
  Serial.begin(115200);
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A1,INPUT);
  pinMode(A2,INPUT);

  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, HIGH);
  digitalWrite(6, HIGH);

  gas_sensor = analogRead(A0);
  suhu_sensor = analogRead(A1);
}

void loop() {

  while (Serial.available() > 0)
  {
    terima = Serial.read();
    isi += terima;

    //r1
    if (isi == "on0")
    {
      digitalWrite(2, LOW);
      isi = "";
    }

    if (isi == "off0")
    {
      digitalWrite(2, HIGH);
      isi = "";
    }

    //r2
    if (isi == "on1")
    {
      digitalWrite(3, LOW);
      isi = "";
    }

    if (isi == "off1")
    {
      digitalWrite(3, HIGH);
      isi = "";
    }

    //r3
    if (isi == "on2")
    {
      digitalWrite(4,LOW);
      isi = "";
    }

    if (isi == "off2")
    {
      digitalWrite(4,HIGH);
      isi = "";
    }
    
    //r4
    if (isi == "on3")
    {
      digitalWrite(5, LOW);
       isi = "";
      
    }

    if (isi == "off3")
    {
      digitalWrite(5, HIGH);
      isi = "";
    }

    //r5

    if (isi == "on4")
    {
      digitalWrite(6, LOW);
       isi = "";
      
    }

    if (isi == "off4")
    {
      digitalWrite(6, HIGH);
      isi = "";
    }

    
  }
gas_sensor = analogRead(A0);
suhu_sensor = analogRead(A1);

if (gas_sensor > 200)
{
//Serial.print("Gas bocor");  
gas = "Gas bocor";
}
else if (gas_sensor < 150)
{
  //Serial.print("Gas aman");
  gas = "Gas aman";
}

//telur
sensor = analogRead(A2);
if (sensor >= 0 && sensor < 650)
{
  jumlah = 0;
}

if (sensor >= 651 && sensor < 798)
{
  jumlah = 1;
}
if (sensor >= 800 && sensor < 850)
{
  jumlah = 2;
}
if (sensor >= 852 && sensor < 895)
{
  jumlah = 3;
}
if (sensor >= 897 && sensor < 915)
{
  jumlah = 4;
}
if (sensor >= 918 && sensor < 934)
{
  jumlah = 5;
}
if (sensor >= 935 && sensor < 945)
{
  jumlah = 6;
}
if (sensor >= 947 && sensor < 955)
{
  jumlah = 7;
}
if (sensor >= 956 && sensor < 962)
{
  jumlah = 8;
}
if (sensor >= 963 && sensor < 968)
{
  jumlah = 9;
}
if (sensor >= 968 )
{
  jumlah = 10;
}


suhu = suhu_sensor*0.488;
Serial.print(gas+"-"+suhu+"-"+jumlah+"-");
delay(100);
//gas = "";
  //isi = "";
  //delay(100);

  /*
    Serial.print("ini data pertama");
    delay(500);
    Serial.print("ini data ke dua");
    delay(500);
  */
}

