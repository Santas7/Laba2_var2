/** Документация к программе
	ФИО: Панюшкин Андрей Михайлович
	номер группы: 6113
	вариант: 17(2)
**/
#include <windows.h>
#include <iostream>

using namespace std;

class WorkInterval{
private:
    double left{}, right{};
public:
    void printOperations() const
    {
        cout << "(" << left << ";" << right << ")";
    }
	
    int statusCheck(int status,WorkInterval inter2) const
    {
        if(inter2.left > right && inter2.right > right) status = 1;
        return status;
    }
	
    WorkInterval interUnion(WorkInterval inter2, WorkInterval ans) const
    {
        if(right < inter2.right && right > inter2.left && left < inter2.left){
            ans.left = left;
            ans.right = inter2.right;
        }
        else if(right < inter2.right && left > inter2.left){
            ans.left = inter2.left;
            ans.right = right;
        }
        else if (right > inter2.right && left > inter2.left) {
            ans.left = inter2.left;
            ans.right = right;
        }
        else if(right > inter2.right && inter2.left > left){
            ans.left = left;
            ans.right = right;
        }
        return ans;
    }
	
    WorkInterval interSection(WorkInterval inter2, WorkInterval ans) const
    {
        if(right < inter2.right && right > inter2.left && left < inter2.left){
                ans.left = inter2.left;
                ans.right = right;
        }
        else if(right < inter2.right && left > inter2.left){
            ans.left = left;
            ans.right = right;
        }
        else if (right > inter2.right && left > inter2.left) {
            ans.left = left;
            ans.right = inter2.right;
        }
        else if(right > inter2.right && inter2.left > left){
            ans.left = inter2.left;
            ans.right = inter2.right;
        }
        else {
            ans.left=0;
            ans.right=0;
        }
        return ans;
    }
	
    void print() const
    {
        cout << "(" << left << ";" << right << ")" << endl;
    }
	
    void setLeft(double l){left = l;}
    static double getLeft(double left){return left;}
    void setRight(double r){right = r;}
    static double getRight(double right){return right;}

    explicit WorkInterval(double left = 0, double right = 0) // конструктор
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
    SetConsoleOutputCP(CP_UTF8); //Задает выходную кодовую страницу,
    cout << "|____________________________________________________|" << endl;
    cout << "|     Лабораторная работа номер 2 ( 17 вариант(2) )  |" << endl;
    cout << "|____________________________________________________|" << endl;
    while (true) // главное меню
    {
        cout << "\nВведите 1 для запуска и 2 для выхода: ";
        int command;
        cin >> command;
        if (command == 1)
        {
            double left = 0, right = 0;
            int status;
            WorkInterval inter1;
            WorkInterval inter2;
            WorkInterval ans;
		
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
		
            // операция пересечения
            ans = inter1.interSection(inter2, ans);
		
            // вывод пересечения
            cout << "пересечение интервалов: " << endl;
            ans.printOperations();
            cout << endl;
		
            // операция объединения
            ans = inter1.interUnion(inter2, ans);
		
            // вывод объединения
            status = inter1.statusCheck(status, inter2);
            cout << "объединение интервалов: " << endl;
            if(status != 1){
                ans.printOperations();
                status = 0;
            }
            else{
                inter1.printOperations();
                cout << "\t" << "U" << "\t";
                inter2.printOperations();
                status = 0;
            }
        }
        else if (command == 2)
            break;
        else
            cout << "Ошибка! Не могу найти такой команды! Попробуйте еще раз!" << endl;
    }
    return 0;
}
