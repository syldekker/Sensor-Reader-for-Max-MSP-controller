// assign variable to each pin
const int groveLightPin = A0;
const int grovePotPin = A1;
const int slidePotPin = A2;

const int button2Pin = 2;
const int button3Pin = 3;
const int button4Pin = 4;
const int button5Pin = 5;
const int button6Pin = 6;
const int button7Pin = 7;
const int button8Pin = 8;
const int button9Pin = 9;

// assign initial values
int groveLightVal = 0;
int grovePotVal = 0;
int slidePotVal = 0;

int button2State = 0;
int button3State = 0;
int button4State = 0;
int button5State = 0;
int button6State = 0;
int button7State = 0;
int button8State = 0;
int button9State = 0;

void setup() {
  // initialize digital pins:
  pinMode(button2Pin, INPUT);
  pinMode(button3Pin, INPUT);
  pinMode(button4Pin, INPUT);
  pinMode(button5Pin, INPUT);
  pinMode(button6Pin, INPUT);
  pinMode(button7Pin, INPUT);
  pinMode(button8Pin, INPUT);
  pinMode(button9Pin, INPUT);

  // initialize serial communication at 9600 bits per second:
  Serial.begin(9600);
}

void loop() {
  // read digital pins:
  button2State = digitalRead(button2Pin);
  button3State = digitalRead(button3Pin);
  button4State = digitalRead(button4Pin);
  button5State = digitalRead(button5Pin);
  button6State = digitalRead(button6Pin);
  button7State = digitalRead(button7Pin);
  button8State = digitalRead(button8Pin);
  button9State = digitalRead(button9Pin);
  
  // read the input on analog pins:
  groveLightVal = analogRead(A0);
  grovePotVal = analogRead(A1);
  slidePotVal = analogRead(A2);

  groveLightVal = map(groveLightVal, 0, 1023, 0, 255);
  grovePotVal = map(grovePotVal, 0, 1023, 0, 255);
  slidePotVal = map(slidePotVal, 0, 1023, 0, 255);
  
  // print out the value you read:
  Serial.print(String("analog ") + groveLightVal + String(" "));
  Serial.print(grovePotVal + String(" "));
  Serial.print(slidePotVal + String("\r\n"));

  Serial.print(String("digital ") + button2State + String(" "));
  Serial.print(button3State + String(" "));
  Serial.print(button4State + String(" "));
  Serial.print(button5State + String(" "));
  Serial.print(button6State + String(" "));
  Serial.print(button7State + String(" "));
  Serial.print(button8State + String(" "));
  Serial.print(button9State + String("\r\n"));
  
  delay(100);        // delay in between reads for stability
}
