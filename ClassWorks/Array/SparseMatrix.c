#include <stdio.h>
int main()
{
    int m, n;
    int i, j, k = 0;
    int count = 0;

    scanf("%d %d", &m, &n);
    int s[m][n];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            scanf("%d", &s[i][j]);
        }
    }

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[i][j] != 0)
                count++;
        }
    }
    int E[count][3];
    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
        {
            if (s[i][j] != 0)
            {
                E[k][0] = s[i][j];
                E[k][1] = i;
                E[k][2] = j;
                printf("%d %d %d\n", E[k][0], E[k][1], E[k][2]);
                k++;
            }
        }
    }
}