typedef enum {
    LEFT,
    RIGHT
} Position;

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

class UnifiedMotor {
    public:
        UnifiedMotor(Motor *leftMotor, Motor *rightMotor);
        void moveForward();
        void moveBackward();
        void stop();
    private:
        Motor *_leftMotor;
        Motor *_rightMotor;   
};