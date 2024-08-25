#include <stdio.h>
struct student
{
    int Roll, CGPA;
    char Name;

} s;
int main()
{

    printf("Enter the Roll No. :");
    scanf("%d", &s.Roll);
    printf("Enter the CGPA : ");
    scanf("%d", &s.CGPA);

    printf("Roll No. : %d\n", s.Roll);
    printf("CGPA :%d", s.CGPA);
}
