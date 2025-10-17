int ledPin = 2;  
char myData = 0;

int motor1Pin1 = 27;
int motor1Pin2 = 26;
int enable1Pin = 12;

// Setting PWM properties
const int freq = 30000;
const int pwmChannel = 0;
const int resolution = 8;
int dutyCycle = 200;

const byte pin_rpm = 13;
int volatile rev = 0;
//int rpm = 0;

void setup()
{
  pinMode(ledPin, OUTPUT);  
  Serial.begin(115200);
  // sets the pins
  pinMode(motor1Pin1, OUTPUT);
  pinMode(motor1Pin2, OUTPUT);
  pinMode(enable1Pin, OUTPUT);
  pinMode(pin_rpm, INPUT_PULLUP);
  //  pinMode(pin_rpm, INPUT);
  //attachInterrupt(digitalPinToInterrupt(pin_rpm), isr, RISING);

  // configure LED PWM functionalitites
  ledcSetup(pwmChannel, freq, resolution);

  // attach the channel to the GPIO to be controlled
  ledcAttachPin(enable1Pin, pwmChannel);

  // testing
  Serial.print("Testing DC Motor...");

}

void MotorOn()
{
  // Move DC motor forward with increasing speed
  dutyCycle = 205;
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  ledcWrite(pwmChannel, dutyCycle);
}

void MotorOff()
{
  dutyCycle = 0;
  digitalWrite(motor1Pin1, HIGH);
  digitalWrite(motor1Pin2, LOW);
  ledcWrite(pwmChannel, dutyCycle);
}

void loop()
{
myData = int(Serial.read());

if (myData == '1'){  
  Serial.println("LED is on !!!");  
  digitalWrite(ledPin, HIGH);
  MotorOn();
}
else if (myData == '0'){  
  Serial.println("LED is off !!!");  
  digitalWrite(ledPin, LOW);
  MotorOff();
}
}