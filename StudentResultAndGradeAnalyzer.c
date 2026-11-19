#include <stdio.h>

int main(){
    int n, i, j;
    int marks[50][5];
    int total[50];
    float percentage[50];
    char grade[50];
    int pass[50];
    int topper = 0;
    float classTotal = 0;
    printf("Enter number of students: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++)
    {
        total[i] = 0;
        pass[i] = 1;

        printf("\nEnter marks for Student %d:\n", i + 1);

        for(j = 0; j < 5; j++)
        {
            printf("Subject %d: ", j + 1);
            scanf("%d", &marks[i][j]);

            total[i] += marks[i][j];

            if(marks[i][j] < 35)
            {
                pass[i] = 0;
            }
       }

        percentage[i] = total[i] / 5.0;

        if(percentage[i] >= 90)
            grade[i] = 'A';
        else if(percentage[i] >= 75)
            grade[i] = 'B';
        else if(percentage[i] >= 60)
            grade[i] = 'C';
        else if(percentage[i] >= 40)
            grade[i] = 'D';
        else
            grade[i] = 'F';

        classTotal += percentage[i];

        if(total[i] > total[topper])
            topper = i;
    }

    printf("\n =====STUDENT RESULTS===== \n");

    for(i = 0; i < n; i++)
    {
        printf("\nStudent %d\n", i + 1);
        printf("Total Marks: %d / 500\n", total[i]);
        printf("Percentage: %.2f%%\n", percentage[i]);
        printf("Grade: %c\n", grade[i]);

        if(pass[i])
            printf("Result: PASS\n");
        else
            printf("Result: FAIL\n");
    }
    printf("\n====CLASS REPORT=====\n");
    printf("Class Topper: Student %d\n", topper + 1);
    printf("Topper Marks: %d / 500\n", total[topper]);
    printf("Class Average: %.2f%%\n", classTotal / n);

    return 0;
}