#include <Arduino.h>
#include "rec.h"


experiment expr;


void serialEvent() {
  while (Serial.available()) {
    expr.receive (Serial.read());
  }
}
