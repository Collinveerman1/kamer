int analogPinY = A4; 
int analogPinX = A5;// potentiometer wiper (middle terminal) connected to analog pin 3
                    // outside leads to ground and +5V
int valY = 0;
int valX = 0;  // variable to store the value read
#define LAMPJE_1 11 // 0 - 255 
#define LAMPJE_2 10 // 0 - 255 
void setup() {
  Serial.begin(9600);           //  setup serial
  pinMode(LAMPJE_1, OUTPUT);
  pinMode(LAMPJE_2, OUTPUT);
}

void loop() {
  valY = analogRead(analogPinY) / 4;
  valX = analogRead(analogPinX) / 4; 

  String output = "X-" + String(valX) + " | " + "Y-" + String(valY);
  Serial.println(output);

  analogWrite(LAMPJE_1, valY);
  analogWrite(LAMPJE_2, valX);
  delay(50);
}