#include <Servo.h> //Servo kütüphanesi

//writed by Fatih mehmet yılmaz
Servo horizontal;
int servoh = 90;

int servohLimitHigh = 180;
int servohLimitLow = 10;

//motor pinleri
#define yukari 10
#define asagi 9
#define sol 8
#define sag 7
#define dikhiz 12
#define yatayhiz 11

int dtime = 200;
  int tol = 150;
int gitmealt =50;
int gitmeust=10;
int servov = 90;

int servovLimitHigh = 175;
int servovLimitLow = 25;
// LDR pin connections
// name = analogpin;

int ldrlt = 2; //LDR sol üst
int ldrrt = 3; //LDR sağ üst
int ldrld = 1; //LDR sol alt
int ldrrd = 0; //LDR sağ alt




void setup()
{
  Serial.begin(9600);
  // servo connections
  // name.attacht(pin);

  pinMode(yukari, OUTPUT);
  pinMode(asagi, OUTPUT);
  pinMode(sol, OUTPUT);
  pinMode(sag, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
pinMode(8, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  /*horizontal.attach(11); // yatay
  vertical.attach(10); // dikey
  horizontal.write(90);
  vertical.write(90);*/
  delay(2000);
}

void loop()
{
 
digitalWrite(11,HIGH);
digitalWrite(12,HIGH);
  int lt = analogRead(ldrlt); // sol üst
  int rt = analogRead(ldrrt); // sağ üst
  int ld = analogRead(ldrld); // sol alt
  int rd = analogRead(ldrrd); // sağ alt

 // int tol = analogRead(0) / 4;
  //int dtime = analogRead(5) / 4;
  int dtime = 10;
  int tol = 20;

  int avt = (lt + rt) / 2; // average value top  ortalama değer üstü
  int avd = (ld + rd) / 2; // average value down  ortalama değer aşağı
  int avl = (lt + ld) / 2; // average value left average value sol
  int avr = (rt + rd) / 2; // average value right average value sag

  int dvert = avt - avd; // check the diffirence of up and down  yukarı ve aşağı arasındaki farkı kontrol et

  int dhoriz = avl - avr;// check the diffirence og left and rigt  solun ve sagın arasındaki farkı kontrol et

int ldrlt = 3; //LDR sol alt
int ldrld = 4; //LDR sol üst 

int ldrrt = 2; //LDR sağ üst
int ldrrd = 1; //LDR sağ alt

  Serial.print("sol ust= "); Serial.print(lt);
  Serial.print(" ");
  Serial.print("sag ust= "); Serial.print(rt);
  Serial.print(" ");
  Serial.print("sol alt= "); Serial.print(ld);
  Serial.print(" ");
  Serial.print("sag alt= "); Serial.println(rd);  Serial.print(" ");
  Serial.print("time= "); Serial.print(dtime);
  Serial.print(" ");
  Serial.print("has.= "); Serial.print(tol);
  Serial.println(" ");

  if (-1 * tol > dvert || dvert > tol)
  {
    if (avt > avd)
    {
       Serial.println("yukari");
    digitalWrite(yukari, LOW);
    digitalWrite(asagi, HIGH);
    digitalWrite(sol, LOW);
    digitalWrite(sag, LOW);
    delay(gitmeust);
      
    }
    else if (avt < avd)
    {
      Serial.println("asagi");
    digitalWrite(yukari,HIGH);
    digitalWrite(asagi, LOW);
    digitalWrite(sol, LOW);
    digitalWrite(sag, LOW);
      delay(gitmeust);
    }

  }





  if (-1 * tol > dhoriz || dhoriz > tol)
  {
    if (avl > avr)
    {
     
       Serial.println("saga");
    digitalWrite(yukari, LOW);
    digitalWrite(asagi, LOW);
    digitalWrite(sol, LOW);
    digitalWrite(sag, HIGH);
       delay(20);
    }
    else if (avl < avr) {
      
       Serial.println("sola");
    digitalWrite(yukari, LOW);
    digitalWrite(asagi, LOW);
    digitalWrite(sol, HIGH);
    digitalWrite(sag, LOW);
       delay(gitmealt);
      
      
    }
    else if (avl = avr)
    {
      // nothing
    }
    
  }
    digitalWrite(yukari, LOW);
    digitalWrite(asagi, LOW);
    digitalWrite(sol, LOW);
    digitalWrite(sag, LOW);
    delay(10);
}
