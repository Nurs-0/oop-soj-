
#include "Student.h"

// Static айнымалыны инициализациялау
int Student::count = 0;

// Person конструкторы
Person::Person(string n, int a) {
    name = n;
    age = a;
}

// Student конструкторы
Student::Student(string n, int a, int i)
    : Person(n, a) {
    id = i;
    count++;
}

// Студент туралы ақпаратты шығару
void Student::showInfo() const {
    cout << "Аты: " << name << endl;
    cout << "Жасы: " << age << endl;
    cout << "ID: " << id << endl;
}

// Static әдіс
int Student::getCount() {
    return count;
}

// Friend функция
void showPrivate(const Student& s) {
    cout << "Жеке ID: " << s.id << endl;
}

// Group конструкторы
Group::Group(Student arr[], int n) {
    students = arr;
    size = n;
}

// Nested class әдісі
void Group::Info::show() const {
    cout << "Топ: TMRP 23-11" << endl;
}

// Топтағы студенттерді көрсету
void Group::showGroup() const {
    info.show();

    for (int i = 0; i < size; i++) {
        cout << "\nСтудент " << i + 1 << ":" << endl;
        students[i].showInfo();
    }
}
