#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct EmployeeNode
{
    int year;
    int numEmployees;
    struct EmployeeNode *next;
} EmployeeNode;

typedef struct CompanyNode
{
    char companyName[50];
    EmployeeNode *employees;
    struct CompanyNode *next;
} CompanyNode;

EmployeeNode *createEmployeeNode(int year, int numEmployees)
{
    EmployeeNode *newNode = (EmployeeNode *)malloc(sizeof(EmployeeNode));
    newNode->year = year;
    newNode->numEmployees = numEmployees;
    newNode->next = NULL;
    return newNode;
}

CompanyNode *createCompanyNode(char *name)
{
    CompanyNode *newNode = (CompanyNode *)malloc(sizeof(CompanyNode));
    strcpy(newNode->companyName, name);
    newNode->employees = NULL;
    newNode->next = NULL;
    return newNode;
}

void addEmployee(CompanyNode *company, int year, int numEmployees)
{
    EmployeeNode *newEmployee = createEmployeeNode(year, numEmployees);

    if (company->employees == NULL)
    {
        company->employees = newEmployee;
    }
    else
    {
        EmployeeNode *temp = company->employees;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newEmployee;
    }
}

void traverse(CompanyNode *head)
{
    CompanyNode *company = head;

    while (company != NULL)
    {
        printf("Company: %s\n", company->companyName);

        EmployeeNode *employee = company->employees;
        while (employee != NULL)
        {
            printf("  Year: %d, Employees Joined: %d\n", employee->year, employee->numEmployees);
            employee = employee->next;
        }
        company = company->next;
        printf("\n");
    }
}

CompanyNode *addCompany(CompanyNode *head, char *name)
{
    CompanyNode *newCompany = createCompanyNode(name);

    if (head == NULL)
    {
        return newCompany;
    }
    else
    {
        CompanyNode *temp = head;
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newCompany;
        return head;
    }
}

int main()
{
    CompanyNode *companies = NULL;

    companies = addCompany(companies, "TCS");
    companies = addCompany(companies, "INFO");
    companies = addCompany(companies, "Wipro");

    addEmployee(companies, 2001, 98);
    addEmployee(companies, 2002, 34);

    addEmployee(companies->next, 2001, 26);
    addEmployee(companies->next, 2003, 34);

    addEmployee(companies->next->next, 2002, 98);
    addEmployee(companies->next->next, 2006, 32);

    traverse(companies);

    return 0;
}
