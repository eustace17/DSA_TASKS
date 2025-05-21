/*
These Features make the code array based as per the question:
Student students[MAX] -> An array of students is used to hold the data
int size -> Keeps track of how many students are in the array
Index-based access->Students are accessed and inserted using students[i], students[pos] for example
The array has a fixed size it has a maximum capacity (MAX_STUDENTS)*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STUDENTS 100 //Array used

//Struct for Course
typedef struct {
    char course_name[50];
    char course_id[10];
} Course;

//Grade struct
typedef struct {
    int marks;
    char letter_grade;
} Grade;

//Student Struct
typedef struct {
    char name[50];
    char regNo[20];
    int age;
    Course course;
    Grade grade;
} Student;

//An array based stack for the list of students
typedef struct {
    int size;
    Student students[MAX_STUDENTS];
} StudentList;

//methods for students
void set_name(Student *s, char name[]) {
    strcpy(s->name, name);
}
void set_regNo(Student *s, char regNo[]) {
    strcpy(s->regNo, regNo);
}
void set_age(Student *s, int age) {
    s->age = age;
}
void set_course(Student *s, Course c) {
    s->course = c;
}
void set_marks(Student *s, int marks) {
    s->grade.marks = marks;
}
void calculate_grade(Student *s) {
    int m = s->grade.marks;
    if (m >= 70) s->grade.letter_grade = 'A';
    else if (m >= 60) s->grade.letter_grade = 'B';
    else if (m >= 50) s->grade.letter_grade = 'C';
    else if (m >= 40) s->grade.letter_grade = 'D';
    else s->grade.letter_grade = 'F';
}

//Operations for list as per question
StudentList create_empty_list() {
    StudentList list;
    list.size = 0;
    return list;
}

StudentList create_list_with_one(Student s) {
    StudentList list;
    list.size = 1;
    list.students[0] = s;
    return list;
}

StudentList create_list_from_existing(StudentList *other) {
    StudentList newList;
    newList.size = other->size;
    for (int i = 0; i < other->size; i++) {
        newList.students[i] = other->students[i];
    }
    return newList;
}

void add_student(StudentList *list, Student s) {
    if (list->size >= MAX_STUDENTS) {
        printf("List full! Cannot add more students.\n");
        return;
    }
    list->students[list->size++] = s;
}

void add_student_at(StudentList *list, Student s, int pos) {
    if (list->size >= MAX_STUDENTS || pos < 0 || pos > list->size) return;
    for (int i = list->size; i > pos; i--) {
        list->students[i] = list->students[i - 1];
    }
    list->students[pos] = s;
    list->size++;
}

void remove_student(StudentList *list, char regNo[]) {
    for (int i = 0; i < list->size; i++) {
        if (strcmp(list->students[i].regNo, regNo) == 0) {
            for (int j = i; j < list->size - 1; j++) {
                list->students[j] = list->students[j + 1];
            }
            list->size--;
            return;
        }
    }
}

void remove_student_at(StudentList *list, int pos) {
    if (pos < 0 || pos >= list->size) return;
    for (int i = pos; i < list->size - 1; i++) {
        list->students[i] = list->students[i + 1];
    }
    list->size--;
}

int get_size(StudentList *list) {
    return list->size;
}

void destroy_list(StudentList *list) {
    list->size = 0;
}

//Client Code
int main() {
    Course cs = {"Computer Science", "CS101"};
    Course ct = {"Computer Technology", "CT102"};

    StudentList list = create_empty_list();

    for (int i = 0; i < 15; i++) {
        Student s;
        char name[50];
        sprintf(name, "Student%d", i + 1);
        set_name(&s, name);
        set_regNo(&s, name);  // Simplified regNo same as name
        set_age(&s, 18 + (i % 5));
        set_course(&s, (i % 2 == 0) ? cs : ct);
        set_marks(&s, 50 + (i * 3) % 50);
        calculate_grade(&s);
        add_student(&list, s);
    }

    printf("List contains %d students.\n", get_size(&list));
    for (int i = 0; i < list.size; i++) {
        Student s = list.students[i];
        printf("%s | %s | %d | %s | Marks: %d | Grade: %c\n",
               s.name, s.regNo, s.age, s.course.course_name,
               s.grade.marks, s.grade.letter_grade);
    }

    return 0;
}
