#include<stdio.h>
#include<string.h>

struct student {
    int rollNo;
    float marks;
    char name[20];
    char grade;
};

void inputStudentDetails(struct student std[], int n) {
    for(int i = 0; i < n; i++) {
        printf("Enter Roll Number, Name, and Marks for student %d: ", i + 1);
        scanf("%d %s %f", &std[i].rollNo, std[i].name, &std[i].marks);
    }
}

char calculateGrade(float marks) {
    if(marks >= 90) return 'A';
    else if(marks >= 80) return 'B';
    else if(marks >= 70) return 'C';
    else if(marks >= 60) return 'D';
    else return 'F';
}

void displayStudentDetails(struct student std[], int n) {
    printf("RollNo\t Name\t Marks\t Grade\n");
    for(int i = 0; i < n; i++) {
        std[i].grade = calculateGrade(std[i].marks);
        printf("%d\t %s\t %.2f\t %c\n", std[i].rollNo, std[i].name, std[i].marks, std[i].grade);
    }
}

void searchStudent(struct student std[], int n, int key) {
    int found = 0;
    for(int i = 0; i < n; i++) {
        if(std[i].rollNo == key) {
            printf("RollNo: %d\t Name: %s\t Marks: %.2f\t Grade: %c\n", std[i].rollNo, std[i].name, std[i].marks, std[i].grade);
            found = 1;
            break;
        }
    }
    if(!found) {
        printf("Student with Roll Number %d not found.\n", key);
    }
}

int main() {
    int n = 10;
    int key;
    char choice;
    struct student std[n];

    do {
        printf("\nMenu:\n");
        printf("1. Input Student Details\n");
        printf("2. Display All Student Details\n");
        printf("3. Search for a Student by Roll Number\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf(" %c", &choice);

        switch(choice) {
            case '1':
                inputStudentDetails(std, n);
                break;
            case '2':
                displayStudentDetails(std, n);
                break;
            case '3':
                printf("Enter Roll Number to search: ");
                scanf("%d", &key);
                searchStudent(std, n, key);
                break;
            case '4':
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != '4');

    return 0;
}
