#include "encoder.h"
#include <Arduino.h>

Encoder::Encoder(int PinA, int PinB)
{
    // set privat var, pin numbers
    pin_a = PinA;
    pin_b = PinB;
    // set pin a and b to be input
    pinMode(pin_a, INPUT);
    pinMode(pin_b, INPUT);
    // and turn on pullup resistors
    digitalWrite(pin_a, HIGH);
    digitalWrite(pin_b, HIGH);
    printf("pin_a %d, pin_b %d \r\n", pin_a, pin_b);
}

void Encoder::update(int direction){
/*    int MSB = digitalRead(pin_a);
    int LSB = digitalRead(pin_b);
    //direction 0=CCW, 1=CW Rotation
    int encoded = (direction << 2 ) | (MSB << 1) | LSB;

    if ((encoded == 0b010)||(encoded == 0b111))
        count++;
    if ((encoded == 0b011)||(encoded == 0b110))
        count--;
*/
    count++;
//    printf("encoded %d, MSB %d, LSB %d, count %ld \r\n", encoded, MSB, LSB, getCount());
}
