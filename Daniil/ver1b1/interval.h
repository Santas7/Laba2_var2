//
// Created by Даниил Вольгов on 14.04.2022.
//

#include <iostream>
using namespace std;

#ifndef DANIIL_INTERVAL_H
#define DANIIL_INTERVAL_H

class interval{
private:
    double _left{}, _right{};
    bool _statusL{}, _statusR{};

public:
    interval() : _left(0), _right(0), _statusL(false), _statusR(false) {}
    interval(bool statusL, double left, double right, bool statusR);

    // sets
    void setLeft(double value);
    void setRight(double value);
    void setStatusL(bool value);
    void setStatusR(bool value);
    // gets
    double getLeft() const;
    double getRight() const;
    bool getStatusL() const;
    bool getStatusR() const;

    interval intersection(const interval& other) const;
    interval combining(const interval& other) const;

    void createInterval();

    void enterLeft();
    void enterRight();
    void statusLeft();
    void statusRight();
};


#endif //DANIIL_INTERVAL_H
