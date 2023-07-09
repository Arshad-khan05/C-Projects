#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
typedef struct node
{
    char NAME[30];
    int INTERNALMARKS[2];
    int QUIZ[4];
    int total_credits;
    int attendance;
    struct node *next;
} NODE;

NODE *insert(NODE *first, int size);
void eligible(NODE *first);
void display(NODE *first);
void compute_credits(NODE *first);
//Creating a node to store the details of the student
NODE *insert(NODE *first, int size)
{

    int i, j;
    for (j = 0; j < size; j++)
    {
        NODE *temp;
        NODE *newnode = (NODE *)malloc(sizeof(NODE));
        printf("ENTER STUDENT%d NAME:\n", j + 1);
        scanf("%s", newnode->NAME);

        for (i = 0; i < 2; i++)
        {

            printf("ENTER TEST%d MARKS:\n", i + 1);
            scanf("%d", &newnode->INTERNALMARKS[i]);
        }
        for (i = 0; i < 4; i++)
        {
            printf("ENTER QUIZ%d MARKS:\n", i + 1);
            scanf("%d", &newnode->QUIZ[i]);
        }
        printf("Enter the attendance out of 25 class:\n");
        scanf("%d", &newnode->attendance);

        newnode->next = NULL;
        if (first == NULL)
        {
            first = newnode;
        }
        else
        {
            temp = first;
            while (temp->next != NULL)
            {
                temp = temp->next;
            }
            temp->next = newnode;
        }
        compute_credits(first);
        display(first);
        eligible(first);
        FILE *file3;
        file3 = fopen("Student_details.txt", "a+");
        fprintf(file3, "Name          : %s\n", newnode->NAME);
        fprintf(file3, "Test1 marks   : %d\n", newnode->INTERNALMARKS[0]);
        fprintf(file3, "Test2 marks   : %d\n", newnode->INTERNALMARKS[1]);
        fprintf(file3, "Quiz1 marks   : %d\n", newnode->QUIZ[0]);
        fprintf(file3, "Quiz2 marks   : %d\n", newnode->QUIZ[1]);
        fprintf(file3, "Quiz3 marks   : %d\n", newnode->QUIZ[2]);
        fprintf(file3, "Quiz4 marks   : %d\n", newnode->QUIZ[3]);
        fprintf(file3, "Total credits  : %d\n", newnode->total_credits);
        fprintf(file3, "Attendence     : %d\n", newnode->attendance);
        fprintf(file3, "\n\n\n");
        fclose(file3);
    }
    return first;
}
//Calculating credits earned by a student
void compute_credits(NODE *first)
{
    NODE *temp;
    int internal_credits[2], quiz_credits[4];
    int i_credits, q_credits, total_ic = 0, total_qc = 0;
    temp = first;
    while (temp != NULL)
    {
        for (int j = 0; j < 2; j++)
        {
            i_credits = (17 * temp->INTERNALMARKS[j]) / 50;
            if ((temp->INTERNALMARKS[j] * 17) % 50 != 0)
                i_credits = i_credits + 1;
            internal_credits[j] = i_credits;
            total_ic = total_ic + internal_credits[j];
        }
        for (int j = 0; j < 4; j++)
        {
            q_credits = (4 * temp->QUIZ[j]) / 10;
            if ((temp->QUIZ[j] * 4) % 10 != 0)
                q_credits = q_credits + 1;
            quiz_credits[j] = q_credits;
            total_qc = total_qc + quiz_credits[j];
        }
        temp->total_credits = total_ic + total_qc;
        temp = temp->next;
        total_ic = 0;
        total_qc = 0;
    }
}
//Checking whether the student is eligible or not 
void eligible(NODE *first)
{
    static int b = 0;
    NODE *temp = first;
    float a;
    for (int i = 0; i < b; i++)

    {
        temp = temp->next;
    }
    b++;

    a = round(0.85 * 25);
    if (temp->attendance >= a)
    {
        if (temp->total_credits > 20)
        {
            printf("\nCongratulations! %s you are eligible\n", temp->NAME);
            FILE *file1;
            file1 = fopen("Eligibility_report.txt", "a+");
            fprintf(file1, "%s\n", temp->NAME);
            fclose(file1);
        }
        else
        {
            printf("\n%s is not eligible due to low credits (i.e <20 )\n", temp->NAME);
            FILE *file2;
            file2 = fopen("Not_Eligibility_report.txt", "a+");
            fprintf(file2, "%s\n", temp->NAME);
            fclose(file2);
        }
    }
    else
    {
        printf("\n%s is not eligible due to low attendence (i.e <85%% )\n", temp->NAME);
        FILE *file2;
        file2 = fopen("Not_Eligibility_report.txt", "a+");
        fprintf(file2, "%s\n", temp->NAME);
        fclose(file2);
    }
    printf("\n*********************************************************\n\n");
}
//Displaying details of the students 
void display(NODE *first)
{
    static int k = 0;
    NODE *temp = first;
    for (int i = 0; i < k; i++)
    {
        temp = temp->next;
    }
    k++;
    printf("Name: %s\n", temp->NAME);
    for (int i = 0; i < 2; i++)
        printf("Test%d marks : %d\n", i + 1, temp->INTERNALMARKS[i]);

    for (int j = 0; j < 4; j++)
    {
        printf("Quiz%d marks : %d\n", j + 1, temp->QUIZ[j]);
    }
    printf("Total credits : %d\n", temp->total_credits);
    printf("Attendence : %d%%", temp->attendance * 100 / 25);

    printf("\n");
}

int main()
{
    NODE *first = NULL;
//Creating 3 files for storing  details of the students
    FILE *file1;
    file1 = fopen("Eligibility_report.txt", "a+");
    fprintf(file1, "Students eligible for exam\n");
    fclose(file1);

    FILE *file2;
    file2 = fopen("Not_Eligibility_report.txt", "a+");
    fprintf(file2, "Students not eligible for exam\n");
    fclose(file2);

    FILE *file3;
    file3 = fopen("Student_details.txt", "a+");
    fprintf(file3, "Details of the students:\n");
    fprintf(file3, "\n\n\n");
    fclose(file2);

    int size;
    printf("Enter the number of students:\n");
    scanf("%d", &size);
    first = insert(first, size);

    return 0;
}
