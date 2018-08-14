int KANAN1=11;
int KANAN2=10;
int KIRI1=9;
int KIRI2=6;
int TRIG=3;
int ECHOR=8;
int ECHOL=7;
int POWER=2; 
int durationR;
int durationL; 
int distanceR;
int distanceL;
  
void setup()
{
  pinMode(KANAN1,OUTPUT);
  pinMode(KANAN2,OUTPUT);
  pinMode(KIRI1,OUTPUT);
  pinMode(KIRI2,OUTPUT);
  pinMode(TRIG,OUTPUT);
  pinMode(ECHOR,INPUT);
  pinMode(ECHOL,INPUT);
  pinMode(POWER,OUTPUT);
  Serial.begin (9600);
}
  
void loop()
{             
  digitalWrite (POWER,HIGH);
  analogWrite (KANAN1,125);   //gerakan awal robot belok ke kanan belakang
  analogWrite (KANAN2,0);
  analogWrite (KIRI1,0);
  analogWrite (KIRI2,255);
  
digitalWrite (TRIG, LOW);   //sensor ultrasonik nyala
delay (2);
digitalWrite (TRIG, HIGH);
delay (10);
digitalWrite (TRIG, LOW);

durationR=pulseIn(ECHOR, HIGH);
distanceR=durationR*0.034/2;
Serial.print("Jarak Kanan:");
Serial.println(distanceR);

durationL=pulseIn(ECHOL, HIGH);
distanceL=durationL*0.034/2;
Serial.print("Jarak Kiri:");
Serial.println(distanceL);


  if (distanceR>140 && distanceL>140)     //enemy undetected, boundary undetected
  {
  analogWrite (KANAN1,0);   //robot berputar ke kanan
  analogWrite (KANAN2,100);
  analogWrite (KIRI1,200);
  analogWrite (KIRI2,0);
  }
  else if (distanceR<140 && distanceL>140) //enemy detected at RIGHT, boundary undetected
  {
  analogWrite (KANAN1,0);   //robot berbelok ke kanan
  analogWrite (KANAN2,125);
  analogWrite (KIRI1,255);
  analogWrite (KIRI2,0);
  }
  else if (distanceR<140 && distanceL<140) //enemy detected, boundary undetected
  {
  analogWrite (KANAN1,255);   //robot maju ke depan
  analogWrite (KANAN2,0);
  analogWrite (KIRI1,255);
  analogWrite (KIRI2,0);
  }
  else if (distanceR>140 && distanceL<140)//enemy detected at LEFT, boundary undetected
  {
  analogWrite (KANAN1,255);   //robot berputar ke kiri
  analogWrite (KANAN2,0);
  analogWrite (KIRI1,0);
  analogWrite (KIRI2,125);
  }
  delay (30);
}   
