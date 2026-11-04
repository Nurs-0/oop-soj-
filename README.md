
# Student Management System (C++)

## Project Description
This project is a simple Student Management System developed using C++.
The program stores student information and displays it on the screen.

## Project Files
- Student.h — contains class declarations.
- Student.cpp — contains class constructors and methods.
- main.cpp — contains the main program.
- README.md — project description.
- UML_Diagram.puml — UML class diagram.

## Object-Oriented Programming Concepts

The project demonstrates the following concepts:

1. **Static Data Member and Static Method**
   - static int count
   - static int getCount()

2. **Friend Class and Friend Function**
   - friend class Group
   - friend void showPrivate()

3. **Nested Class**
   - Info class inside Group.

4. **Object Array**
   - Student students[2]

5. **Composition and Aggregation**
   - Composition: Info info inside Group.
   - Aggregation: Student* students.

6. **Encapsulation**
   - private, protected and public access modifiers.

7. **Inheritance**
   - Student class inherits from Person class.

## Compilation

To compile the project using g++:

```bash
g++ -std=c++17 main.cpp Student.cpp -o StudentProject
```

## Run the Program

Windows:
```bash
StudentProject.exe
```

Linux / macOS:
```bash
./StudentProject
```

## Author Information

- **Name:** [Write your full name]
- **Group:** [Write your group]
- **Subject:** Object-Oriented Programming-1
- **Programming Language:** C++
