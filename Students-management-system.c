
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Structure to store student info
struct Student {
    char name[50];
    int studentNo;
    int math, english, computer;
    float average;
    char grade;
};

struct Student students[MAX];
int count = 0;

// Function prototypes
void addStudent();
void viewStudents();

void searchStudent();
void calculateResults();
void saveToFile();
char calculateGrade(float avg);

int main() {
    int choice;

    while (1) {
        printf("\n==============================\n");
        printf("      STUDENT MANAGEMENT SYSTEM\n");
        printf("==============================\n");
        printf("1. Add Student\n");
        printf("2. View Students\n");
        printf("3. Search Student\n");
        printf("4. Calculate Results\n");

        printf("5. Save Results to File\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: viewStudents(); break;
            case 3: searchStudent(); break;
            case 4: calculateResults(); break;
            case 5: saveToFile(); break;
            case 6: printf("Exiting program...\n"); exit(0);
            default: printf("Invalid choice! Please try again.\n");
        }
    }

    return 0;
}

// 1. Add Student
void addStudent() {
    if(count >= MAX) {
        printf("Maximum number of students reached.\n");
        return;
    }

    getchar(); // clear newline from buffer
    printf("Enter Student Name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter Student Number: ");
    scanf("%d", &students[count].studentNo);

    printf("Math Marks: ");
    scanf("%d", &students[count].math);

    printf("English Marks: ");
    scanf("%d", &students[count].english);

    printf("Computer Marks: ");
    scanf("%d", &students[count].computer);

    printf("Student added successfully!\n");
    count++;
}

// 2. View Students
void viewStudents() {
    if(count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\n-------------------------------------------------------------\n");
    printf("%-15s %-10s %-5s %-5s %-5s %-7s %-5s\n", 
           "Name", "StudentNo", "Math", "Eng", "Comp", "Average", "Grade");

    printf("-------------------------------------------------------------\n");

    for(int i = 0; i < count; i++) {
        printf("%-15s %-10d %-5d %-5d %-5d %-7.2f %-5c\n",
               students[i].name, students[i].studentNo,
               students[i].math, students[i].english, students[i].computer,
               students[i].average, students[i].grade);
    }
}

// 3. Search Student
void searchStudent() {
    if(count == 0) {
        printf("No students to search.\n");
        return;

    }

    int number, found = 0;
    printf("Enter Student Number to search: ");
    scanf("%d", &number);

    for(int i = 0; i < count; i++) {
        if(students[i].studentNo == number) {
            printf("\nStudent Found!\n");
            printf("Name: %s\n", students[i].name);
            printf("Math: %d\n", students[i].math);
            printf("English: %d\n", students[i].english);
            printf("Computer: %d\n", students[i].computer);
            printf("Average: %.2f\n", students[i].average);
            printf("Grade: %c\n", 

students[i].grade);
            found = 1;
            break;
        }
    }

    if(!found) printf("Student not found!\n");
}

// 4. Calculate Results
void calculateResults() {
    if(count == 0) {
        printf("No students to calculate.\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        int total = students[i].math + students[i].english + students[i].computer;
        students[i].average = total / 3.0;
        students[i].grade = 

calculateGrade(students[i].average);
    }

    printf("Results calculated successfully!\n");
}

// Helper function to calculate grade
char calculateGrade(float avg) {
    if(avg >= 80) return 'A';
    else if(avg >= 70) return 'B';
    else if(avg >= 60) return 'C';
    else if(avg >= 50) return 'D';
    else return 'F';
}

// 5. Save to File
void saveToFile() {
    if(count == 0) {
        printf("No data to save.\n");
        return;

    }

    FILE *file = fopen("students.txt", "w");
    if(file == NULL) {
        printf("Error opening file!\n");
        return;
    }

    for(int i = 0; i < count; i++) {
        // Ensure average & grade are calculated
        int total = students[i].math + students[i].english + students[i].computer;
        students[i].average = total / 3.0;
        students[i].grade = calculateGrade(students[i].average);

        fprintf(file, "%-15s %-10d %-5d %-5d %-5d %-7.2f %-5c\n",
                students[i].name, students[i].studentNo,

                students[i].math, students[i].english, students[i].computer,
                students[i].average, students[i].grade);
    }

    fclose(file);
    printf("Data saved to students.txt successfully!\n");
}



