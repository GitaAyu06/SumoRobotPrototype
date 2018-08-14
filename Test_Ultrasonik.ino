int TRIG=4;
int ECHO=7;
int duration;
int distance;

void setup() 
{
 pinMode (TRIG, OUTPUT);
 pinMode (ECHO, INPUT);
 Serial.begin(9600);
}

void loop() 
{
digitalWrite (TRIG, LOW);
delay (5);
digitalWrite (TRIG, HIGH);
delay (10);
digitalWrite (TRIG, LOW);

duration=pulseIn(ECHO, HIGH);
distance=duration*0.034/2;

Serial.print("Jarak:");
Serial.println(distance);
}
