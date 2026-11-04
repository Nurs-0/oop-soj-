
#include <iostream>
#include "Student.h"
using namespace std;

int main() {

    // 1. Объектілер массивін құру
    Student students[2] = {
        Student("Asem", 20, 101),
        Student("Aliya", 19, 102)
    };

    // 2. Aggregation
    Group group(students, 2);

    // 3. Студенттер туралы ақпаратты шығару
    group.showGroup();

    // 4. Static әдісті шақыру
    cout << "\nСтуденттер саны: "
         << Student::getCount() << endl;

    // 5. Friend функцияны шақыру
    showPrivate(students[0]);

    return 0;
}
