/* Program by Volgov Daniil
 * 6113 group
 * Variant #2
 * Intersection and combining intervals
 */

#include <iostream>
#include "interval.h"
using namespace std;

void interval_print(interval value){
    if(!value.getStatusL())
        cout << "(";
    else
        cout << "[";
    cout << value.getLeft() << ";" << value.getRight();
    if(!value.getStatusR())
        cout << ")" << endl;
    else
        cout << "]" << endl;
}

int main(){
    while(true){

        // the first interval
        interval i1;
        printf("Enter the first interval:\n");
        i1.createInterval();
        interval_print(i1);
        /*
        i1.statusLeft();
        i1.enterLeft();
        i1.enterRight();
        i1.statusRight();
         */

        // the second interval
        interval i2;
        printf("\nEnter the second interval:\n");
        i2.createInterval();
        interval_print(i2);
        /*
        i2.statusLeft();
        i2.enterLeft();
        i2.enterRight();
        i2.statusRight();
         */

        printf("\nThe first interval: ");
        interval_print(i1);
        printf("The second interval: ");
        interval_print(i2);
        printf("\n");

        // intersection of intervals
        interval crossed = i1.intersection(i2);
        printf("The intersection: ");
        interval_print(crossed);
        int a;
        a=0;
        
        interval combined = i1.combining(i2);
        printf("The union: ");
        interval_print(combined);

        int stop;
        cout << "\n\n\x1B[32mStop execution?\033[0m\nType 0 to stop, type other number to continue: ";
        cin >> stop;
        if(stop == 0) break;
        cout << "\n\n";
    }
    return 0;
}
