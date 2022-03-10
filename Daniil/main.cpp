#include <iostream>

class interval{
private:
    double a{};
    double b{};

public:
    void setA(int value){a = value;}
    void setB(int value){b = value;}
    double getA() const{return a;}
    double getB() const{return b;}

    void print() const{
        printf("(%d;%d)", a, b);
    }

    explicit interval(int a = 0, int b = 0){
        setA(a);
        setB(b);
    }
};

int main() {
    interval i1;
    interval i2;

    int a1, b1, a2, b2;

    printf("Enter the first interval:\n");
    printf("a = ");
    scanf("%d", &a1);
    printf("b = ");
    scanf("%d", &b1);

    i1.setA(a1);
    i1.setB(b1);

    printf("Enter the second interval:\n");
    printf("a = ");
    scanf("%d", &a2);
    printf("b = ");
    scanf("%d", &b2);

    i2.setA(a2);
    i2.setB(b2);

    i1.print();
    i2.print();

    return 0;
}
