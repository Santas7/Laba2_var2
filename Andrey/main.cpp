#include <iostream>
#include <windows.h>

using namespace std;

class WorkInterval {
private:
    double _left, _right;
    bool _statusR, _statusL;
public:

    bool statusCheck(WorkInterval inter2) const
    {
        bool status;
        if (inter2._left > _right && inter2._right > _right)
            status = true;
        else
            status = false;
        return status;
    }

    WorkInterval interUnion(WorkInterval inter2) const
    {
        WorkInterval ans;
        if (_left > inter2._right && _right > inter2._left) { // проверка на объединение интервалов
            ans._right = 0;
            ans._left = 0;
            ans._statusR = false;
            ans._statusL = false;
            return ans;
        }
        //for left
        if (_left > inter2._left) {
            ans._left = inter2._left;
            ans._statusL = inter2._statusL;
        }
        else if (_left < inter2._left) {
            ans._left = _left;
            ans._statusL = _statusL;
        }
        else {
            ans._left = _left;
            ans._statusL = _statusL || inter2._statusL; // true || false = true
        }
        //for right
        if (_right > inter2._right) {   
            ans._right = _right;
            ans._statusR = _statusR;
        }
        else if (_right < inter2._right) {
            ans._right = inter2._right;
            ans._statusR = inter2._statusR;
        }
        else {
            ans._right = _right;
            ans._statusR = _statusR || inter2._statusR; // true || false = true
        }
      
        return ans;
    }

    WorkInterval interSection(WorkInterval inter2, WorkInterval ans) const
    {
        if (_left > inter2._right && inter2._left > _right) { // проверка на пересечение интервалов
            ans._left = 0;
            ans._right = 0;
            ans._statusL = false;
            ans._statusR = false;
            return ans;
        }
            // for left
        if (_left > inter2._left) {
            ans._left = _left;
            ans._statusL = _statusL;
        }
        else if (_left < inter2._left) {
            ans._left = inter2._left;
            ans._statusL = inter2._statusL;
        }
        else {
            ans._left = _left;
            ans._statusL = _statusL && inter2._statusL; // bool1 and bool2 = ?
        }
            // for right
        if (_right > inter2._right) {
            ans._right = inter2._right;
            ans._statusR = inter2._statusR;
        }
        else if (_right < inter2._right) {
            ans._right = _right;
            ans._statusR = _statusR;
        }
        else {
            ans._right = _right;
            ans._statusR = _statusR && inter2._statusR; // bool1 and bool2 = ?
        }
        return ans;
    }
    void print() const
    {
        if (!_statusL)
            cout << "(";
        else
            cout << "[";
        cout << _left << ";" << _right;
        if (!_statusR)
            cout << ")" << endl;
        else
            cout << "]" << endl;
    }
    void setLeft(double value) { _left = value; }
    double getLeft(double _left) { return _left; }
    void setRight(double value) { _right = value; }
    double getRight(double _right) { return _right; }
    void setR(bool value) { _statusR = value; }
    void setL(bool value) { _statusL = value; }
    explicit WorkInterval(double left = 0, double right = 0, bool statusL = false, bool statusR = false)
        : _left(left), _right(right), _statusL(statusL), _statusR(statusR)// конструктор
    {
    }
};

//behind class

double inputLeftInterval() // ввод левого конца интервала
{
    double left;
    cin >> left;
    return left;
}
double inputRightInterval(double left) // ввод правого конца интервала
{
    double right;
    while (true)
    {
        cin >> right;
        cout << endl;
        if (right < left)
        {
            cout << "Левый конец должен быть < правого конца!" << endl << "правый конец интервала: ";
        }
        else
            break;
    }
    return right;
}
bool statusLeft()
{
    bool status;
    char str[1] = "";
    while (true) {
        cout << "левая скобка: ";
        cin >> str[0];
        if (str[0] == '(') {
            status = false;
            break;
        }
        else if (str[0] == '[') {
            status = true;
            break;
        }
        else
            cout << "Вы ввели неверный символ! Повторите еще разок!" << endl;
    }
    return status;
}
bool statusRight()
{
    bool status;
    char str[1] = "";
    while (true) {
        cout << "правая скобка: ";
        cin >> str[0];
        if (str[0] == ')') {
            status = false;
            break;
        }
        else if (str[0] == ']') {
            status = true;
            break;
        }
        else
            cout << "Вы ввели неверный символ! Повторите еще разок!";
    }
    return status;
}
int main()
{
    setlocale(LC_ALL, "Rus");
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
            bool status;
            WorkInterval inter1;
            WorkInterval inter2;
            WorkInterval ans;

            // ввод первого интервала
            cout << "1 интервал-->" << endl;
            status = statusLeft();
            inter1.setL(status);
            cout << "левый конец интервала: ";
            left = inputLeftInterval();
            cout << "правый конец интервала: ";
            right = inputRightInterval(left);
            status = statusRight();
            inter1.setR(status);
            inter1.setLeft(left);
            inter1.setRight(right);

            // ввод второго интервала
            cout << "2 интервал-->" << endl;
            status = statusLeft();
            inter2.setL(status);
            cout << "левый конец интервала: ";
            left = inputLeftInterval();
            cout << "правый конец интервала: ";
            right = inputRightInterval(left);
            status = statusRight();
            inter2.setR(status);
            inter2.setLeft(left);
            inter2.setRight(right);

            // вывод интервалов
            inter1.print();
            inter2.print();

            // операция пересечения
            ans = inter1.interSection(inter2, ans);

            // вывод пересечения
            cout << "пересечение интервалов: " << endl;
            ans.print();
            cout << endl;

            // операция объединения
            ans = inter1.interUnion(inter2);

            // вывод объединения
            status = inter1.statusCheck(inter2);
            cout << "объединение интервалов: " << endl;
            if (status != 1) {
                ans.print();
                status = false;
            }
            else {
                cout << "(0;0)" << endl;
                status = false;
            }
        }
        else if (command == 2)
            break;
        else
            cout << "Ошибка! Не могу найти такой команды! Попробуйте еще раз!";
    }
    return 0;
}
