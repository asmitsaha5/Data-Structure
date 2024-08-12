#include <stdio.h>
#include <stdlib.h>

struct employee
{
    char fname[20];
    char lname[20];
    char designation[20];
    int basicsalary;
    int empid;
};
struct address
{
    char city;
    char state;
    int pincode;
};

int main()
{

    int n;
    printf("Enter the number of employee :");
    scanf("%d", &n);
    struct employee *emp = (struct employee *)malloc(n * sizeof(struct employee *));

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of employee %d\n", i + 1);
        printf("Enter first name :");
        scanf("%s", emp[i].fname);
        printf("Enter last name :");
        scanf("%s", emp[i].lname);
        printf("Enter Employee Id :");
        scanf("%d", &emp[i].empid);
        printf("Enter the designation");
        scanf("%s", emp[i].designation);
        printf("Enter salary :");
        scanf("%d", &emp[i].basicsalary);
    }
    for (int i = 0; i < n; i++)
    {
        printf("Details of employee %d \n", i + 1);
        printf("Name : %s %s \n", emp[i].fname, emp[i].lname);
        printf("Employee Id : %d\n", emp[i].empid);
        printf("Basic Salary : %d\n\n", emp[i].basicsalary);
        printf("");

        float HRA = emp[i].basicsalary + (emp[i].basicsalary * (15 / 100));
        float DA = emp[i].basicsalary + (emp[i].basicsalary * (25 / 100));
        float Grosssalary;
        Grosssalary = HRA + DA + emp[i].basicsalary;
        printf("The Gross Salary is %d", Grosssalary);
    }
}