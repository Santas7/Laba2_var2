/* Program by Volgov Daniil
 * 6113 group
 * Variant #2
 * Intersection and combining intervals
 */

#include <iostream>
using namespace std;

class interval{
private:
    double left, right;
    bool statusL, statusR;

public:
    void setLeft(double value){left = value;}
    void setRight(double value){right = value;}
    void setStatusL(bool value){statusL = value;}
    void setStatusR(bool value){statusR = value;}
    double getLeft() const{return left;}
    double getRight() const{return right;}
    bool getStatusL() const{return statusL;}
    bool getStatusR() const{return statusR;}

    void print() const{
        if(!statusL)
            cout << "(";
        else
            cout << "[";
        cout << left << ";" << right;
        if(!statusR)
            cout << ")" << endl;
        else
            cout << "]" << endl;
    }

    void enterLeft(){
        double value;
        printf("Left: ");
        scanf("%lf", &value);
        left = value;
    }

    void enterRight(){
        double value;
        while(true){
            printf("Right: ");
            scanf("%lf", &value);
            if(value < left){
                printf("\x1B[31mThe right number must be greater than the left one!\n\033[0m");
            }
            else{
                right = value;
                break;
            }
        }
    }

    void statusLeft(){
        char str[1] = "";
        while(true){
            cout << "Left bracket: ";
            cin >> str[0];
            if(str[0] == '('){
                statusL = false;
                break;
            }
            else if(str[0] == '['){
                statusL = true;
                break;
            }
            else
                cout << "\x1B[31mInvalid character!\n\033[0m";
        }
    }

    void statusRight(){
        char str[1] = "";
        while(true){
            cout << "Right bracket: ";
            cin >> str[0];
            if(str[0] == ')'){
                statusR = false;
                break;
            }
            else if(str[0] == ']'){
                statusR = true;
                break;
            }
            else
                cout << "\x1B[31mInvalid character!\n\033[0m";
        }
    }
};

interval intersection(interval i1, interval i2){
    interval crossed{};
    crossed.setStatusL(false);
    crossed.setStatusR(false);
    crossed.setLeft(0);
    crossed.setRight(0);

    // i1
    bool i1_statusL = i1.getStatusL();
    double i1_left = i1.getLeft();
    double i1_right = i1.getRight();
    bool i1_statusR = i1.getStatusR();
    // i2
    bool i2_statusL = i2.getStatusL();
    double i2_left = i2.getLeft();
    double i2_right = i2.getRight();
    bool i2_statusR = i2.getStatusR();

    // (10;15) U (20;25) or (20;25) U (10;15)
    if(i2_left > i1_right or i1_left > i2_right){
        return crossed;
    }

    // comparing starts of interval
    if(i1_left > i2_left){ // (20;x) U (10;x)
        crossed.setLeft(i1_left);
        crossed.setStatusL(i1_statusL);
    }
    else if(i1_left < i2_left){ // (10;x) U (20;x)
        crossed.setLeft(i2_left);
        crossed.setStatusL(i2_statusL);
    }
    else{ // (10;x) U [10;x)
        crossed.setLeft(i1_left);
        crossed.setStatusL(i1_statusL && i2_statusL);
    }

    // comparing ends of interval
    if(i1_right > i2_right){ // (x;20) U (x;10)
        crossed.setRight(i2_right);
        crossed.setStatusR(i2_statusR);
    }
    else if(i1_right < i2_right){ // (x;10) U (x;20)
        crossed.setRight(i1_right);
        crossed.setStatusR(i1_statusR);
    }
    else{ // [x;10) U (x;10)
        crossed.setRight(i1_right);
        crossed.setStatusR(i1_statusR && i2_statusR);
    }

    return crossed;
}

interval combining(interval i1, interval i2){
    interval combined{};
    combined.setStatusL(false);
    combined.setStatusR(false);
    combined.setLeft(0);
    combined.setRight(0);

    // i1
    bool i1_statusL = i1.getStatusL();
    double i1_left = i1.getLeft();
    double i1_right = i1.getRight();
    bool i1_statusR = i1.getStatusR();
    // i2
    bool i2_statusL = i2.getStatusL();
    double i2_left = i2.getLeft();
    double i2_right = i2.getRight();
    bool i2_statusR = i2.getStatusR();

    // (10;15) U (20;25) or (20;25) U (10;15)
    if(i2_left > i1_right or i1_left > i2_right){
        return combined;
    }

    // comparing starts of interval
    if(i1_left > i2_left){
        combined.setLeft(i2_left);
        combined.setStatusL(i2_statusL);
    }
    else if(i1_left < i2_left){
        combined.setLeft(i1_left);
        combined.setStatusL(i1_statusL);
    }
    else{
        combined.setLeft(i1_left);
        combined.setStatusL(i1_statusL || i2_statusL);
    }

    // comparing ends of interval
    if(i1_right > i2_right){
        combined.setRight(i1_right);
        combined.setStatusR(i1_statusR);
    }
    else if(i1_right < i2_right){
        combined.setRight(i2_right);
        combined.setStatusR(i2_statusR);
    }
    else{
        combined.setRight(i1_right);
        combined.setStatusR(i1_statusR || i2_statusR);
    }

    return combined;
}

int main(){
    while(true){
        // the first interval
        interval i1{};
        printf("Enter the first interval:\n");
        i1.statusLeft();
        i1.enterLeft();
        i1.enterRight();
        i1.statusRight();
        printf("The first interval: ");
        i1.print();

        // the second interval
        interval i2{};
        printf("\nEnter the second interval:\n");
        i2.statusLeft();
        i2.enterLeft();
        i2.enterRight();
        i2.statusRight();
        printf("The second interval: ");
        i2.print();
        printf("\n");

        // intersection of intervals
        interval crossed{};
        crossed = intersection(i1, i2);
        printf("The intersection: ");
        crossed.print();

        interval combined{};
        combined = combining(i1, i2);
        printf("The union: ");
        combined.print();

        int stop;
        cout << "\n\n\x1B[32mContinue execution?\033[0m\nType 0 to continue, type other number to stop: ";
        cin >> stop;
        if(stop == 0) break;
        cout << "\n\n";
    }

    return 0;
}
