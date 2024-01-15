

// code only works if FIRST_LED < LAST_LED
// and there are no gaps in the pins.

const int FIRST_LED = 2;
const int LAST_LED = 7;

const int MAX_SPEED = 60;
const int MIN_SPEED = 30;

int cur_led = FIRST_LED - 2;

void setup() {
  // put your setup code here, to run once:

  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);

  Serial.begin(9600);

}


// function to check the direction of the light
// returns a boolean value: HIGH = (relative) right, LOW = left
bool checkDir() {

  static bool direction;

  if (cur_led <= FIRST_LED - 1) direction = HIGH;
  if (cur_led >= LAST_LED + 1) direction = LOW;

  return direction;
}

// function that updates the led, based on the direction and speed
// param bool direction defines the direction of the light
// param speed is the speed at wicht the light moves 
void updateLeds(bool direction, int speed) {

  if (direction) {
    cur_led++;

    digitalWrite(cur_led, HIGH);
    digitalWrite(cur_led - 2, LOW);
  }

  else {
    cur_led--;

    digitalWrite(cur_led, HIGH);
    digitalWrite(cur_led + 2, LOW);
  }

  delay(speed);
}


// main function moves the light "nightrider style"
void loop() {
  // put your main code here, to run repeatedly:

  bool direction = checkDir();

  int raw_speed = analogRead(A0);

  int speed = map(raw_speed, 0, 600, MIN_SPEED, MAX_SPEED);

  Serial.println(raw_speed);

  if (raw_speed < 600) {

    updateLeds(direction, speed);

  }

}
