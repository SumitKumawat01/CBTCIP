#include <iostream>
#include <vector>
#include <limits>

using namespace std;

class Student {
public:
    int id;
    string name;
    int age;
    string course;

    Student(int id, string name, int age, string course) {
        this->id = id;
        this->name = name;
        this->age = age;
        this->course = course;
    }
};

vector<Student> students;

void displayMenu();
void addStudent();
void displayStudents();
void deleteStudent();
void clearInput();

int main() {
    bool keepRunning = true;
    char choice;

    while (keepRunning) {
        displayMenu();
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case '1':
                addStudent();
                break;
            case '2':
                displayStudents();
                break;
            case '3':
                deleteStudent();
                break;
            case 'q':
                keepRunning = false;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        clearInput();
    }

    cout << "Exiting the program." << endl;
    return 0;
}

void displayMenu() {
    cout << "\nStudent Record Management System" << endl;
    cout << "================================" << endl;
    cout << "1. Add Student" << endl;
    cout << "2. Display Students" << endl;
    cout << "3. Delete Student" << endl;
    cout << "q. Quit" << endl;
    cout << "================================" << endl;
}

void addStudent() {
    int id, age;
    string name, course;

    cout << "Enter student ID: ";
    cin >> id;
    cout << "Enter student name: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, name);
    cout << "Enter student age: ";
    cin >> age;
    cout << "Enter student course: ";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    getline(cin, course);

    students.push_back(Student(id, name, age, course));
    cout << "Student added successfully!" << endl;
}

void displayStudents() {
    if (students.empty()) {
        cout << "No student records found." << endl;
    } else {
    for (const auto& student : students) {
        cout << "\nID: " << student.id << endl;
        cout << "Name: " << student.name << endl;
        cout << "Age: " << student.age << endl;
    	cout << "Course: " << student.course << endl;
        }
    }
}

void deleteStudent() {
    int id;
    cout << "Enter student ID to delete: ";
    cin >> id;

    for (auto it = students.begin(); it != students.end(); ++it) {
        if (it->id == id) {
            students.erase(it);
            cout << "Student record deleted successfully!" << endl;
            return;
        }
    }

    cout << "Student ID not found." << endl;
}

void clearInput() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}
