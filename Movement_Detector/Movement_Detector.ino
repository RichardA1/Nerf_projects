int PIRPin = 0;
int RFarmPin = 1;
int RFfirePin = 2;
int LEDarmedPin = 3;
int LEDfirePin = 4;
int RELAYfirePin = 5;
int ARMED = 0; //Set to Un-Armed
 
void setup()
{
  pinMode(PIRPin, INPUT);
  pinMode(RFarmPin, INPUT);
  pinMode(RFfirePin, INPUT);
  pinMode(LEDarmedPin, OUTPUT);
  pinMode(LEDfirePin, OUTPUT);
  pinMode(RELAYfirePin, OUTPUT);
  digitalWrite(RELAYfirePin,LOW);
  digitalWrite(LEDfirePin,HIGH);
  digitalWrite(LEDarmedPin,HIGH);
}
 
void loop()
{
  if (digitalRead(RFarmPin) == HIGH) //Was the Arm button pressed?
  {
    switch (ARMED) {
    case 0: //Is Un-Armed
      //If Un-Armed, set ARMED to 1 when Arm button is pressed
      ARMED = 1; //Set to Armed
      digitalWrite(LEDfirePin,LOW);
      digitalWrite(LEDarmedPin,LOW);
      delay(3000);                  // waits for 3 seconds
      break;
    case 1: //Is Armed
      //If Armed, set ARMED to 0 when Arm button is pressed
      ARMED = 0; //Set to Un-Armed
      digitalWrite(LEDfirePin,HIGH);
      digitalWrite(LEDarmedPin,HIGH);
      delay(3000);                  // waits for 3 seconds
      break;
    //default: 
    }
  }
  if (ARMED == 1)
  {
    //Power on motion detection
    if (digitalRead(PIRPin) == HIGH)
    {
      //Motion detected, FIRE
      digitalWrite(RELAYfirePin,HIGH);
      digitalWrite(LEDfirePin,LOW);
      digitalWrite(LEDarmedPin,HIGH);
    }
    else
    {
      //No Motion detected
      digitalWrite(RELAYfirePin,LOW);
      digitalWrite(LEDfirePin,HIGH);
      digitalWrite(LEDarmedPin,LOW);
    }
  }
  if (digitalRead(RFfirePin) == HIGH) //Was the Fire button pressed?
  {
    //Remote Fire is pressed.
    digitalWrite(RELAYfirePin,HIGH);
    digitalWrite(LEDfirePin,LOW);
    digitalWrite(LEDarmedPin,LOW);
  }
  else
  {
    //Remote Fire not pressed.
    digitalWrite(RELAYfirePin,LOW);
    digitalWrite(LEDfirePin,HIGH);
    digitalWrite(LEDarmedPin,HIGH);
  }
}
