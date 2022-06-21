// LMS Grade  Calculator.cpp : This file contains the 'main' function. Program execution begins and ends there.
#include <iostream>
// grade calculator 2/20/2022

// LMS contribution grade
// same value lecture and laboratory
const float quiz = 0.25f; // quiz 25%
const float exam = 0.5f; // exam 50%
const float lmsPreMid = 0.3f; // prelim and midterm 30%
const float lmsFinals = 0.4f; // finals 40%
const float lec = 0.6f; // lecture 60%
const float lab = 0.4f; // laboratory 40%
float laboratoryGrade, lectureGrade, overallGrade;
int option; // menu banner option

struct gradeLMS{ 
    float cutoffGrade;
    float gradePoint;
    std::string gradeLetter;
    std::string gradeletter;
};

gradeLMS gradesLMS[]{ //chart
    {96, 1.00, "A+", "a+"},
    {91, 1.25, "A", "a"},
    {86, 1.50, "A-", "a-"},
    {81, 1.75, "B+", "b+"},
    {75, 2.00, "B", "b"},
    {69, 2.25, "B-", "b-"},
    {63, 2.50, "C+", "c+"},
    {57, 2.75, "C", "c"},
    {50, 3.00, "C-", "c-"},
    {0, 5.00, "F", "f"}
};

class lectureC{
    float prelimQ1, prelimQ2, prelimExam,
        midtermQ1, midtermQ2, midtermExam,
        finalQ1, finalQ2, finalExam;

    float prelimTotal, midtermTotal, finalTotal;

    void Lecture() {
        // Prelim 
        std::cout << "Enter Prelim Quiz 1: ";
        std::cin >> prelimQ1;
        std::cout << "Enter Prelim Quiz 2: ";
        std::cin >> prelimQ2;
        std::cout << "Enter Prelim Exam: ";
        std::cin >> prelimExam;

        // Midterm 
        std::cout << "Enter Midterm Quiz 1: ";
        std::cin >> midtermQ1;
        std::cout << "Enter Midterm Quiz 2: ";
        std::cin >> midtermQ2;
        std::cout << "Enter Midterm Exam: ";
        std::cin >> midtermExam;

        //Finals
        std::cout << "Enter Final Quiz 1: ";
        std::cin >> finalQ1;
        std::cout << "Enter Final Quiz 2: ";
        std::cin >> finalQ2;
        std::cout << "Enter Final Exam: ";
        std::cin >> finalExam;

        system("cls");

        prelimTotal = ((prelimQ1 * quiz) + (prelimQ2 * quiz) + (prelimExam * exam));
        midtermTotal = ((midtermQ1 * quiz) + (midtermQ2 * quiz) + (midtermExam * exam));
        finalTotal = ((finalQ1 * quiz) + (finalQ2 * quiz) + (finalExam * exam));
    }
public:
    
    void lecture_total() {
        Lecture();

        lectureGrade = ((prelimTotal * lmsPreMid) + (midtermTotal * lmsPreMid) + (finalTotal * lmsFinals));
        
        std::cout << "Lecture Grade: " << lectureGrade << std::endl;
    }

};

class LaboratoryC
{
    lectureC lecC;
    float prelimLabQ1, prelimLabQ2, prelimLabExam, midtermLabQ1, 
        midtermLabQ2, midtermLabExam, finalLabQ1, finalLabQ2, finalLabExam;

    float prelimLabTotal, midtermLabTotal, finalLabTotal;

    void Laboratory() 
    {
        // Prelim 
        std::cout << "Enter Prelim Lab Quiz 1: ";
        std::cin >> prelimLabQ1;
        std::cout << "Enter Prelim Lab Quiz 2: ";
        std::cin >> prelimLabQ2;
        std::cout << "Enter Prelim Lab Exam: ";
        std::cin >> prelimLabExam;

        // Midterm 
        std::cout << "Enter Midterm Lab Quiz 1: ";
        std::cin >> midtermLabQ1;
        std::cout << "Enter Midterm Lab Quiz 2: ";
        std::cin >> midtermLabQ2;
        std::cout << "Enter Midterm Lab Exam: ";
        std::cin >> midtermLabExam;

        //Finals
        std::cout << "Enter Final Lab Quiz 1: ";
        std::cin >> finalLabQ1;
        std::cout << "Enter Final Lab Quiz 2: ";
        std::cin >> finalLabQ2;
        std::cout << "Enter Final Lab Exam: ";
        std::cin >> finalLabExam;

        system("cls");

        prelimLabTotal = ((prelimLabQ1 * quiz) + (prelimLabQ2 * quiz) + (prelimLabExam * exam));
        midtermLabTotal = ((midtermLabQ1 * quiz) + (midtermLabQ2 * quiz) + (midtermLabExam * exam));
        finalLabTotal = ((finalLabQ1 * quiz) + (finalLabQ2 * quiz) + (finalLabExam * exam));
    }
public:
    void laboratory_total() 
    { 
        Laboratory();
        
        laboratoryGrade = ((prelimLabTotal * lmsPreMid) + (midtermLabTotal * lmsPreMid) + (finalLabTotal * lmsFinals));

        
        overallGrade = ((lectureGrade * lec) + (laboratoryGrade * lab));

        std::cout << "Lecture Grade: " << lectureGrade << std::endl;
        std::cout << "Laboratory Grade: " << laboratoryGrade << std::endl;
           
        std::cout << "Overall Grade: " << overallGrade << std::endl;
    }
};


