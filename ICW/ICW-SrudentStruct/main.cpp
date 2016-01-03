#include <iostream>
#include <string>
#include <ctime>
#include <cstdlib>

using namespace std;

const int NUM_QUIZZES = 5;

const int NUM_EXAMS = 3;

struct Student

{

        string firstName;

        string lastName;

        int quizzes[NUM_QUIZZES];

        int exams[NUM_EXAMS];

};

int main()

{

        const int NUM_STUDENTS = 2;

        Student cop1334[NUM_STUDENTS];

        int quizSum;
        int examSum;
        double quizAvg;
        double examAvg;


        //RANDOM GENERATOR FUNCTION
        srand( time(0));      //This will ensure a really randomized number by help of time

        for (int index = 0; index < NUM_STUDENTS; index++)

        {

                cout << "Enter first name: ";

                cin >> cop1334[index].firstName;

                cout << "Enter last name: ";

                cin >> cop1334[index].lastName;

                quizSum = 0;
                examSum = 0;
                quizAvg =0;
                examAvg = 0;

                for (int i = 0; i < NUM_QUIZZES; i++)

                {
                    cop1334[index].quizzes[i]= rand()%51+50; // Randomizing the number between 50-100.
                    quizSum = quizSum + cop1334[index].quizzes[i];
                }

                for (int i = 0; i < NUM_EXAMS; i++)

                {
                    cop1334[index].exams[i]= rand()%51+50; // Randomizing the number between 50-100.
                    examSum = examSum + cop1334[index].exams[i];
                }

                cout << "\n\nName: " << cop1334[index].firstName

                        << " " << cop1334[index].lastName << endl;

                for (int i = 0; i < NUM_QUIZZES; i++)

                        cout << "Quiz #"

                        << i + 1 << ": " << cop1334[index].quizzes[i]

                        << endl;

                for (int i = 0; i < NUM_EXAMS; i++)

                        cout << "Exam #"

                        << i + 1 << ": " << cop1334[index].exams[i]

                        << endl;
                cout<< "Quiz Average: " << static_cast<float>(quizSum)/NUM_QUIZZES << endl;
                cout << "Exam Average: "<< static_cast<float>(examSum)/NUM_EXAMS<< endl;

        }



        return 0;

}
