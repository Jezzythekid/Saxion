void setup() {
  // put your setup code here, to run once:
  pinMode(2, INPUT);
  pinMode(3, OUTPUT);
  Serial.begin(9600);

}

/// Stateful function that returns the number of milliseconds the button was kept pressed
/// before it was released.
/// Returns a value once each time the button was released.
/// @return The time the button was kept pressed before it was released, in milliseconds, or -1 if no button release was detected since the last call to this function.
int button_pressed_time();

void loop() {
  // put your main code here, to run repeatedly:
  int timePressed = button_pressed_time();
  bool buttonPressed = digitalRead(2);

  if (timePressed < 1000 && !buttonPressed) {
    digitalWrite(3, HIGH);
  } else if (timePressed > 1000 buttonPressed) {
    digitalWrite(3, LOW);
  }
  Serial.println(timePressed);
}

int button_pressed_time() {
  
  bool BtnValue = digitalRead(2);
  static int TimeStart;
  static int TimeDifference;


  if (BtnValue == false) {
    TimeStart = millis();

  } else {
    TimeDifference = millis() - TimeStart;
  }

  return TimeDifference;
  
}