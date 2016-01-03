/* Programmer   :   Bernice Templeman
/* Date         :   10/15/2014
/* Class        :   COP1334
/* Project      :   Exercise 3
/*
/* Description  :
Write a program that asks the user to enter the number of students in his/her class
and then calculates and displays number of A’s, B’s, C’s, D’s, and F’s for the entire class.

Each student is graded on the following categories:
• 10 programming Exercises (progEx)
• 1 Midterm (midTerm)
• 1 Final Exam (final)

For each student, use random number generator to generate scores for each category.
You need to make sure that the random number generator
returns value in the range 1-100 for each of the grade book categories.
So for each student you need to calculate their grade using the following formula:

numericGrade = (progEx Average *.70) + (midTerm *.15)+(final *.15)

The program needs to compute the letter grade equivalent according to the following chart:
numericGrade (range)   letterGrade
0–59                       F
60-69                        D
70-79                        C
80-89                        B
90-100                       A

Once letter grade has been computed, update the count for that letter grade. When the program finishes the loop, it should display the following information:
Number of students who received each letter grade:
10 A
14 B
6 C
4 D
4 F

*/

#include <iostream>
#include <ctime>     // time
#include <cstdlib>   // random function generator

using namespace std;

int main()
{
    //Constants
    const double PROG_EX_PERCENT = 0.70;    //programming exercise percentage of grade
    const double MID_TERM_PERCENT = 0.15;   // mid term percentage of grade
    const double FINAL_PERCENT = 0.15;      //final exam percentage of grade
    const int GRADE_LOW = 1;                //low month range 1
    const int GRADE_HIGH = 100;             // high grade range 100

    //Variable declarations
    char letterGrade;                       // letter grade
    int numStudents;                        // number of Students
    int numericGrade;                       // numeric grade
    int progEx;                             // program exercise grade
    int progExTotal;                        // program exercise accumulator
    int progExAverage;                      // program exercise Average
    int midTerm;                            // midterm numeric grade
    int finalExam;                          // final exam numeric grade

    //declare & initialize counters
    int aCount = 0,                         // A counter initialized to 0
        bCount = 0,                         // B counter initialized to 0
        cCount = 0,                         // C counter initialized to 0
        dCount = 0,                         // D counter initialized to 0
        fCount = 0;                         // F counter initialized to 0

    //seed the random number generator
    srand( time( NULL ) );

    // ask for number of students
    cout << "Enter the number of students in your class: ";

    //get number of students
    cin >> numStudents;

    //loop for each student
    for(int i=0; i < numStudents; i++ )
    {
        //get their grades
        //use random number generator to generate scores for each category.

        //get program exercise grades and compute average

        //set total to 0
        progExTotal = 0;

        //generate 10 program exercise scores
        for (int j=0; j<10; j++)
        {

            progEx = (rand() % (GRADE_HIGH-GRADE_LOW + 1)) + GRADE_LOW;

            progExTotal = progEx + progExTotal;

        }//end progEx for loop
        //calculate the average of the 10 scores
        progExAverage = static_cast<double>(progExTotal)/10;

        //get the midterm score
        midTerm = (rand() % (GRADE_HIGH-GRADE_LOW + 1)) + GRADE_LOW;

        //get the final exam score
        finalExam = (rand() % (GRADE_HIGH-GRADE_LOW + 1)) + GRADE_LOW;

        //calculate their numeric grade
        //numericGrade = (progEx Average *.70) + (midTerm *.15)+(final *.15)
        numericGrade =((progExAverage * PROG_EX_PERCENT )
                        + (midTerm * MID_TERM_PERCENT)
                        + (finalExam * FINAL_PERCENT ));

        //Compute letter Grade equivalent
        if  (numericGrade < 60)
        {
            letterGrade = 'F';
            fCount++;
        }
        else if (numericGrade < 70)
        {
            letterGrade = 'D';
            dCount++;
        }
        else if (numericGrade < 80)
        {
            letterGrade = 'C';
            cCount++;
        }
        else if (numericGrade < 90)
        {
            letterGrade = 'B';
            bCount++;
        }
        else
        {
            letterGrade = 'A';
            aCount++;
        }

    }//end for loop

    //Display the count for each letter grade
    cout << "Number of students who received each letter grade: " << endl;
    cout << aCount << " A" << endl;
    cout << bCount << " B" << endl;
    cout << cCount << " C" << endl;
    cout << dCount << " D" << endl;
    cout << fCount << " F" << endl;

    return 0;
}
