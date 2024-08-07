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

    struct student std[n + 1];

    for (int i = 0; i < n; i++)
    {
        printf("Enter the details of the student %d : \n ", i + 1);
        printf("Enter the name : ");
        scanf("%s", std[i].studentname);
        printf("Enter the roll no. : ");
        scanf("%d", &std[i].Roll);
        printf("Enter the CGPA : ");
        scanf("%lf", &std[i].CGPA);
    }

    printf("Enter the position to insert the new student (1 to %d): ", n + 1);
    scanf("%d", &pos);
    pos--;

    for (int i = n; i > pos; i--)
    {
        std[i] = std[i - 1];
    }
    printf("Enter the details of the new student : \n");
    printf("Enter the name : ");
    scanf("%s", std[pos].studentname);
    printf("Enter the roll no. : ");
    scanf("%d", &std[pos].Roll);
    printf("Enter the CGPA : ");
    scanf("%lf", &std[pos].CGPA);

    for (int i = 0; i < n + 1; i++)
    {
        printf("Details of the student %d \n", i + 1);
        printf("Name of the student : %s \n", std[i].studentname);
        printf("Roll no : %d \n", std[i].Roll);
        printf("CGPA : %lf \n", std[i].CGPA);
    }

    return 0;
}
