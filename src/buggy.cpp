#include "motors.h"
#include "head.h"
#include "buggy.h"
#include <stdlib.h>
#include <arduino.h>

// Number of actions to store in the stack
#define MEMORY_SIZE 10
// Degrees of step for optimised scans
#define INCREMENT 5

// Constructor for action stack
ActionStack::ActionStack() {
    createActionStack();
}

// Creates a temp actionstack sets appropriate variables
// sets private stack to temp handles failure by waiting
// then reattempting.
void ActionStack::createActionStack() {
    action_stack* stack = (action_stack*)malloc(sizeof(action_stack));
    if (stack == NULL) {
        delay(500);
        createActionStack();
    }
    stack->capacity = MEMORY_SIZE;
    stack->top = -1;
    stack->array = (action*)malloc(stack->capacity * sizeof(action));
    if (stack->array == NULL) {
        delay(500);
        createActionStack();
    }
    _stack = stack;
    Serial.println("ACTION STACK - CREATED");
}

// Checks if no initialisation has occured
int ActionStack::isEmpty() {
    return _stack->top == - 1;
}

// Cyclic push looping the top pointer back to 0 
int ActionStack::push(action action) {
    if (_stack->top == _stack->capacity - 1) {
        _stack->top = -1;
    } 
    (_stack->array)[++_stack->top] = action;
    Serial.println("ACTION STACK - ACTION PUSHED");
    Serial.println();
    return 1;
}

// Returns an action and uses cyclic to set top = -1 -> capacity - 1
action ActionStack::pop() {
    if (isEmpty()) {
        action action;
        return action;
    }
    action action = (_stack->array)[_stack->top];
    if (_stack->top == 0) {
        _stack->top = _stack->capacity - 1;
    } else {
        _stack->top--;
    }
    Serial.println("ACTION STACK - ACTION POPPED");
    return action;
}

// Returns the action pointed by top no pointer change
action ActionStack::peek() {
    if (isEmpty()) {
        action action;
        return action;
    }
    Serial.println("ACTION STACK - ACTION PEEKED");
    return (_stack->array)[_stack->top];
}

// Constructor assinging pointers and creating instance 
// of action stack
Buggy::Buggy(UnifiedMotor *uMotor, Head *head) {
    Serial.println("BUGGY - INSTANTIATED");
    _uMotor = uMotor;
    _head = head;
    _actionStack = ActionStack();
}

// gets the head pointer
Head* Buggy::head() {
    Serial.println("BUGGY - GET HEAD");
    return _head;
}

// gets the uMotor pointer
UnifiedMotor* Buggy::uMotor() {
    Serial.println("BUGGY - GET UMOTOR");
    return _uMotor;
}

// gets the left motor pointer
Motor* Buggy::leftMotor() {
    Serial.println("BUGGY - GET LEFT MOTOR");
    return _uMotor->getLeftMotor();
}

// gets the right motor pointer
Motor* Buggy::rightMotor() {
    Serial.println("BUGGY - GET RIGHT MOTOR");
    return _uMotor->getRightMotor();
}

// Scans the environment every degree and rotates 
// to the closest sensor reading
void Buggy::turnToNearestPoint() {
    Serial.println("BUGGY - TURN TO NEAREST POINT");
    int angle = -1;
    double min = 100000000;
    for (int i = 0; i <= 180; i++) {
        _head->rotate(i);
        delay(10);
        double distance = _head->checkDistance();
        if (distance < min) {
            min = distance;
            angle = i;
        }
    }
    turn(angle);
}

// Scans the environment every degree and rotates 
// to the furthest sensor reading
void Buggy::turnToFurthestPoint() {
    Serial.println("BUGGY - TURN TO FURTHEST POINT");
    double max = -1;
    int angle = -1;
    for (int i = 0; i <= 180; i++) {
        _head->rotate(i);
        delay(10);
        double distance = _head->checkDistance();
        if (distance > max) {
            max = distance;
            angle = i;
        }
    }
    turn(angle);
}


// Scans the environment every 5 degrees then
// scans ± increment/2 of nearest reading
// and rotates to the nearest sensor reading
void Buggy::turnToNearestPointOpt() {
    Serial.println("BUGGY - TURN TO NEAREST POINT (OPT)");
    // Every increment
    int angle = -1;
    double min = 100000000;
    int increment = INCREMENT;
    for (int i = 0; i <= 180; i = i + increment) {
        _head->rotate(i);
        double distance = _head->checkDistance();
        if (distance < min) {
            min = distance;
            angle = i;
        }
    }
    // ± increment / 2
    _head->rotate(angle);
    delay(100);
    for(int i = angle-(increment/2); i <= angle + (increment/2); i++){
        _head->rotate(i);
        double distance = _head->checkDistance();
        if (distance < min) {
            min = distance;
            angle = i;
        }
    }
    turn(angle);
}

