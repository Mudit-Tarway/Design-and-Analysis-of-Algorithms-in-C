#include <stdio.h>

int main()
{
    float w[50], p[50], ratio[50], m, total, temp;
    int n, i, j;

    printf("Enter the number of items: ");
    scanf("%d", &n);

    for (i = 0; i < n; i++)
    {
        printf("Enter the weight and profit for item[%d]: \n", i);
        scanf("%f %f", &w[i], &p[i]);
    }

    printf("Enter the capacity of knapsack :\n");
    scanf("%f", &m);

    for (i = 0; i < n; i++)
    {
        ratio[i] = p[i] / w[i];
    }

    // Sorting items by ratio in descending order
    for (i = 0; i < n; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (ratio[i] < ratio[j])
            {
                temp = ratio[j];
                ratio[j] = ratio[i];
                ratio[i] = temp;

                temp = w[j];
                w[j] = w[i];
                w[i] = temp;

                temp = p[j];
                p[j] = p[i];
                p[i] = temp;
            }
        }
    }

    printf("Knapsack problems using greedy method :\n");

    total = 0;
    for (i = 0; i < n; i++)
    {
        if (w[i] > m)
            break;
        else
        {
            total = total + p[i];
            m = m - w[i];
        }
    }

    if (i < n)
        total = total + (ratio[i] * m);

    printf("\nThe maximum value is : %f\n", total);

    return 0;
}