/** Документация к программе
	ФИО: Панюшкин Андрей Михайлович
	номер группы: 6113
**/

#include <iostream>

using namespace std;

class WorkInterval{
private:
    double left, right;
public:
    void printRes(double var)
    {
        cout << var << "\t";
    }
    void interUnion(WorkInterval inter2) 
    {
        double min = left;
        double max = right;
        if(inter2.left < min) min = inter2.left;
        if(inter2.right > max) max = inter2.right;
        while(min < max-1){
            min++;
            printRes(min);
        }
    }
    void interSection(WorkInterval inter2)
    {
        double tmp = inter2.left;
        double tmpleft = left;
        double tmpright = right;
        while(left < right-1){
            left++;
            inter2.left = tmp;
            while(inter2.left < inter2.right-1){
                inter2.left++;
                if(inter2.left == left) printRes(left);
            }
        }
        left = tmpleft;
        right = tmpright;
        inter2.left = tmp;
    }

    void print()
    {
        cout << "(" << left << ";" << right << ")" << endl;
    }
    // Set() + Get()
    void setLeft(double left){this->left = left;}
    double getLeft(double left){return left;}
    void setRight(double right){this->right = right;}
    double getRight(double right){return right;}

    WorkInterval(double left = 0, double right = 0) // конструктор
    {
        setLeft(left); setRight(right);
    }
};
double inputLeftInterval(double left) // ввод левого конца интервала
{
    cin >> left;
    return left;
}
double inputRightInterval(double left, double right) // ввод правого конца интервала
{
    while (true)
    {
        cout << "right: ";
        cin >> right;
        cout << endl;
        if (right < left)
        {
            cout << "Левый конец должен быть < правого конца!";
        }
        else
            break;
    }
    return right;
}
int main()
{
    cout << "|____________________________________________________|" << endl;
    cout << "|     Лабораторная работа номер 2 ( 17 вариант(2) )     |" << endl;
    cout << "|____________________________________________________|" << endl;
    while (true) // главное меню
    {
        cout << "\nВведите 1 для запуска и 2 для выхода: ";
        int command;
        cin >> command;
        if (command == 1)
        {
            double left, right;
            WorkInterval inter1;
            WorkInterval inter2;
            // ввод первого интервала
            cout << "1 интервал-->" << endl;
            cout << "left: ";
            left = inputLeftInterval(left);
            right = inputRightInterval(left, right);
            inter1.setLeft(left);
            inter1.setRight(right);

            // ввод второго интервала
            cout << "2 интервал-->" << endl;
            cout << "left: ";
            left = inputLeftInterval(left);
            right = inputRightInterval(left, right);
            inter2.setLeft(left);
            inter2.setRight(right);

            // вывод интервалов
            inter1.print(); inter2.print();

            // операция пересечения интервалов
            cout << "пересечение интервалов: " << endl;
            inter1.interSection(inter2);
            cout << endl;

            // операция объединения интервалов
            cout << "объединение интервалов: " << endl;
            inter1.interUnion(inter2);
        }
        else if (command == 2)
            break;
        else
            cout << "Ошибка! Не могу найти такой команды! Попробуйте еще раз!" << endl;
    }
    return 0;
}
