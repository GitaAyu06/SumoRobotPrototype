int MKANAN1=5;
int MKANAN2=6;
int MKIRI1=10;
int MKIRI2=11;

void setup() 
{
pinMode (MKANAN1, OUTPUT);
pinMode (MKANAN2, OUTPUT);
pinMode (MKIRI1, OUTPUT);
pinMode (MKIRI2, OUTPUT);
}

void loop() 
{
analogWrite (MKANAN1,225);
analogWrite (MKANAN2,0);
analogWrite (MKIRI1,225);
analogWrite (MKIRI2,0);
delay (300);

analogWrite (MKANAN1,0);
analogWrite (MKANAN2,225);
analogWrite (MKIRI1,0);
analogWrite (MKIRI2,225);
delay (300);
}
