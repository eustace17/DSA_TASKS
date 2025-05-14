#include <stdio.h>
#include <string.h>
//Tuesday after CAT whiteboard guideline
struct Course {
    char course_code[20];
    char course_name[50];
};

struct Grade {
    int mark;
    char the_grade;
    int is_final;  // 0 means it is not set, 1 means it is locked
};

struct Student {
    char reg_no[21];
    char name[51];
    int age;
    struct Course course;
    struct Grade grade;
};

#define MAX_STUDENTS 40
struct Student students[MAX_STUDENTS];
int student_count = 0;

//computing grade function
char computeGrade(int mark) {
    if (mark > 69) return 'A';
    else if (mark > 59) return 'B';
    else if (mark > 49) return 'C';
    else if (mark > 39) return 'D';
    else return 'E';
}

// add a student function
void addStudent() {
    if (student_count >= MAX_STUDENTS) {
        printf("Cannot add more students.\n");
        return;
    }

    struct Student s;

    printf("Enter registration number: ");
    scanf(" %20s", s.reg_no);

    printf("Enter name: ");
    scanf(" %50[^\n]", s.name);

    printf("Enter age: ");
    scanf("%d", &s.age);

    printf("Enter course code: ");
    scanf(" %19s", s.course.course_code);

    printf("Enter course name: ");
    scanf(" %49[^\n]", s.course.course_name);

    s.grade.is_final = 0;  // grade not yet set

    students[student_count++] = s;
    printf("Student added successfully!\n");
}

// function to edit student
void editStudent() {
    char reg[21];
    printf("Enter registration number of student to edit: ");
    scanf(" %20s", reg);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].reg_no, reg) == 0) {
            printf("Editing %s:\n", students[i].name);

            printf("Enter new name: ");
            scanf(" %50[^\n]", students[i].name);

            printf("Enter new age: ");
            scanf("%d", &students[i].age);

            printf("Enter new course code: ");
            scanf(" %19s", students[i].course.course_code);

            printf("Enter new course name: ");
            scanf(" %49[^\n]", students[i].course.course_name);

            printf("Student info updated.\n");
            return;
        }
    }

    printf("Student not found.\n");
}

//enter the marks and calculate the grade
void enterMarks() {
    char reg[21];
    printf("Enter registration number of student to enter marks for: ");
    scanf(" %20s", reg);

    for (int i = 0; i < student_count; i++) {
        if (strcmp(students[i].reg_no, reg) == 0) {
            if (students[i].grade.is_final) {
                printf("Grade already set. Cannot modify.\n");
                return;
            }

            int mark;
            printf("Enter mark (0-100): ");
            scanf("%d", &mark);

            students[i].grade.mark = mark;
            students[i].grade.the_grade = computeGrade(mark);
            students[i].grade.is_final = 1;  // lock the grade

            printf("Mark and grade set. Grade: %c\n", students[i].grade.the_grade);
            return;
        }
    }

    printf("Student not found.\n");
}

//the display function
void displayAll() {
    if (student_count == 0) {
        printf("No students available.\n");
        return;
    }

    for (int i = 0; i < student_count; i++) {
        struct Student s = students[i];
        printf("\n--- Student %d ---\n", i + 1);
        printf("Reg No: %s\n", s.reg_no);
        printf("Name: %s\n", s.name);
        printf("Age: %d\n", s.age);
        printf("Course Code: %s\n", s.course.course_code);
        printf("Course Name: %s\n", s.course.course_name);

        if (s.grade.is_final) {
            printf("Mark: %d\n", s.grade.mark);
            printf("Grade: %c\n", s.grade.the_grade);
        } else {
            printf("Grade not yet set.\n");
        }
    }
}


int main() {
    int choice;

    do {
        printf("\n--- STUDENT RECORD SYSTEM ---\n");
        printf("1. Add Student\n");
        printf("2. Edit Student\n");
        printf("3. Enter Marks & Compute Grade\n");
        printf("4. Display All Students\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: editStudent(); break;
            case 3: enterMarks(); break;
            case 4: displayAll(); break;
            case 5: printf("Goodbye!\n"); break;
            default: printf("Invalid option.\n");
        }

    } while (choice != 5);

    return 0;
}
