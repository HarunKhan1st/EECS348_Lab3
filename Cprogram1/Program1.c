#include <stdio.h>
#define MONTHS 12

void sales_report(float sales[MONTHS])
{
    char my_months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Monthly sales report for 2022: \n");
    printf("Month               Sales\n");
    for (int i=0; i < 12; i++)
    {
        printf("%-15s   $%-15.2f\n", my_months[i], sales[i]);
    }   
}

void min_max_avg(float sales[MONTHS])
{
    char my_months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    float min=sales[0];
    int min_month=0;
    float max=0;
    int max_month=0;
    float avg=0;


    for (int i=0; i < 12; i++)
    {
        if (sales[i] > max)
        {
            max = sales[i];
            max_month = i;
        }

        if (sales[i] < min)
        {
            min = sales[i];
            min_month = i;
        }

        avg += sales[i];
    }   

    printf("Minimum Sales: $%-15.2f  (%s)\n", min, my_months[min_month]);
    printf("Maximum Sales: $%-15.2f  (%s)\n", max, my_months[max_month]);
    printf("Average Sales: $%-15.2f \n", avg/12);

}

void six_month_avg(float sales[MONTHS])
{
    float six_month_avg = 0;
    char my_months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    printf("Six-Month Moving Average Report\n\n");
    for (int i=0; i < 7; i++)
    {
        six_month_avg = 0;
        for (int j=i; j < i+6; j++)
        {
            six_month_avg += sales[j];
        }
        printf("%-15s - %-15s      $%-15.2f\n", my_months[i], my_months[i+5], six_month_avg/6);
    }
}

void print_sales_descending(float sales[MONTHS])
{
    char my_months[12][12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
    int month_tracker[12] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11};

    for (int i=0; i < MONTHS; i++)
    {
        for (int j=0; j < MONTHS; j++)
        {
            if (sales[i] > sales[j])
            {
                int tmp = sales[i];
                sales[i] = sales[j];
                sales[j] = tmp;

                int month_tmp = month_tracker[i];
                month_tracker[i] = month_tracker[j];
                month_tracker[j] = month_tmp;
            }
        }
    }
    printf("Month                      Sales\n");
    for (int k=0; k < MONTHS; k++)
        printf("%-15s           $%-15.2f\n", my_months[month_tracker[k]], sales[k]);
}



int main()
{
    char name[20];
    printf("Enter name of file: ");
    scanf("%s", name);

    float array[12];
    
    FILE *fp; 

    fp = fopen(name, "r");

    if (fp == NULL)
    {
        printf("Error\n");
    }

    for (int i=0; i < MONTHS; i++)
    {
        fscanf(fp, "%f", &array[i]);
    }

   
    sales_report(array);
    printf("\n\n");
    min_max_avg(array);
    printf("\n\n");
    six_month_avg(array);
    printf("\n\n");
    print_sales_descending(array);
    
    
    


    return 0;
}