#ifndef BUGGY_H
#define BUGGY_H
#include "head.h"
#include "motors.h"

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
    private:
        Head* _head;
        UnifiedMotor* _uMotor;
};

#endif