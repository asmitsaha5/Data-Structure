#include <stdio.h>
#include <string.h>

#define MAX_NAME_LENGTH 50
#define ARRAY_SIZE 3

struct student
{
    char name[MAX_NAME_LENGTH];
    int roll;
    float CGPA;
};

int main()
{
    struct student stu[ARRAY_SIZE];

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Enter details for student %d:\n", i + 1);

        printf("  Name: ");
        fgets(stu[i].name, MAX_NAME_LENGTH, stdin);
        stu[i].name[strcspn(stu[i].name, "\n")] = '\0';

        printf("  ROll: ");
        scanf("%d", &stu[i].roll);

        printf("  CGPA: ");
        scanf("%f", &stu[i].CGPA);
        while (getchar() != '\n')
            ;
    }
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Student %d:\n", i + 1);
        printf("  Name: %s\n", stu[i].name);
        printf("  Roll: %d\n", stu[i].roll);
        printf("  CGPA: %.1f\n\n", stu[i].CGPA);
    }

    return 0;
}
