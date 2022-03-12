#include <iostream>

class interval{
private:
    double left, right;

public:
    void setLeft(double value){left = value;}
    void setRight(double value){right = value;}
    double getLeft() const{return left;}
    double getRight() const{return right;}

    void print() const{
        printf("(%g;%g)", left, right);
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
};

interval intersection(interval i1, interval i2){
    interval cross{};
    cross.setLeft(0);
    cross.setRight(0);

    

    return cross;
}

int main(){
    // the first interval
    interval i1{};
    printf("Enter the first interval:\n");
    i1.enterLeft();
    i1.enterRight();
    printf("The first interval: ");
    i1.print();

    // the second interval
    interval i2{};
    printf("\n\nEnter the second interval:\n");
    i2.enterLeft();
    i2.enterRight();
    printf("The second interval: ");
    i2.print();



    return 0;
}
