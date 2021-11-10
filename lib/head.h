#ifndef HEAD_H
#define HEAD_H
#include "Servo.h"

// Class to encapsulate the sensor and servo
// allows implementation of rotation and distance
// checking simply
class Head {
    public:
        Head(int echo, int trig);
        void initialise();
        double checkDistance();
        void rotate(double angle);
        int getEchoPin();
        int getTrigPin();
        Servo* getServo();
        void setServo(Servo* servo);
    private:
        int _echo;
        int _trig;
        Servo* _servo;
};

#endif