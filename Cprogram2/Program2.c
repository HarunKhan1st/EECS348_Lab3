#include <stdio.h>

int main()
{
    // 2, 3, 6, 7, 8 possible points
    int total_score = 1;

    printf("Enter 0 or 1 to STOP\n");
    
    while (total_score <= 1)
    {
        printf("Enter the NFL score: \n");
        scanf("%d", &total_score);
    }

    for (int i=0; i <= (total_score/8); i++) // number of 8s
    {
        for (int j=0; j <= (total_score/7); j++) // number of 7s
        {
            for (int k=0; k <= (total_score/6); k++) // number of 6s
            {
                for (int l=0; l <= (total_score/3); l++) // number of 3s
                {
                    for (int p=0; p <= (total_score/2); p++) // number of 2s 
                    {
                        if ((8*i + 7*j + 6*k + 3*l + 2*p) == total_score)
                        {
                            printf("%d TD + 2pt, %d TD + FG, %d TD, %d 3pt FG, %d Safety\n", i, j, k, l, p);
                        }                            
                    }
                }
            }
        }
    }
    


    return 0;
}