#include <stdio.h>
struct employee
{
    char fname[20];
    char lname[20];
    int empid;
    int salary;
};

int main()
{

    int n;
    printf("Enter the number of employee :");
    scanf("%d", &n);
    struct employee emp[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of employee %d\n", i + 1);
        printf("Enter first name :");
        scanf("%s", emp[i].fname);
        printf("Enter last name :");
        scanf("%s", emp[i].lname);
        printf("Enter Employee Id :");
        scanf("%d", &emp[i].empid);
        printf("Enter salary :");
        scanf("%d", &emp[i].salary);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Details of employee %d \n", i + 1);
        printf("Name : %s %s \n", emp[i].fname, emp[i].lname);
        printf("Employee Id : %d\n", emp[i].empid);
        printf("Salary : %d\n\n", emp[i].salary);
    }
}