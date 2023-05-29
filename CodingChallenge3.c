#include <stdio.h>
#include <stdlib.h>
#include <math.h>

void displayGrades(int grades[]);
int operations(int grades[]);
int generateNumbers(int min, int max);
void searchGrade(int grades[]);
void sortingOptions(int grades[]); // Di pa tapos
void computeAverage(int grades[]);
void countPass(int grades[]);
void countFail(int grades[]);
char askAnother();

int main() {

    system("cls");
    int grades[8], i; // Declare variable

    for (i = 0; i < 8; i++)
        grades[i] = generateNumbers(50, 100); // Generate numbers from 50 - 100

    displayGrades(grades); // Display grades
    operations(grades); // Operations

    return 0;
}

void displayGrades(int grades[]) {
    int i;

    printf("\nList of Grades:\n"); 
    for (i = 0; i < 8; i++)
        printf("%d\t", grades[i]); // Use for loop to display grades
}

int operations(int grades[]) {
    char ch, returnCh;

    do // use do-while loop to loop operations unless ch == 'F' or exit.
    {   
        printf("\n\nOperations:"); // Declare operations
        printf("\nA. Search for Specific Grade");
        printf("\nB. Sort Grades");
        printf("\nC. Compute the Average Grade");
        printf("\nD. Count Number of PASS Grades");
        printf("\nE. Count Number of FAIL Grades");
        printf("\nF. Exit");
        printf("\nEnter the letter that corresponds to the operation: ");
        scanf(" %c", &ch);

        switch (ch)
        {
            case 'A': // Case 'A' Search for specific grade
            do {
                printf("\nA. Search for Specific Grade\n"); // display choice
                searchGrade(grades); // search grade function
                returnCh = askAnother();
                printf("\n\n\n-------------------------------------------------------------------------------");
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;
            case 'B':
            do {
                printf("\nB. Sort Grades\n");
                sortingOptions(grades);
                returnCh = askAnother();
                printf("\n\n\n-------------------------------------------------------------------------------");
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;
            case 'C':
            do {
                printf("\nC. Compute the Average Grade\n"); // display choice
                computeAverage(grades); // compute average function
                returnCh = askAnother();
                printf("\n\n\n-------------------------------------------------------------------------------");
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;
            case 'D':
            do {
                printf("\nD. Count Number of PASS Grades");
                countPass(grades);
                returnCh = askAnother();
                printf("\n\n\n-------------------------------------------------------------------------------");
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;
            case 'E':
            do {
                printf("\nE. Count Number of FAIL Grades");
                countFail(grades);
                returnCh = askAnother();
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;
            case 'F':
                printf("\n\nThank you! Press E to exit...");
                return 0;
                break;
            default:
                break;
        }
    }while (returnCh == 'Y');



}

int generateNumbers(int min, int max) {
    return min + rand() % (max - min + 1); // Generate random numbers from 50 - 100 (min 50, max 100, inclusive)
}

void searchGrade(int grades[]) {
    int i, grade, count = 0;

    printf("\nEnter grade to search: ");
    scanf("%d", &grade);

    for (i = 0; i < 8; i++)
    {
        if (grades[i] == grade) // check if grades array has the same value from the grade input
            count++; // inc count if true
    }

    if (count > 0) // check if count > 0 then print the result
        printf("Result: %d occurrence(s)", count);
    else // if count is 0, result not found
        printf("Result: Not found!");
}

void sortingOptions(int grades[]) {
    int ch;
    printf("\nSorting Operations: ");
    printf("\n[1] Ascending");
    printf("\n[2] Descending");
    printf("\nEnter operation: ");
    scanf("%d", &ch);

    switch (ch)
    {
    case 1:
        printf("\nSort in Ascending Order: ");
        // to be produce (ASCENDING ORDER)
        break;
    case 2:
        printf("\nSort in Descending Order: ");
        // to be produce (DESCENDING ORDER)
        break;
    default:
        break;
    }
}

void computeAverage(int grades[]) {
    int i, sum = 0, ave; // declare variables

    for (i = 0; i < 8; i++)
        sum += grades[i];  // assign value of sum to the sum of each value in the array

    ave = sum / 8; // divide sum from 8 to get the average
    printf("\nAverage grade: %d%%", ave); // display average
}

void countPass(int grades[]) {
    int i, count = 0;

    for (i = 0; i < 8; i++)
    {
        if (grades[i] <= 100 && grades[i] >= 75) // check if grades array is less than or equal to 100 and is greater than or equal to 75
            count++; // inc count if true
    }
    printf("\n\nCount: %d", count); // display pass count
}

void countFail(int grades[]) {
    int i, count = 0;

    for (i = 0; i < 8; i++)
    {
        if (grades[i] <= 74 && grades[i] >= 50) // check if grades array is less than or equal to 74 and is greater than or equal to 50
            count++; // inc count if true
    }
    printf("\n\nCount: %d", count); // display fail count
}

char askAnother() {
    char ch;

    printf("\n\nPress Y to return to Operations, press N to try again: "); // option to exit or try again
    scanf(" %c", &ch);

    return ch;
}