/** Документация к программе
	ФИО: Панюшкин Андрей Михайлович
	номер группы: 6113
**/

#include <windows.h>
#include <iostream>

using namespace std;

class WorkInterval{
private:
    double left, right;
public:
    void interSection(WorkInterval inter2)
    {
        double tmp = inter2.left;
        double tmpleft = left;
        double tmpright = right;
        while(left < right-1){
            left++;
            inter2.left = tmp;
            while(inter2.left < inter2.right){
                inter2.left++;
                if(inter2.left == left) cout << left << "\t";
            }
        }
        left = tmpleft;
        right = tmpright;

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

    WorkInterval() // конструктор по умолчанию интервал (0;0)
    {
        this->left = 0; this->right = 0;
    }

    WorkInterval(double left, double right) // конструктор с параметрами левого и правого конца
    {
        setLeft(left); setRight(right);
    }
};
double inputLeftInterval(double left)
{
    cin >> left;
    return left;
}
double inputRightInterval(double left, double right)
{
    while (true)
    {
        cout << "right: ";
        cin >> right;
        cout << endl;
        if (right < left)
        {
            printf("Левый конец должен быть < правого конца!");
        }
        else
            break;
    }
    return right;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8); //Задает выходную кодовую страницу,
    printf("|____________________________________________________|\n");
    printf("|     Лабораторная работа номер 2 ( 17 вариант(2) )     |\n");
    printf("|____________________________________________________|\n");
    while (true)
    {
        printf("\nВведите 1 для запуска и 2 для выхода: ");
        int command;
        scanf_s("%d", &command);
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
            // операция объединения интервалов
            //inter1.interUnion(inter2);
        }
        else if (command == 2)
            break;
        else
            printf("Ошибка! Не могу найти такой команды! Попробуйте еще раз!\n");
    }
    return 0;
}


