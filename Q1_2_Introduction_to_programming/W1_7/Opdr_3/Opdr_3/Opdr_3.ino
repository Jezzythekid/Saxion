const int pinds[] = {2, 3, 4, 5, 6, 7};


void setup() {
  // put your setup code here, to run once:
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

}

void loop() {
  // put your main code here, to run repeatedly:

  // code only works if first_led < last_led
  // and there are no gaps in the pins.

  const int time = 100;
  const int first_led = 2;
  const int last_led = 7;
  

  for (int i = first_led + 1; i < last_led + 2; i++) {
    digitalWrite(i, HIGH);
    digitalWrite(i - 2, LOW);
    delay(time);
  }

  for (int i = last_led - 1; i > first_led - 2; i--) {
    digitalWrite(i, HIGH);
    digitalWrite(i + 2, LOW);
    delay(time);
  }
}
