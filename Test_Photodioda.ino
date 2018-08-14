int PHOTO= A5;

void setup() 
{
  pinMode(PHOTO,INPUT);
  Serial.begin(9600);
}

void loop() 
{
 int baca=analogRead(PHOTO);
 Serial.println(baca);
 delay (500);
}
