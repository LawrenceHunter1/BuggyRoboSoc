#ifndef BUGGY_H
#define BUGGY_H
#include "head.h"
#include "motors.h"

// Easier readability for action types
enum ACTION_ID {
    TURN=1,
    MOVE=2
};

// Type to store id bundled with array of parameters
typedef struct action
{
    ACTION_ID id;
    double parameters[1];
} action;

// stack implementation with an array of actions
typedef struct action_stack
{
    int top;
    unsigned capacity;
    action* array;
} action_stack;

// Class to act as a wrapper to the action_stack type providing
// functionality to the stack
class ActionStack {
    public:
        ActionStack();
        void createActionStack();
        int isEmpty();
        int push(action action);
        action pop();
        action peek();
        action_stack* _stack;
};

// Class to unify components allowing more complex abstract 
// operations implementing actionstack to simulate memory
// TODO stop bugging looping from undo
class Buggy {
    public:
        Buggy(UnifiedMotor *uMotor, Head *head);
        Head* head();
        UnifiedMotor* uMotor();
        Motor* leftMotor();
        Motor* rightMotor();
        void turnToNearestPoint();
        void turnToFurthestPoint();
        void turnToNearestPointOpt();
        void turnToFurthestPointOpt();
        void turn(double degrees);
        void undo(int steps);
        void revertAction(action* action);
        void revertTurn(double degrees);
        void move(double distance);
        void revertMove(double distance);
    private:
        Head* _head;
        UnifiedMotor* _uMotor;
        ActionStack _actionStack;
};


#endif