#include<stdio.h>  
#include<stdlib.h> 
struct Employee { 
int empId; 
char 
empName[50]; 
float 
empSalary;}; 
int main() 
{ FILE 
*filePtr; 
struct Employee emp; 
filePtr = fopen("employee.dat", "rb+"); 
if (filePtr == NULL) { 
filePtr = fopen("employee.dat", "wb+"); 
if (filePtr == NULL) { 
printf("Error creating the 
file.\n"); return 1; } 
} 
Int 
choie; 
do { 
printf("\nEmployee Database Menu:\n"); 
printf("1. AddEmployee\n"); 
printf("2. Display Employee Details\n"); 
printf("3. Update Employee Details\n"); 
printf("4. Exit\n"); 
printf("Enter your choice: 
"); 
scanf("%d",&choice);swith 
(choice) { 
case 1: 
printf("Enter Employee ID: "); 
scanf("%d",&emp.empId);printf("Ente
 r EmployeeName: "); 
scanf("%s", emp.empName); 
printf("Enter Employee Salary: 
"); scanf("%f", 
&emp.empSalary); 
fseek(filePtr, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET); 
fwrite(&emp, sizeof(struct Employee), 1, filePtr); 
printf("Employee details added successfully.\n"); 
break; 
case 2: 
printf("Enter Employee ID to display: "); 
scanf("%d",&emp.empId); 
fseek(filePtr, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET); 
fread(&emp, sizeof(struct Employee), 1, filePtr); 
printf("Employee ID: %d\n", emp.empId); 
printf("Employee Name: %s\n", 
emp.empName);printf("EmployeeSalary:%.2f\n",emp.
 empSalary); break; 
case 3: 
printf("Enter Employee ID to update: "); 
scanf("%d",&emp.empId); 
fseek(filePtr, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET); 
fread(&emp, sizeof(struct Employee), 1, filePtr); 
printf("Enter EmployeeName: "); 
scanf("%s", emp.empName); 
printf("Enter Employee Salary:"); 
scanf("%f",&emp.empSalary); 
fseek(filePtr, (emp.empId - 1) * sizeof(struct Employee), SEEK_SET); 
fwrite(&emp, sizeof(struct Employee), 1, filePtr); 
printf("Employee detailsupdated successfully.\n"); 
break; 
case 4: 
break; 
default() 
printf("Invalid choice. Please try again.\n"); 
} 
} 
while(choice!=4); 
fclose(filePtr); 
return 0; 
} 