// Scans the environment every 5 degrees then
// scans ± increment/2 of furthest reading
// and rotates to the furthest sensor reading
void Buggy::turnToFurthestPointOpt() {
    Serial.println("BUGGY - TURN TO FURTHEST POINT (OPT)");
    // Every increment
    double max = -1; 
    int angle = -1;
    int increment = INCREMENT;
    for (int i = 0; i <= 180; i = i + increment) {
        _head->rotate(i);
        double distance = _head->checkDistance();
        if (distance > max) {
            max = distance;
            angle = i;
        }
    }
    // ± increment / 2
    _head->rotate(angle);
    delay(100);
    for(int i = angle-(increment/2); i <= angle + (increment/2); i++){
        _head->rotate(i);
        double distance = _head->checkDistance();
        if (distance > max) {
            max = distance;
            angle = i;
        }
    }
    turn(angle);
}

// Based on an input angle calls the uMotor
// function to turn based on an angle 
// pushes the action onto the action stack
void Buggy::turn(double angle) {
    Serial.print("BUGGY - TURN ");
    Serial.println(angle);
    action new_action;
    new_action.id = TURN;
    if (angle < 0) {
        // To the left
        _uMotor->turnLeft(abs(angle));
        new_action.parameters[0] = angle;
    } else  {
        // To the right
        _uMotor->turnRight(angle);
        new_action.parameters[0] = angle;
    }
    if (_actionStack.push(new_action) == 0) {
        _uMotor->turnRight(100000.0f);
    }
}

// Based on an input angle calls the uMotor
// function to turn based on the angle parameter
// from the action
void Buggy::revertTurn(double angle) {
    Serial.print("BUGGY - TURN ");
    Serial.print(angle);
    Serial.println(" ***REVERT***");
    // Operations inverted from turn
    if (angle < 0) {
        // To the right
        _uMotor->getRightMotor()->moveBackward();
        delay(2475*(abs(angle)/360.0));
        _uMotor->getRightMotor()->stop();
    } else {
        // To the left
        _uMotor->getLeftMotor()->moveBackward();
        delay(2475*(angle/360.0));
        _uMotor->getLeftMotor()->stop();
    }
}

// Takes an input of the number of actions to 
// revert if the action poppped is valid calls
// a function to undo it
void Buggy::undo(int steps) {
    Serial.print("BUGGY - ");
    Serial.print(steps);
    Serial.println(" STEPS TO REVERT");
    action action_revert;
    for (int i = 0; i < steps; i++) {
        action_revert = _actionStack.pop();
        if (action_revert.id != NULL) {
            revertAction(&action_revert);
            Serial.println();
            delay(100);
        }
    }
}

// Based on action_id calls a function to do
// the opposite of the operation
void Buggy::revertAction(action* action) {
    switch (action->id) {
        case TURN: {
            double angle = (action->parameters)[0];
            revertTurn(angle);
            break;
        }
        case MOVE: {
            // move the same distance in the other direction
            double distance = (action->parameters)[0];
            revertMove(-distance);
        }
        default: {
            break;
        }
    }
}

// Based on the distance decides to move forwards or
// backwards uses the head checkDistance function
// to move until sensor shows distance moved
// then pushes the action onto the action stack
void Buggy::move(double distance) {
    Serial.print("BUGGY - MOVE ");
    Serial.print(distance);
    Serial.println("CM");
    action new_action;
    new_action.id = MOVE;

    double init_distance = _head->checkDistance();
    if (distance < 0.0) {
        _uMotor->moveBackward();
    }
    else {
        _uMotor->moveForward();
    }
    while(_head->checkDistance() > init_distance - distance) {
        delay(15);
    }
    _uMotor->stop();

    new_action.parameters[0] = distance;
    if (_actionStack.push(new_action) == 0) {
        _uMotor->turnRight(100000.0);
    }
}

// Same as move but doesn't append to stack
void Buggy::revertMove(double distance) {
    Serial.print("BUGGY - MOVE ");
    Serial.print(distance);
    Serial.print("CM");
    Serial.println(" ***REVERT***");

    double init_distance = _head->checkDistance();
    if (distance < 0) {
        _uMotor->moveBackward();
        while(_head->checkDistance() < init_distance - distance) {
            delay(15);
        }
    }
    else {
        _uMotor->moveForward();
        while(_head->checkDistance() > init_distance - distance) {
            delay(15);
        }
    }
    _uMotor->stop();
}