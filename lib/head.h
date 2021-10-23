#include "Servo.h"

class Head {
    public:
        Head(int echo, int trig);
        void initialise();
        long checkDistance();
        void rotate(long angle);
        int getEchoPin();
        int getTrigPin();
        Servo* getServo();
        void setServo(Servo* servo);
    private:
        int _echo;
        int _trig;
        Servo* _servo;
};