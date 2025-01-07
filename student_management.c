#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100

struct Student {
    int rollno;
    char name[50];
    float marks;
};

struct Student students[MAX_STUDENTS];
int num_students = 0;

void addStudent() {
    if (num_students == MAX_STUDENTS) {
        printf("Maximum number of students reached.\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &students[num_students].rollno);

    printf("Enter Name: ");
    scanf(" %[^\n]", students[num_students].name); // Read full name

    printf("Enter Marks: ");
    scanf("%f", &students[num_students].marks);

    num_students++;
    printf("Student added successfully.\n");
}

void displayStudents() {
    if (num_students == 0) {
        printf("No students found.\n");
        return;
    }

    printf("------------------------------------\n");
    printf("Roll No\tName\t\tMarks\n");
    printf("------------------------------------\n");

    for (int i = 0; i < num_students; i++) {
        printf("%d\t%s\t\t%.2f\n", students[i].rollno, students[i].name, students[i].marks);
    }

    printf("------------------------------------\n");
}

void searchStudent() {
    int rollno;
    printf("Enter Roll No to search: ");
    scanf("%d", &rollno);

    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (students[i].rollno == rollno) {
            printf("Student Found:\n");
            printf("Roll No: %d\n", students[i].rollno);
            printf("Name: %s\n", students[i].name);
            printf("Marks: %.2f\n", students[i].marks);
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

void deleteStudent() {
    int rollno;
    printf("Enter Roll No to delete: ");
    scanf("%d", &rollno);

    int found = 0;
    for (int i = 0; i < num_students; i++) {
        if (students[i].rollno == rollno) {
            // Shift remaining students
            for (int j = i; j < num_students - 1; j++) {
                students[j] = students[j + 1];
            }
            num_students--;
            printf("Student deleted successfully.\n");
            found = 1;
            break;
        }
    }

    if (!found) {
        printf("Student not found.\n");
    }
}

int main() {
    int choice;

    do {
        printf("\nStudent Management System\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student\n");
        printf("4. Delete Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                displayStudents();
                break;
            case 3:
                searchStudent();
                break;
            case 4:
                deleteStudent();
                break;
            case 5:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice.\n");
        }
    } while (choice != 5);

    return 0;
}