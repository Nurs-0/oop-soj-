
#ifndef STUDENT_H
#define STUDENT_H

#include <iostream>
#include <string>
using namespace std;

// Негізгі класс
class Person {
protected:
    string name;
    int age;

public:
    Person(string n, int a);
};

// Туынды класс
class Student : public Person {
private:
    int id;
    static int count;

public:
    Student(string n, int a, int i);

    void showInfo() const;

    // Static әдіс
    static int getCount();

    // Friend class және friend function
    friend class Group;
    friend void showPrivate(const Student& s);
};

// Студенттер тобының класы
class Group {
private:
    Student* students; // Aggregation
    int size;

    // Nested class
    class Info {
    public:
        void show() const;
    };

    Info info; // Composition

public:
    Group(Student arr[], int n);
    void showGroup() const;
};

#endif
