#ifndef MOTORS_H
#define MOTORS_H

// Simplifies code reading for left and 
// right motor positions
typedef enum {
    LEFT,
    RIGHT
} Position;

// A class to implement pin operations for moving to
// allow abstraction 
class Motor {
    public:
        Motor(int pin1, int pin2, Position p);
        void moveForward();
        void moveBackward();
        void stop();
        Position getPosition();
    private:
        int _pin1;
        int _pin2;
        Position _position;
};

// A class to combine two motors into allowing moving
// forward in one operation rather than calling
// both motors
class UnifiedMotor {
    public:
        UnifiedMotor(Motor *leftMotor, Motor *rightMotor);
        void moveForward();
        void moveBackward();
        void stop();
        void turnLeft(double theta);
        void turnRight(double theta);
        Motor* getLeftMotor();
        Motor* getRightMotor();
    private:
        Motor *_leftMotor;
        Motor *_rightMotor;   
};

#endif