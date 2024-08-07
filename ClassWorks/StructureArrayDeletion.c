#include <stdio.h>
struct student
{
    char studentname[20];
    int Roll;
    double CGPA;
};

int main()
{
    int n, pos;

    printf("Enter the number of students : ");
    scanf("%d", &n);

    struct student std[n];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of the student %d : \n ", i + 1);
        printf("Enter the name : ");
        scanf("%s", std[i].studentname);
        printf("Enter the roll no. : ");
        scanf("%d", &std[i].Roll);
        printf("Enter the CGPA : ");
        scanf("%2lf", &std[i].CGPA);
    }

    printf("Enter the position to delete the student (1 to %d): ", n);
    scanf("%d", &pos);
    pos--;
    for (int i = pos; i < n; i++)
    {
        std[i] = std[i + 1];
    }
    n--;

    for (int i = 0; i < n; i++)
    {
        printf("Details of the student %d:\n", i + 1);
        printf("Name of the student: %s\n", std[i].studentname);
        printf("Roll no: %d\n", std[i].Roll);
        printf("CGPA: %.2lf\n", std[i].CGPA);
    }

    return 0;
}