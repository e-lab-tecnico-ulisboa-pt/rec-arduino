#include "rec.h"
#include "user_define.h"


void setup() {
  expr.begin("ELAB_LED_ARDUINO_V1.0");
}

void loop() {
  expr.state_machine();
}

