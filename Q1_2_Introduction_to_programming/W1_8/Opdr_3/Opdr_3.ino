const short int NO_OF_SEGMENTS = 8;

const short int SEGMENTS[NO_OF_SEGMENTS] = { 5, 6, 7, 8, 9, 10, 11, 12 };
const short int BTN_TOGGLE = 2;
const short int BTN_SELECT = 3;

const short int BLINK_SPEED = 250;

void setup() {

  // Setting the pins to OUTPUT
  for (int i = 0; i <= NO_OF_SEGMENTS; i++) {
    pinMode(SEGMENTS[i], OUTPUT);
  }

  pinMode(BTN_TOGGLE, INPUT_PULLUP);  // btn_toggle
  pinMode(BTN_SELECT, INPUT_PULLUP);  // btn_select
}

/// function to update an bool array
/// @param segment the index of the array to update the value of
/// @param pins the bool array with the values to update
void update_segment(short int segment, bool pins[NO_OF_SEGMENTS]);

/// Stateful function to detect wether a button was pressed.
/// Returns true once for each time the button was pressed.
/// @return true if a new button press was detected since the lass call to this function.
/// @param pinNo Pin to check for the buttonpress.
bool toggle_button_pressed(int pinNo);

bool select_button_pressed(int pinNo);

/// Statefull function that blinks the selected segment by toggling it on/off.
/// Keeps track of the time that has elapsed since the last toggle, and of the current state of the segment.
/// Does nothing while callid in the time between the toggles
/// @param segment The segment (0..6) to toggle on/off.
/// @param duration The duration of the blink in ms.
void blink_segment(int segment, int duration);

void loop() {

  static short int selSegments = 0;
  static bool values[NO_OF_SEGMENTS] = { false };
  bool btnSelect;
  bool btntoggle;

  btnSelect = toggle_button_pressed(BTN_SELECT);
  btntoggle = select_button_pressed(BTN_TOGGLE);

  // when the select button is pressed, update the
  if (btntoggle) update_segment(selSegments, values);

  // when button is pressed, go to the next segment
  if (btnSelect && selSegments >= NO_OF_SEGMENTS - 1) selSegments = 0;
  else if (btnSelect && selSegments >= 0) selSegments++;


  // for loop to update the values according to the array values
  for (int i = 0; i <= NO_OF_SEGMENTS; i++) {
    digitalWrite(SEGMENTS[i], values[i]);
  }

  // blink the selected segment
  blink_segment(SEGMENTS[selSegments], BLINK_SPEED);
}


void update_segment(short int segment, bool pins[NO_OF_SEGMENTS]) {

  if (pins[segment]) pins[segment] = false;
  else pins[segment] = true;

  //pins[segment] = !pins[segment];
}

bool toggle_button_pressed(int pinNo) {

  static bool output;
  static bool buffer;
  bool input = digitalRead(pinNo);

  if (input && !output && !buffer) {
    output = true;
    buffer = true;
  } else output = false;

  if (buffer && !input) {
    buffer = false;
  }

  return output;
}

bool select_button_pressed(int pinNo) {

  static bool output;
  static bool buffer;
  bool input = digitalRead(pinNo);

  if (input && !output && !buffer) {
    output = true;
    buffer = true;
  } else output = false;

  if (buffer && !input) {
    buffer = false;
  }

  return output;
}

void blink_segment(int segment, int duration) {
  static long int startTime;
  static bool outputValue;
  long int diffTime;

  diffTime = millis() - startTime;

  if (diffTime > duration) {
    startTime = millis();

    if (outputValue) outputValue = false;
    else outputValue = true;
    digitalWrite(segment, outputValue);
  }
}
