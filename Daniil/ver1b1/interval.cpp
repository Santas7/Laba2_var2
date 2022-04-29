//
// Created by Даниил Вольгов on 14.04.2022.
//

#include "interval.h"
using namespace std;

interval::interval(bool statusL, double left, double right, bool statusR){}

// sets
void interval::setLeft(double value){
    if(value <= _right)
        _left = value;
}
void interval::setRight(double value){
    if(value >= _left)
        _right = value;
}
void interval::setStatusL(bool value){
    if(_right == _left){
        _statusL = _statusR && value;
    }
    else _statusL = value;
}
void interval::setStatusR(bool value){
    if(_left == _right){
        _statusR = _statusL && value;
    }
    else _statusR = value;
}

// gets
double interval::getLeft() const{
    return _left;}
double interval::getRight() const{
    return _right;}
bool interval::getStatusL() const{
    return _statusL;}
bool interval::getStatusR() const{
    return _statusR;}

interval interval::intersection(const interval& other) const{
    interval crossed{};

    // (10;15) X (20;25) or (20;25) X (10;15)
    if(other._left > _right || _left > other._right){
        return crossed;
    }

    // comparing starts of interval
    if(_left > other._left){ // (20;x) X (10;x)
        crossed._left = _left;
        //crossed.setLeft(_left);
        crossed._statusL = _statusL;
        //crossed.setStatusL(_statusL);
    }
    else if(_left < other._left){ // (10;x) X (20;x)
        crossed._left = other._left;
        //crossed.setLeft(other._left);
        crossed._statusL = other._statusL;
        //crossed.setStatusL(other._statusL);
    }
    else{ // (10;x) X [10;x)
        crossed._left = _left;
        //crossed.setLeft(_left);
        crossed._statusL = _statusL && other._statusL;
        //crossed.setStatusL(_statusL && other._statusL);
    }

    // comparing ends of interval
    if(_right > other._right){ // (x;20) X (x;10)
        crossed._right = other._right;
        //crossed.setRight(other._right);
        crossed._statusR = other._statusR;
        //crossed.setStatusR(other._statusR);
    }
    else if(_right < other._right){ // (x;10) X (x;20)
        crossed._right = _right;
        //crossed.setRight(_right);
        crossed._statusR = _statusR;
        //crossed.setStatusR(_statusR);
    }
    else{ // [x;10) X (x;10)
        crossed._right = _right;
        //crossed.setRight(_right);
        crossed._statusR = _statusR && other._statusR;
        //crossed.setStatusR(_statusR && other._statusR);
    }

    if(_right == other._left){
        crossed._statusL = _statusR && other._statusL;
        //crossed.setStatusL(_statusR && other._statusL);
        crossed._statusR = _statusR && other._statusL;
        //crossed.setStatusR(_statusR && other._statusL);
    }
    if(_left == other._right){
        crossed._statusL = _statusL && other._statusR;
        //crossed.setStatusL(_statusL && other._statusR);
        crossed._statusR = _statusL && other._statusR;
        //crossed.setStatusR(_statusL && other._statusR);
    }

    return crossed;
}

interval interval::combining(const interval& other) const{
    interval combined{};

    // (10;15) U (20;25) or (20;25) U (10;15)
    if(other._left > _right or _left > other._right){
        return combined;
    }

    // comparing starts of interval
    if(_left > other._left){
        combined._left = other._left;
        //combined.setLeft(other._left);
        combined._statusL = other._statusL;
        //combined.setStatusL(other._statusL);
    }
    else if(_left < other._left){
        combined._left = _left;
        //combined.setLeft(_left);
        combined._statusL = _statusL;
        //combined.setStatusL(_statusL);
    }
    else{
        combined._left = _left;
        //combined.setLeft(_left);
        combined._statusL = _statusL || other._statusL;
        //combined.setStatusL(_statusL || other._statusL);
    }

    // comparing ends of interval
    if(_right > other._right){
        combined._right = _right;
        //combined.setRight(_right);
        combined._statusR = _statusR;
        //combined.setStatusR(_statusR);
    }
    else if(_right < other._right){
        combined._right = other._right;
        //combined.setRight(other._right);
        combined._statusR = other._statusR;
        //combined.setStatusR(other._statusR);
    }
    else{
        combined._right = _right;
        //combined.setRight(_right);
        combined._statusR = _statusR || other._statusR;
        //combined.setStatusR(_statusR || other._statusR);
    }

    return combined;
}

void interval::createInterval(){
    char strL[1] = "";
    while(true){
        cout << "Left bracket: ";
        cin >> strL[0];
        if(strL[0] == '('){
            //setStatusL(false);
            _statusL = false;
            break;
        }
        else if(strL[0] == '['){
            //setStatusL(true);
            _statusL = true;
            break;
        }
        else
            cout << "\x1B[31mInvalid character!\n\033[0m";
    }

    double new_left;
    printf("Left: ");
    scanf("%lf", &new_left);
    _left = new_left;
    //setLeft(new_left);

    double new_right;
    while(true){
        printf("Right: ");
        scanf("%lf", &new_right);
        if(new_right < _left){
            printf("\x1B[31mThe right number must be greater than the left one!\n\033[0m");
        }
        else{
            _right = new_right;
            //setRight(new_right);
            break;
        }
    }

    char strR[1] = "";
    while(true){
        cout << "Right bracket: ";
        cin >> strR[0];
        if(strR[0] == ')'){
            if(_left == _right){
                _statusL = false;
            }
            //setStatusR(false);
            _statusR = false;
            break;
        }
        else if(strR[0] == ']'){
            if(_left == _right){
                _statusR = _statusL;
                break;
            }
            //setStatusR(true);
            _statusR = true;
            break;
        }
        else
            cout << "\x1B[31mInvalid character!\n\033[0m";
    }

}

void interval::enterLeft(){
    double new_left;
    printf("Left: ");
    scanf("%lf", &new_left);
    setLeft(new_left);
}
void interval::enterRight(){
    double new_right;
    while(true){
        printf("Right: ");
        scanf("%lf", &new_right);
        if(new_right < _left){
            printf("\x1B[31mThe right number must be greater than the left one!\n\033[0m");
        }
        else{
            setRight(new_right);
            break;
        }
    }
}
void interval::statusLeft(){
    char strL[1] = "";
    while(true){
        cout << "Left bracket: ";
        cin >> strL[0];
        if(strL[0] == '('){
            setStatusL(false);
            //_statusL = false;
            break;
        }
        else if(strL[0] == '['){
            setStatusL(true);
            //_statusL = true;
            break;
        }
        else
            cout << "\x1B[31mInvalid character!\n\033[0m";
    }
}
void interval::statusRight(){
    char strR[1] = "";
    while(true){
        cout << "Right bracket: ";
        cin >> strR[0];
        if(strR[0] == ')'){
            setStatusR(false);
            //_statusR = false;
            break;
        }
        else if(strR[0] == ']'){
            setStatusR(true);
            //_statusR = true;
            break;
        }
        else
            cout << "\x1B[31mInvalid character!\n\033[0m";
    }
}
