#include <iostream>
#include <string>
using namespace std;


// PART A: Question 2
// Defining the Grade ADT
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
        mark = 0;
        the_grade = '-';
        is_final = false;
    }

    void set_mark(int m) {
        if (!is_final) {
            mark = m;
            the_grade = computeGrade(m);
            is_final = true;
        } else {
            cout << "Grade already finalized. Cannot modify.\n";
        }
    }

    int get_mark() const { return mark; }
    char get_grade() const { return the_grade; }
    bool isFinalized() const { return is_final; }
};


//Question 2 Defining the Course ADT
class Course {
private:
    string course_code;
    string course_name;

public:
    Course() : course_code(""), course_name("") {}

    void set_course(string code, string name) {
        course_code = code;
        course_name = name;
    }

    string get_course_code() const { return course_code; }
    string get_course_name() const { return course_name; }
};

-
// Question 2 + 3 Defining the Student ADT
class Student {
private:
    string reg_no;
    string name;
    int age;
    Course course;
    Grade grade;

public:
    Student() : reg_no(""), name(""), age(0) {}

    Student(string reg, string n, int a) : reg_no(reg), name(n), age(a) {}

    void set_regNo(string reg) { reg_no = reg; }
    string get_regNo() const { return reg_no; }

    void set_name(string n) { name = n; }
    string get_name() const { return name; }

    void set_age(int a) { age = a; }
    int get_age() const { return age; }

    void set_course(Course c) { course = c; }
    Course get_course() const { return course; }

    void set_grade(Grade g) { grade = g; }
    Grade get_grade() const { return grade; }

    void set_marks(int mark) { grade.set_mark(mark); }

    void display() {
        cout << "Reg No: " << reg_no << ", Name: " << name << ", Age: " << age << endl;
        cout << "Course: " << course.get_course_code() << " - " << course.get_course_name() << endl;
        if (grade.isFinalized()) {
            cout << "Mark: " << grade.get_mark() << ", Grade: " << grade.get_grade() << endl;
        } else {
            cout << "Grade not yet set.\n";
        }
    }
};


//Question 1 about Defining the Array-Based List class for Students
class List {
private:
    static const int MAX = 40;
    Student students[MAX];
    int size;

public:
    // Constructor 1: Empty list
    List() { size = 0; }

    // Constructor 2: List with one student
    List(Student s) {
        students[0] = s;
        size = 1;
    }

    // Constructor 3: Copy from existing list
    List(const List& other) {
        size = other.size;
        for (int i = 0; i < size; i++) {
            students[i] = other.students[i];
        }
    }

    // Add student at end
    void add(Student s) {
        if (size >= MAX) {
            cout << "List full.\n";
            return;
        }
        students[size++] = s;
    }

    // Add student at position
    void addAt(Student s, int pos) {
        if (pos < 0 || pos > size || size >= MAX) {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = size; i > pos; i--) {
            students[i] = students[i - 1];
        }
        students[pos] = s;
        size++;
    }

    // Remove student by reg_no
    void remove(Student s) {
        for (int i = 0; i < size; i++) {
            if (students[i].get_regNo() == s.get_regNo()) {
                for (int j = i; j < size - 1; j++) {
                    students[j] = students[j + 1];
                }
                size--;
                return;
            }
        }
        cout << "Student not found.\n";
    }

    // Remove by position
    void removeAt(int pos) {
        if (pos < 0 || pos >= size) {
            cout << "Invalid position.\n";
            return;
        }
        for (int i = pos; i < size - 1; i++) {
            students[i] = students[i + 1];
        }
        size--;
    }

    // Get current size
    int getSize() const { return size; }

    // Destroy the list
    void destroy() {
        size = 0;
        cout << "List destroyed.\n";
    }

    // Display all students
    void displayAll() {
        for (int i = 0; i < size; i++) {
            cout << "\nStudent " << i + 1 << ":\n";
            students[i].display();
        }
    }

    // Access a student by index used in the main
    Student& getStudent(int index) {
        return students[index];
    }
};


//Question 4 the Client code
int main() {
    List studentList;

    for (int i = 0; i < 15; i++) {
        string reg = "S" + to_string(100 + i);
        string name = "Student" + to_string(i + 1);
        int age = 18 + (i % 5);

        Student s(reg, name, age);

        Course c;
        c.set_course("ICS210" + to_string(i % 5), "Course" + to_string(i % 5));
        s.set_course(c);

        studentList.add(s);
    }

    // Set marks for each student and calculate grades
    for (int i = 0; i < studentList.getSize(); i++) {
        int mark = 50 + (i % 40); // Sample marks from 50 to 89
        studentList.getStudent(i).set_marks(mark);
    }

    // Display all student data
    studentList.displayAll();

    return 0;
}
