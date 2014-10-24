/*Interrupt Example (the Encoder interrupts the processor).
Uses a single interrupt pin, wraps the Encoder into a C++ class.
http://playground.arduino.cc/Main/RotaryEncoders#Example4
*/

#ifndef ENCODER_H
#define ENCODER_H

#define ENCODER_INT_MODE	  FALLING

class Encoder
{
public:
    Encoder(int PinA, int PinB);
    void update(int direction);
    long int getCount() { return count; };
    void clearCount() { count = 0; };
private:
    long int count;
    int pin_a;
    int pin_b;
};

#endif // ENCODER_H
