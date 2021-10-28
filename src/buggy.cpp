#include "motors.h"
#include "head.h"
#include "buggy.h"
#include <arduino.h>

Buggy::Buggy(UnifiedMotor *uMotor, Head *head) {
    _uMotor = uMotor;
    _head = head;
}

Head* Buggy::head() {
    return _head;
}

UnifiedMotor* Buggy::uMotor() {
    return _uMotor;
}

Motor* Buggy::leftMotor() {
    return _uMotor->getLeftMotor();
}

Motor* Buggy::rightMotor() {
    return _uMotor->getRightMotor();
}

void Buggy::turnToNearestPoint() {
    int angle = -1;
    int min = 32767;
    for (int i = 0; i <= 180; i++) {
        _head->rotate(i);
        delay(10);
        int distance = _head->checkDistance();
        if (distance < min) {
            min = distance;
            angle = i;
        }
    }
    if (angle > 90) {
        _uMotor->turnLeft(float(angle-90));
    } else if (angle < 90) {
        _uMotor->turnRight(float(90-angle));
    }
}


void Buggy::turnToFurthestPoint() {
    int max, angle = -1;
    for (int i = 0; i <= 180; i++) {
        _head->rotate(i);
        delay(10);
        int distance = _head->checkDistance();
        if (distance > max) {
            max = distance;
            angle = i;
        }
    }
    if (angle > 90) {
        _uMotor->turnLeft(float(angle-90));
    } else if (angle < 90) {
        _uMotor->turnRight(float(90-angle));
    }
}


void Buggy::turnToNearestPointOpt() {
    int angle = -1;
    int min = 32767;
    int increment = 5;
    for (int i = 0; i <= 180; i = i + increment) {
        _head->rotate(i);
        int distance = _head->checkDistance();
        if (distance < min) {
            min = distance;
            angle = i;
        }
    }
    _head->rotate(angle);
    delay(100);
    for(int i = angle; i <= angle + increment; i++){
        _head->rotate(i);
        int distance = _head->checkDistance();
        if (distance < min) {
            min = distance;
            angle = i;
        }
    }
    if (angle > 90) {
        _uMotor->turnLeft(float(angle-90));
    } else if (angle < 90) {
        _uMotor->turnRight(float(90-angle));
    }
}


void Buggy::turnToFurthestPointOpt() {
    int max, angle = -1;
    int increment = 5;
    for (int i = 0; i <= 180; i = i + increment) {
        _head->rotate(i);
        int distance = _head->checkDistance();
        if (distance > max) {
            max = distance;
            angle = i;
        }
    }
    _head->rotate(angle);
    delay(100);
    for(int i = angle; i <= angle + increment; i++){
        _head->rotate(i);
        int distance = _head->checkDistance();
        if (distance > max) {
            max = distance;
            angle = i;
        }
    }
    if (angle > 90) {
        _uMotor->turnLeft(float(angle-90));
    } else if (angle < 90) {
        _uMotor->turnRight(float(90-angle));
    }
}

