#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

// Function Declaration
void displayGrades(int grades[]); 
char operations();
int generateNumbers(int min, int max);
void searchGrade(int grades[]);
void sortingOptions(int grades[]); 
void computeAverage(int grades[]);
void countPass(int grades[]);
void countFail(int grades[]);
void exitProgram();
char askAnother();

int main() {

    system("cls");
    int grades[8], i; // Declare variable
    char ch, returnCh;

    for (i = 0; i < 8; i++)
        grades[i] = generateNumbers(50, 100); // Generate numbers from 50 - 100

    // use do-while loop to loop operations unless ch == 'F' or exit.    
    do {
        displayGrades(grades); // Display grades
        ch = operations();
        switch (ch) {

            case 'A': // Case 'A' Search for specific grade
            do {

                printf("\nA. Search for Specific Grade\n"); // display choice
                searchGrade(grades); // search grade function
                returnCh = askAnother(); // ask if will go to operations or try again
                system("cls");
                displayGrades(grades); // display grades again
                printf("\n");
            } while (returnCh == 'N');
                break;

            case 'B':
            do {
                printf("\nB. Sort Grades\n"); 
                sortingOptions(grades);
                returnCh = askAnother();
                system("cls");
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;

            case 'C':
            do {
                printf("\nC. Compute the Average Grade\n"); // display choice
                computeAverage(grades); // compute average function
                returnCh = askAnother();
                system("cls");
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;

            case 'D':
            do {
                printf("\nD. Count Number of PASS Grades");
                countPass(grades);
                returnCh = askAnother();
                system("cls");
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;

            case 'E':
            do {
                printf("\nE. Count Number of FAIL Grades");
                countFail(grades);
                returnCh = askAnother();
                system("cls");
                displayGrades(grades);
                printf("\n");
            } while (returnCh == 'N');
                break;

            case 'F':
                system("cls");
                exitProgram();
                return 0;
                break;

            default:
                printf("Invalid input.");
                break;
        }
        system("cls");
    } while (returnCh == 'Y');

    return 0;
}

// Function Definition

char operations() {
    char ch;

    while (1) {
        printf("\n\nOperations:"); // Declare operations
        printf("\nA. Search for Specific Grade");
        printf("\nB. Sort Grades");
        printf("\nC. Compute the Average Grade");
        printf("\nD. Count Number of PASS Grades");
        printf("\nE. Count Number of FAIL Grades");
        printf("\nF. Exit");
        printf("\nEnter the letter that corresponds to the operation: ");
        scanf(" %c", &ch);

        ch = toupper(ch);
        if (ch == 'A' || ch == 'B' || ch == 'C' || ch == 'D' || ch == 'E' || ch == 'F')
            break;
    }
    return ch;
}

void displayGrades(int grades[]) {
    int i;

    printf("List of Grades:\n"); 
    for (i = 0; i < 8; i++)
        printf("%d\t", grades[i]); // Use for loop to display grades
}

int generateNumbers(int min, int max) {
    return min + rand() % (max - min + 1); // Generate random numbers from 50 - 100 (min 50, max 100, inclusive)
}

void searchGrade(int grades[]) {
    int i, grade, count = 0;

    printf("\nEnter grade to search: ");
    scanf("%d", &grade);

    for (i = 0; i < 8; i++)
        if (grades[i] == grade) // check if grades array has the same value from the grade input
            count++; // inc count if true

    if (count > 0) // check if count > 0 then print the result
        printf("Result: %d occurrence(s)", count);
    else // if count is 0, result not found
        printf("Result: Not found!");
}

void sortingOptions(int grades[]) {
    int i, j, ch, tempGrades[8];

    while (1) {
        printf("\nSorting Operations: "); // Loop options if not 1 or 2
        printf("\n[1] Ascending");
        printf("\n[2] Descending");
        printf("\nEnter operation: ");
        scanf("%d", &ch);

        if (ch == 1 || ch == 2)
            break;
    }

    for (i = 0; i < 8; i++)
        tempGrades[i] = grades[i]; // put values to temporary grade array

    switch (ch) {
    case 1:
        printf("\nSort in Ascending Order: \n");
        for (i = 0; i < 7; i++) // bubble sort
            for (j = 0; j < 7 - i; j++)  
                if (tempGrades[j] > tempGrades[j + 1]) {    // check if grades[j] is greater than grades[j + 1]
                        int temp = tempGrades[j]; // Swap values if true then continue the loop
                        tempGrades[j] = tempGrades[j + 1];
                        tempGrades[j + 1] = temp; 
                }
        for (i = 0; i < 8; i++) // Display grades 
            printf("%d\t", tempGrades[i]);
        break;
    case 2:
        printf("\nSort in Descending Order: \n");
        for (i = 0; i < 7; i++) 
            for (j = 0; j < 7 - i; j++) 
                if (tempGrades[j] < tempGrades[j + 1]) {    // check if grades[j] is less than grades[j + 1]
                        int temp = tempGrades[j]; // Swap values if true then continue the loop
                        tempGrades[j] = tempGrades[j + 1];
                        tempGrades[j + 1] = temp;
                }
        for (i = 0; i < 8; i++) // Display grades 
            printf("%d\t", tempGrades[i]);
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

void exitProgram() {
    printf("Thank you! Press E to exit...");
}

char askAnother() {
    char ch;

    while (1) {
        printf("\n\nPress Y to return to Operations, press N to try again: "); // option to exit or try again
        scanf(" %c", &ch);

        ch = toupper(ch); // convert character to uppercase

        if (ch == 'Y' || ch == 'N') // check if ch is equal to y or n, if not, continue the loop
            break;
    }
    return ch; // return value of ch
}

