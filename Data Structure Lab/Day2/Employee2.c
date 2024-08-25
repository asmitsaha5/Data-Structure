#include <stdio.h>
#include <stdlib.h>
struct address
{
    int pincode;
    char state[20];
};

struct employee
{
    char name[20];
    int empid;
    char designation[20];
    int salary;
    struct address details;
};

int main()
{
    int n;
    printf("Enter the number of employee :");
    scanf("%d", &n);
    struct employee *emp = (struct employee *)malloc(n * sizeof(struct employee *));
    if (emp == NULL)
    {
        printf("Memory full");
    }
    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of employee %d\n", i + 1);
        printf("Enter Employee Name :");
        scanf("%s", emp[i].name);
        printf("Enter Employee Id :");
        scanf("%d", &emp[i].empid);
        printf("Enter designation :");
        scanf("%s", emp[i].designation);
        printf("Enter salary :");
        scanf("%d", &emp[i].salary);
        printf("Enter Pin Code :");
        scanf("%d", &emp[i].details.pincode);
        printf("Enter State :");
        scanf("%s", emp[i].details.state);
    }

    for (int i = 0; i < n; i++)
    {
        printf("Details of employee %d \n", i + 1);
        printf("Name : %s\n", emp[i].name);
        printf("Employee Id : %d\n", emp[i].empid);
        printf("Designation : %s\n", emp[i].designation);
        printf("Salary : %d\n", emp[i].salary);
        float hra = (emp[i].salary * 25) / 100;
        float da = (emp[i].salary * 15) / 100;
        float gross;
        gross = emp[i].salary + hra + da;
        printf("Gross salary :%f\n", gross);
        printf("Pin Code :%d\n", emp[i].details.pincode);
        printf("State :%s \n\n", emp[i].details.state);
    }
    free(emp);
}