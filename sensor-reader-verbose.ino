const int groveLightPin = A0;
const int grovePotPin = A1;
const int groveButtonPin = 1;
const int slidePotPin = A2;

int groveButtonState = 0;
int groveLightVal = 0;
int grovePotVal = 0;
int slidePotVal = 0;

void setup() {
  // initialize digital pins:
  pinMode(groveButtonPin, OUTPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // read digital pins:
  groveButtonState = digitalRead(groveButtonPin);
  
  // read the input on analog pins:
  groveLightVal = analogRead(A0);
  grovePotVal = analogRead(A1);
  slidePotVal = analogRead(A2);

  groveLightVal = map(groveLightVal, 0, 1023, 0, 255);
  grovePotVal = map(grovePotVal, 0, 1023, 0, 255);
  slidePotVal = map(slidePotVal, 0, 1023, 0, 255);
  
  // print out the value you read:
  Serial.println(String("grove light: ") + String(groveLightVal));
  Serial.println(String("grove pot: ") + String(grovePotVal));
  Serial.println(String("slide pot: ") + String(slidePotVal));
  Serial.println();
  
  delay(2000);        // delay in between reads for stability
}
