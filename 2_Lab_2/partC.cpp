//Implementing Lab 2 Part B using  OOP concepts
#include <iostream>
#include <string>
using namespace std;

//Course Class
class Course {
public:
    string course_name;
    string course_id;

    Course() {}
    Course(string name, string id) : course_name(name), course_id(id) {}
};

//Grade Class
class Grade {
public:
    int marks;
    char letter_grade;

    Grade() : marks(0), letter_grade('F') {}
};

//Student Class
class Student {
private:
    string name;
    string regNo;
    int age;
    Course course;
    Grade grade;

public:
    Student() {}
    Student(string n, string r, int a, Course c, int m) {
        name = n;
        regNo = r;
        age = a;
        course = c;
        set_marks(m);
        calculate_grade();
    }

    void set_name(string n) { name = n; }
    void set_regNo(string r) { regNo = r; }
    void set_age(int a) { age = a; }
    void set_course(Course c) { course = c; }
    void set_marks(int m) { grade.marks = m; }
    void set_grade(char g) { grade.letter_grade = g; }

    string get_name() { return name; }
    string get_regNo() { return regNo; }
    int get_age() { return age; }
    Course get_course() { return course; }
    Grade get_grade() { return grade; }

    void calculate_grade() {
        int m = grade.marks;
        if (m >= 70) grade.letter_grade = 'A';
        else if (m >= 60) grade.letter_grade = 'B';
        else if (m >= 50) grade.letter_grade = 'C';
        else if (m >= 40) grade.letter_grade = 'D';
        else grade.letter_grade = 'F';
    }

    void display() {
        cout << name << " | " << regNo << " | " << age << " | "
             << course.course_name << " | Marks: " << grade.marks
             << " | Grade: " << grade.letter_grade << endl;
    }
};

//Class for our Node in Part B
class Node {
public:
    Student data;
    Node* next;

    Node(Student s) {
        data = s;
        next = nullptr;
    }
};

//Linked List Class
class StudentList {
private:
    Node* head;
    int size;

public:
    StudentList() {
        head = nullptr;
        size = 0;
    }

    void add(Student s) {
        Node* newNode = new Node(s);
        if (!head) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next)
                current = current->next;
            current->next = newNode;
        }
        size++;
    }

    void remove(string regNo) {
        Node* current = head;
        Node* prev = nullptr;
        while (current && current->data.get_regNo() != regNo) {
            prev = current;
            current = current->next;
        }

        if (!current) return;

        if (!prev) {
            head = current->next;
        } else {
            prev->next = current->next;
        }

        delete current;
        size--;
    }

    void display_all() {
        Node* current = head;
        while (current) {
            current->data.display();
            current = current->next;
        }
    }

    int get_size() {
        return size;
    }

    void destroy() {
        Node* current = head;
        while (current) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    ~StudentList() {
        destroy();
    }
};

//Client code
int main() {
    Course cs("Computer Science", "CS101");
    Course ct("Computer Technology", "CT102");

    StudentList list;

    for (int i = 0; i < 15; i++) {
        string name = "Student" + to_string(i + 1);
        string reg = "REG" + to_string(i + 1);
        int age = 18 + (i % 5);
        Course c = (i % 2 == 0) ? cs : ct;
        int marks = 50 + (i * 3) % 50;

        Student s(name, reg, age, c, marks);
        list.add(s);
    }

    cout << "Student List (" << list.get_size() << " students):" << endl;
    list.display_all();

    return 0;
}
