#include <iostream>
#include <string>
//Used OOP Class concept instead of using structs
using namespace std;

class Course {
public:
    string course_code;
    string course_name;

    void inputCourse() {
        cout << "Enter course code: ";
        getline(cin, course_code);
        cout << "Enter course name: ";
        getline(cin, course_name);
    }
};

class Grade {
private:
    int mark;
    char the_grade;
    bool is_final;

    char computeGrade(int m) {
        if (m > 69) return 'A';
        else if (m > 59) return 'B';
        else if (m > 49) return 'C';
        else if (m > 39) return 'D';
        else return 'E';
    }

public:
    Grade() {
        is_final = false;
        mark = 0;
        the_grade = '-';
    }

    void enterMark() {
        if (is_final) {
            cout << "Grade already finalized. Cannot modify.\n";
            return;
        }

        cout << "Enter mark (0 - 100): ";
        cin >> mark;
        the_grade = computeGrade(mark);
        is_final = true;
        cout << "Grade set to: " << the_grade << "\n";
    }

    void display() {
        if (is_final) {
            cout << "Mark: " << mark << ", Grade: " << the_grade << "\n";
        } else {
            cout << "Grade not yet set.\n";
        }
    }
};

class Student {
private:
    string reg_no;
    string name;
    int age;
    Course course;
    Grade grade;

public:
    void addStudent() {
        cout << "Enter registration number: ";
        cin.ignore();
        getline(cin, reg_no);
        cout << "Enter name: ";
        getline(cin, name);
        cout << "Enter age: ";
        cin >> age;
        cin.ignore();
        course.inputCourse();
    }

    void editStudent() {
        cout << "Editing " << reg_no << " - " << name << ":\n";
        cout << "Enter new name: ";
        getline(cin, name);
        cout << "Enter new age: ";
        cin >> age;
        cin.ignore();
        course.inputCourse();
    }

    void addMark() {
        grade.enterMark();
    }

    string getRegNo() {
        return reg_no;
    }

    void display() {
        cout << "\n--- Student Info ---\n";
        cout << "Reg No: " << reg_no << "\n";
        cout << "Name: " << name << "\n";
        cout << "Age: " << age << "\n";
        cout << "Course Code: " << course.course_code << "\n";
        cout << "Course Name: " << course.course_name << "\n";
        grade.display();
    }
};

const int MAX_STUDENTS = 40;
Student students[MAX_STUDENTS];
int student_count = 0;

void menu() {
    int choice;
    string searchReg;

    do {
        cout << "\n--- STUDENT SYSTEM MENU ---\n";
        cout << "1. Add Student\n";
        cout << "2. Edit Student\n";
        cout << "3. Enter Marks\n";
        cout << "4. Display All Students\n";
        cout << "5. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            if (student_count < MAX_STUDENTS) {
                students[student_count++].addStudent();
            } else {
                cout << "Maximum student limit reached.\n";
            }
            break;

        case 2:
            cout << "Enter reg number to edit: ";
            cin.ignore();
            getline(cin, searchReg);
            for (int i = 0; i < student_count; i++) {
                if (students[i].getRegNo() == searchReg) {
                    students[i].editStudent();
                    break;
                }
                if (i == student_count - 1) cout << "Student not found.\n";
            }
            break;

        case 3:
            cout << "Enter reg number to enter mark: ";
            cin.ignore();
            getline(cin, searchReg);
            for (int i = 0; i < student_count; i++) {
                if (students[i].getRegNo() == searchReg) {
                    students[i].addMark();
                    break;
                }
                if (i == student_count - 1) cout << "Student not found.\n";
            }
            break;

        case 4:
            if (student_count == 0) {
                cout << "No students added yet.\n";
            }
            for (int i = 0; i < student_count; i++) {
                students[i].display();
            }
            break;

        case 5:
            cout << "Goodbye!\n";
            break;

        default:
            cout << "Invalid option.\n";
        }

    } while (choice != 5);
}

int main() {
    menu();
    return 0;
}
