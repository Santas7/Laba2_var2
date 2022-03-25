#include <iostream>

class interval{
private:
    double left, right;
    bool printIt = true;

public:
    void setPrintIt(bool value){printIt = value;}
    void setLeft(double value){left = value;}
    void setRight(double value){right = value;}
    double getLeft() const{return left;}
    double getRight() const{return right;}

    void print() const{
        printf("(%g;%g)", left, right);
    }

    void enterLeft(bool printIt = true){
        if(printIt){
            double value;
            printf("Left: ");
            scanf("%lf", &value);
            left = value;
        }
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
    interval crossed{};
    crossed.setLeft(-1);
    crossed.setRight(-1);

    double i1_left = i1.getLeft();
    double i1_right = i1.getRight();
    double i2_left = i2.getLeft();
    double i2_right = i2.getRight();

    // if two intervals do not cross
    if(i1_right < i2_left || i1_left > i2_right){
        crossed.setLeft(0);
        crossed.setRight(0);
        return crossed;
    }

    // if some ends are equal
    if(i1_left == i2_left || i1_right == i2_right){
        // (10;20) X (15;20)
        if (i1_left < i2_left){
            crossed.setLeft(i2_left);
            crossed.setRight(i1_right);
            return crossed;
        }
        // (15;20) X (10;20)
        if (i1_left > i2_left){
            crossed.setLeft(i1_left);
            crossed.setRight(i1_right);
            return crossed;
        }
        // (10;20) X (10;25)
        if(i1_right < i2_right){
            crossed.setLeft(i1_left);
            crossed.setRight(i1_right);
            return crossed;
        }
        // (10;20) X (10;15)
        if(i1_right > i2_right){
            crossed.setLeft(i1_left);
            crossed.setRight(i2_right);
            return crossed;
        }
        // if two intervals are equal
        crossed.setLeft(0);
        crossed.setRight(0);
        return crossed;
    }

    if(i1_left < i2_left){
        // (10;20) X (15;25)
        if(i1_right < i2_right){
            crossed.setLeft(i2_left);
            crossed.setRight(i1_right);
            return crossed;
        }
        // (10;25) X (15;20)
        if(i1_right > i2_right){
            crossed.setLeft(i2_left);
            crossed.setRight(i2_right);
            return crossed;
        }
    }
    else if(i1_left > i2_left){
        // (15:20) x (10;25)
        if(i1_right < i2_right){
            crossed.setLeft(i1_left);
            crossed.setRight(i1_right);
            return crossed;
        }
        // (15;25) X (10;20)
        if(i1_right > i2_right){
            crossed.setLeft(i1_left);
            crossed.setRight(i2_right);
            return crossed;
        }
    }

    return crossed;
}

interval combining(interval i1, interval i2){
    interval combined{};
    combined.setLeft(-1);
    combined.setRight(-1);
    combined.setPrintIt(true);

    double i1_left = i1.getLeft();
    double i1_right = i1.getRight();
    double i2_left = i2.getLeft();
    double i2_right = i2.getRight();

    // if two intervals do not cross
    // (10;15) U (20;25)
    if(i2_left > i1_right){
        combined.setLeft(i1_left);
        combined.setRight(i1_right);
        printf("\n(%g;%g) U (%g;%g)", i1_left, i1_right, i2_left, i2_right);
        combined.setPrintIt(false);
        return combined;
    }
    // (20;25) U (10;15)
    if(i1_right > i1_left){
        combined.setLeft(i1_left);
        combined.setRight(i1_right);
        printf("\n(%g;%g) U (%g;%g)", i1_left, i1_right, i2_left, i2_right);
        return combined;
    }

    // if some ends are equal
    if(i1_left == i2_left || i1_right == i2_right){
        // (10;20) U (15;20)
        if (i1_left < i2_left){
            combined.setLeft(i1_left);
            combined.setRight(i1_right);
            return combined;
        }
        // (15;20) U (10;20)
        if (i1_left > i2_left){
            combined.setLeft(i2_left);
            combined.setRight(i1_right);
            return combined;
        }
        // (10;20) U (10;25)
        if(i1_right < i2_right){
            combined.setLeft(i1_left);
            combined.setRight(i2_right);
            return combined;
        }
        // (10;20) U (10;15)
        if(i1_right > i2_right){
            combined.setLeft(i1_left);
            combined.setRight(i1_right);
            return combined;
        }
        // if two intervals are equal
        combined.setLeft(0);
        combined.setRight(0);
        return combined;
    }

    if(i1_left < i2_left){
        // (10;20) U (15;25)
        if(i1_right < i2_right){
            combined.setLeft(i1_left);
            combined.setRight(i2_right);
            return combined;
        }
        // (10;25) U (15;20)
        if(i1_right > i2_right){
            combined.setLeft(i1_left);
            combined.setRight(i2_right);
            return combined;
        }
    }
    else if(i1_left > i2_left){
        // (15;20) U (10;25)
        if(i1_right < i2_right){
            combined.setLeft(i2_left);
            combined.setRight(i2_right);
            return combined;
        }
        // (15;25) U (10;20)
        if(i1_right > i2_right){
            combined.setLeft(i2_left);
            combined.setRight(i1_right);
            return combined;
        }
    }

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
    printf("The intersection: ");
    crossed.print();

    interval combined{};
    combined = combining(i1, i2);
    printf("\nThe union: ");
    combined.print();

    return 0;
}
