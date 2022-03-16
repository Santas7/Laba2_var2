#include <iostream>

class interval{
private:
    int left, right;

public:
    void setLeft(int value){left = value;}
    void setRight(int value){right = value;}
    int getLeft() const{return left;}
    int getRight() const{return right;}

    void print() const{
        printf("(%d;%d)", left, right);
    }

    void enterLeft(){
        int value;
        printf("Left: ");
        scanf("%d", &value);
        left = value;
    }

    void enterRight(){
        int value;
        while(true){
            printf("Right: ");
            scanf("%d", &value);
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
    interval crossed{};

    int i1_left = i1.getLeft();
    int i1_right = i1.getRight();
    int i2_left = i2.getLeft();
    int i2_right = i2.getRight();

    if(i1_right < i2_left){
        crossed.setLeft(0);
        crossed.setRight(0);
        return crossed;
    }



    return crossed;
}

interval combining(interval i1, interval i2){
    interval combined{};
    combined.setLeft(0);
    combined.setRight(0);



    return combined;
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
    printf("\n\n");

    // intersection of intervals
    interval crossed{};
    crossed = intersection(i1, i2);
    crossed.print();



    return 0;
}
