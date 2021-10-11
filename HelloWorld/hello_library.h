#ifndef HELLO_LIBRARY_H
#define HELLO_LIBRARY_H

#include <Arduino.h>

void hello() {
    digitalWrite(LED_BUILTIN, HIGH);
    delay(100);
    digitalWrite(LED_BUILTIN, LOW);
    delay(100);
}

#endif