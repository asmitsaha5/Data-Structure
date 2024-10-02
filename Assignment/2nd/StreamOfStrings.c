#include <stdio.h>
#include <string.h>

int main()
{
    char stream[100];
    int n;

    printf("Enter the stream of characters (without spaces): ");
    scanf("%s", stream);

    n = strlen(stream);

    int element = -1;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (stream[i] == stream[j])
            {
                count++;
            }
        }
        if (count == 1)
        {
            element = i;
            break;
        }
    }

    if (element != -1)
    {
        printf("First non-repeating character: %c\n", stream[element]);
    }
    else
    {
        printf("-1\n");
    }

    return 0;
}