void gradepoint_to_lettergrade(float gwa)
{
    for (auto gradeLMS: gradesLMS)
    {
        if (gwa <= gradeLMS.gradePoint)
        {
            std::cout << "Grade: " << gradeLMS.gradeLetter << std::endl;
            break;
        }
    }
}

void lettergrade_to_gradepoint(std::string letterGrade)
{
    bool j = false;
    for (auto gradeLMS : gradesLMS)
    {
        if (letterGrade == gradeLMS.gradeLetter || letterGrade == gradeLMS.gradeletter)
        {    
            j = true;
            std::cout << "Grade: " << gradeLMS.gradePoint << std::endl;
            break;
        }

    }
    if (j == false)
    {
        system("cls");
        std::cout << "Error\n";
    }
        
    
}

// Base grade to 5 scale grade point
void basegrade_to_gradepoint(float baseGrade)
{   
    bool k = false;
    for (auto gradeLMS : gradesLMS)
    {
        if (gradeLMS.cutoffGrade <= baseGrade)
        {
            k = true;
            std::cout << "GWA: " << gradeLMS.gradePoint;
            std::cout << '\t' << gradeLMS.gradeLetter << std::endl;
            break;
        }
    }
    if (k == false)
    {
        system("cls");
        std::cout << "\nError";
    }  
}

void menu_banner()
{
        std::cout << "\n******************************************\n";
        std::cout << "********** LMS Grade Calculator **********\n";
        std::cout << "******************************************\n";
        std::cout << "1. Lecture or Laboratory\n";
        std::cout << "2. Lecture and Laboratory\n";
        std::cout << "3. Grade Point to Letter Grade\n";
        std::cout << "4. Letter Grade to Grade Point\n";
        std::cout << "5. Base Grade to Grade Point\n";
        std::cout << "0. Exit\n" << std::endl;
        std::cout << "\nEnter Number: ";
        std::cin >> option;
        system("cls");
}

int main()
{
    lectureC lecC;
    LaboratoryC labC;
    float gradepoint;
    std::string lGrade;
    float z;

    do
    {
        menu_banner();
        switch (option) {
        case 1:
            std::cout << "Lecture or Laboratory Calculator\n";
            std::cout << "\nNote: Enter Grade 0 - 100.\n" << std::endl;
            lecC.lecture_total();
            basegrade_to_gradepoint(std::round(lectureGrade));
            break;
        case 2:
            std::cout << "Lecture and Laboratory Calculator\n";
            std::cout << "\nNote: Enter Grade 0 - 100.\n";
            std::cout << "\nEnter Lecture Grades.\n" << std::endl;
            lecC.lecture_total();
            std::cout << "Enter Laboratory Grades.\n" << std::endl;
            labC.laboratory_total();
            basegrade_to_gradepoint(std::round(overallGrade));
            break;
        case 3:
            std::cout << "Grade Point to Letter Grade Converter\n";
            std::cout << "\nNote: Grade Point must be 1.00, 1.25, 1.50, 1.75, 2.00, 2.25, 2.50, 2.75, 3.00, and 5.00\n" << std::endl;
            std::cout << "\nEnter Grade Point: ";
            std::cin >> gradepoint;
            system("cls");
            gradepoint_to_lettergrade(gradepoint);
            break;
        case 4:

            std::cout << "Letter Grade to Grade Point\n";
            std::cout << "\nNote: Grade must be A+ to C- and F." << std::endl;
            std::cout << "\nEnter Letter Grade: ";
            std::cin >> lGrade;
            system("cls");
            lettergrade_to_gradepoint(lGrade);
            break;
        case 5:
            std::cout << "Base Grade to Grade Point\n";
            std::cout << "\nBase Grade must be 0 - 100." << std::endl;
            std::cout << "\nEnter Grade: ";
            std::cin >> z;
            system("cls");
            basegrade_to_gradepoint(std::round(z));
            break;
        }
    } while (option != 0);

    return 0;
}