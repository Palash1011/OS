#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define FILENAME "employee.dat"

typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;

void addEmployee();
void displayEmployees();
void updateEmployee();
void searchEmployee();

int main() {
    int choice;
    while (1) {
        printf("\nEmployee Management System\n");
        printf("1. Add Employee\n");
        printf("2. Display All Employees\n");
        printf("3. Update Employee\n");
        printf("4. Search Employee\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2:
                displayEmployees();
                break;
            case 3:
                updateEmployee();
                break;
            case 4:
                searchEmployee();
                break;
            case 5:
                exit(0);
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    return 0;
}

void addEmployee() {
    FILE *file = fopen(FILENAME, "ab");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    printf("Enter Employee ID: ");
    scanf("%d", &emp.id);
    printf("Enter Employee Name: ");
    scanf("%s", emp.name);
    printf("Enter Employee Salary: ");
    scanf("%f", &emp.salary);

    fwrite(&emp, sizeof(Employee), 1, file);
    fclose(file);
    printf("Employee added successfully!\n");
}

void displayEmployees() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    Employee emp;
    printf("\nEmployee Details:\n");
    printf("ID\tName\t\tSalary\n");
    printf("---------------------------------\n");
    while (fread(&emp, sizeof(Employee), 1, file)) {
        printf("%d\t%s\t\t%.2f\n", emp.id, emp.name, emp.salary);
    }
    fclose(file);
}

void updateEmployee() {
    FILE *file = fopen(FILENAME, "rb+");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int id;
    printf("Enter Employee ID to update: ");
    scanf("%d", &id);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.id == id) {
            printf("Enter new name: ");
            scanf("%s", emp.name);
            printf("Enter new salary: ");
            scanf("%f", &emp.salary);

            fseek(file, -sizeof(Employee), SEEK_CUR);
            fwrite(&emp, sizeof(Employee), 1, file);
            fclose(file);
            printf("Employee updated successfully!\n");
            return;
        }
    }

    printf("Employee with ID %d not found.\n", id);
    fclose(file);
}

void searchEmployee() {
    FILE *file = fopen(FILENAME, "rb");
    if (!file) {
        perror("Error opening file");
        return;
    }

    int id;
    printf("Enter Employee ID to search: ");
    scanf("%d", &id);

    Employee emp;
    while (fread(&emp, sizeof(Employee), 1, file)) {
        if (emp.id == id) {
            printf("\nEmployee Details:\n");
            printf("ID: %d\n", emp.id);
            printf("Name: %s\n", emp.name);
            printf("Salary: %.2f\n", emp.salary);
            fclose(file);
            return;
        }
    }

    printf("Employee with ID %d not found.\n", id);
    fclose(file);
}