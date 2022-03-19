// 2 реализация
/** Документация к программе
	ФИО: Панюшкин Андрей Михайлович
	номер группы: 6113
    Задача: Класс интервала с учётом включения/исключения концов.Реализовать следующие методы:
     вычисление пересечения двух интервалов;
     вычисление объединения двух интервалов
    Для простоты считать, что интервалы, не имеющие общих точек, пересекаться/объединяться не могут
    (результат в таком случае должен равняться пустому интервалу (0; 0) с исключенными концами).
**/

#include <windows.h>
#include <iostream>

using namespace std;

class WorkInterval{
private:
    double left{}, right{};
public:
    static void printSection(double A[], int N)
    {
        for(int i = 0; i < N; i++){
            cout << A[i] << "\t";
        }
    }
    static void printUnion(WorkInterval inter1, WorkInterval inter2, double A[])
    {
        double min = inter1.left;
        double max = inter1.right;
        int i = 0;
        if(inter2.left < min) min = inter2.left;
        if(inter2.right > max) max = inter2.right;
        while(min < max-1){
            min++;
            cout << A[i] << "\t";
            i++;
        }
    }
    void interUnion(WorkInterval inter2, double A[]) const
    {
        double min = left;
        double max = right;
        int i = 0;
        if(inter2.left < min) min = inter2.left;
        if(inter2.right > max) max = inter2.right;
        while(min < max-1){
            min++;
            A[i] = min; i++;
        }
    }
    void interSection(WorkInterval inter2, double A[])
    {
        double tmp = inter2.left;
        double tmpleft = left;
        double tmpright = right;
        int i = 0;
        while(left < right-1){
            left++;
            inter2.left = tmp;
            while(inter2.left < inter2.right-1){
                inter2.left++;
                if(inter2.left == left){
                    A[i] = left; i++;
                }
            }
        }
        left = tmpleft;
        right = tmpright;
        inter2.left = tmp;
    }

    void print() const
    {
        cout << "(" << left << ";" << right << ")" << endl;
    }
    // Set() + Get()
    void setLeft(double left){this->left = left;}
    static double getLeft(double left){return left;}
    void setRight(double right){this->right = right;}
    static double getRight(double right){return right;}

    explicit WorkInterval(double left = 0, double right = 0) // конструктор
    {
        setLeft(left); setRight(right);
    }
};
void clearA(const double A[])
{
    delete [] A;
}
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
int findNumbersN(const double A[], int N)
{
    for(int i = 0; i < 100; i++){
        if(A[i] == 0.0){
            break;
        }
        N++;
    }
    return N;
}
int main()
{
    SetConsoleOutputCP(CP_UTF8); //Задает выходную кодовую страницу,
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
            int N = 0;
            auto *A = new double [100];
            WorkInterval inter1;
            WorkInterval inter2;
            // ввод первого интервала
            cout << "1 интервал-->" << endl;
            cout << "left: ";
            left = inputLeftInterval(left);
            right = inputRightInterval(left, right);
            inter1.setLeft(left); inter1.setRight(right);

            // ввод второго интервала
            cout << "2 интервал-->" << endl;
            cout << "left: ";
            left = inputLeftInterval(left);
            right = inputRightInterval(left, right);
            inter2.setLeft(left); inter2.setRight(right);

            // вывод интервалов
            inter1.print(); inter2.print();

            // операция пересечения интервалов
            cout << "пересечение интервалов: " << endl;
            inter1.interSection(inter2, A);

            // вывод пересечения интервалов
            N = findNumbersN(A, N);
            inter1.printSection(A, N);
            cout << endl;

            // освобождение памяти
            clearA(A);

            // операция объединения интервалов
            inter1.interUnion(inter2, A);

            // освобождение памяти
            clearA(A);

            // вывод объединения интервалов
            cout << "объединение интервалов: " << endl;
            inter1.printUnion(inter1, inter2, A);

            // освобождение памяти
            clearA(A);
        }
        else if (command == 2)
            break;
        else
            cout << "Ошибка! Не могу найти такой команды! Попробуйте еще раз!" << endl;
    }
    return 0;
}


