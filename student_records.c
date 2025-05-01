
#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct {
    int rollNo;
    char name[50];
    float marks;
} Student;

Student students[MAX];
int count = 0;

int isDuplicate(int rollNo) {
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo)
            return 1;
    }
    return 0;
}

void addStudent() {
    if (count >= MAX) {
        printf("Student limit reached!\n");
        return;
    }

    printf("Enter Roll No: ");
    scanf("%d", &students[count].rollNo);

    if (isDuplicate(students[count].rollNo)) {
        printf("Roll Number already exists! Try again.\n");
        return;
    }

    printf("Enter Name: ");
    scanf(" %[^
]", students[count].name);

    printf("Enter Marks: ");
    scanf("%f", &students[count].marks);

    count++;
    printf("Student added successfully!\n");
}

void displayStudents() {
    if (count == 0) {
        printf("No students to display.\n");
        return;
    }

    printf("\nStudent Records:\n");
    for (int i = 0; i < count; i++) {
        printf("Roll No: %d, Name: %s, Marks: %.2f\n", students[i].rollNo, students[i].name, students[i].marks);
    }
}

void searchStudent() {
    int rollNo;
    printf("Enter Roll No to search: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            printf("Student Found: %s with Marks: %.2f\n", students[i].name, students[i].marks);
            return;
        }
    }
    printf("Student not found.\n");
}

void updateStudent() {
    int rollNo;
    printf("Enter Roll No to update: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            char confirm;
            printf("Are you sure you want to update marks for %s? (y/n): ", students[i].name);
            scanf(" %c", &confirm);
            if (confirm != 'y' && confirm != 'Y') {
                printf("Update canceled.\n");
                return;
            }
            printf("Enter new Marks: ");
            scanf("%f", &students[i].marks);
            printf("Marks updated successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void deleteStudent() {
    int rollNo;
    printf("Enter Roll No to delete: ");
    scanf("%d", &rollNo);
    for (int i = 0; i < count; i++) {
        if (students[i].rollNo == rollNo) {
            char confirm;
            printf("Are you sure you want to delete student %s? (y/n): ", students[i].name);
            scanf(" %c", &confirm);
            if (confirm != 'y' && confirm != 'Y') {
                printf("Deletion canceled.\n");
                return;
            }
            for (int j = i; j < count - 1; j++) {
                students[j] = students[j + 1];
            }
            count--;
            printf("Student deleted successfully.\n");
            return;
        }
    }
    printf("Student not found.\n");
}

void sortStudentsByMarks() {
    if (count == 0) {
        printf("No students to sort.\n");
        return;
    }
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].marks < students[j + 1].marks) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
    printf("Students sorted by Marks (High to Low)!\n");
}

void sortStudentsByRollNo() {
    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (students[j].rollNo > students[j + 1].rollNo) {
                Student temp = students[j];
                students[j] = students[j + 1];
                students[j + 1] = temp;
            }
        }
    }
}

void binarySearchStudent() {
    if (count == 0) {
        printf("No students to search.\n");
        return;
    }
    sortStudentsByRollNo();
    int rollNo, low = 0, high = count - 1, mid;
    printf("Enter Roll No to search (Binary Search): ");
    scanf("%d", &rollNo);
    while (low <= high) {
        mid = (low + high) / 2;
        if (students[mid].rollNo == rollNo) {
            printf("Student Found: %s with Marks: %.2f\n", students[mid].name, students[mid].marks);
            return;
        } else if (students[mid].rollNo < rollNo) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    printf("Student not found.\n");
}

int main() {
    int choice;
    do {
        printf("\n===== Student Records Management =====\n");
        printf("1. Add Student\n");
        printf("2. Display Students\n");
        printf("3. Search Student (Linear Search)\n");
        printf("4. Update Student Marks\n");
        printf("5. Delete Student\n");
        printf("6. Sort Students by Marks\n");
        printf("7. Binary Search Student\n");
        printf("8. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addStudent(); break;
            case 2: displayStudents(); break;
            case 3: searchStudent(); break;
            case 4: updateStudent(); break;
            case 5: deleteStudent(); break;
            case 6: sortStudentsByMarks(); break;
            case 7: binarySearchStudent(); break;
            case 8:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice! Try again.\n");
        }
    } while (choice != 8);

    return 0;
}
