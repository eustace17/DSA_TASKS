
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Struct for Courses
typedef struct {
    char course_name[50];
    char course_id[10];
} Course;

//Struct for Grades
typedef struct {
    int marks;
    char letter_grade;
} Grade;

//Struct for Students
typedef struct {
    char name[50];
    char regNo[20];
    int age;
    Course course;
    Grade grade;
} Student;

//Struct for student Node
typedef struct StudentNode {
    Student data;
    struct StudentNode *next;
} StudentNode;

//Head of the Linked List
typedef struct {
    StudentNode *head;
    int size;
} StudentList;

//Setters and getters and calculating grades for students
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

//Specified question operations for the linked List
StudentList create_linked_list() {
    StudentList list;
    list.head = NULL;
    list.size = 0;
    return list;
}

void add_student_end(StudentList *list, Student s) {
    StudentNode *newNode = (StudentNode *)malloc(sizeof(StudentNode));
    newNode->data = s;
    newNode->next = NULL;
    if (list->head == NULL) {
        list->head = newNode;
    } else {
        StudentNode *current = list->head;
        while (current->next != NULL)
            current = current->next;
        current->next = newNode;
    }
    list->size++;
}

void remove_student_by_regNo(StudentList *list, char regNo[]) {
    StudentNode *current = list->head;
    StudentNode *previous = NULL;

    while (current != NULL && strcmp(current->data.regNo, regNo) != 0) {
        previous = current;
        current = current->next;
    }

    if (current == NULL) return;  // Not found

    if (previous == NULL) {
        list->head = current->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    list->size--;
}

int get_list_size(StudentList *list) {
    return list->size;
}

void destroy_list(StudentList *list) {
    StudentNode *current = list->head;
    while (current != NULL) {
        StudentNode *next = current->next;
        free(current);
        current = next;
    }
    list->head = NULL;
    list->size = 0;
}

//print
void print_students(StudentList *list) {
    StudentNode *current = list->head;
    while (current != NULL) {
        Student s = current->data;
        printf("%s | %s | %d | %s | Marks: %d | Grade: %c\n",
               s.name, s.regNo, s.age, s.course.course_name,
               s.grade.marks, s.grade.letter_grade);
        current = current->next;
    }
}

//Client code
int main() {
    Course cs = {"Computer Science", "CS101"};
    Course ct = {"Computer Technology", "CT102"};

    StudentList list = create_linked_list();

    for (int i = 0; i < 15; i++) {
        Student s;
        char name[50];
        sprintf(name, "Student%d", i + 1);

        set_name(&s, name);
        set_regNo(&s, name);
        set_age(&s, 18 + (i % 5));
        set_course(&s, (i % 2 == 0) ? cs : ct);
        set_marks(&s, 50 + (i * 3) % 50);
        calculate_grade(&s);
        add_student_end(&list, s);
    }

    printf("Linked List contains %d students.\n", get_list_size(&list));
    print_students(&list);

    destroy_list(&list);
    return 0;
}
