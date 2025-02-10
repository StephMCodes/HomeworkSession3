// HomeworkSession3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//it seems to be bad practice to use "using std" library (research more)


//////////////////////////////////////////////////////////////////////////
//                              TO DO                                   //
//Research \n vs endl; and understand when which is better              //
//Research how to customize the console colours                         //
//Research error handling                                               //
//////////////////////////////////////////////////////////////////////////

struct Course
{
    //difference between struct and class
    //members are default public
    //From Microsoft Learn:
    //"Structures are value types; classes are reference types" (research more)
    //"Structures use stack allocation; classes use heap allocation."

    std::string name;
    float midterm;
    float exam;
    float project;
};

bool IsInRange(int num)
{
    return (num >= 0 && num <= 100);
    //this checks if num is between 0 to 100 and returns true if so
}

void CourseToString(Course& course)
{
   //use << to insert the variables into the string not + like in csharp
    std::cout << "\nCourse: " << course.name << " Midterm: " << course.midterm << " Exam: " << course.exam << " Project: " << course.project << "\n";
}

void InputCourseInfo(Course& course, int courseNumber) {
    //we output a message
    std::cout << "\nEnter the name of the course " << courseNumber << ": ";
    //take input
    std::cin >> course.name;
    //remove unwanted characters like the user pressing \n
    std::cin.ignore();
    //repeat
    std::cout << "Enter the midterm grade of the course " << courseNumber << ": ";
    std::cin >> course.midterm;
    std::cin.ignore();
    //loop while the method returns false
    while (!IsInRange(course.midterm)) {
        //false: display error msg
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> course.midterm;
        std::cin.ignore();
    }

    std::cout << "Enter the project grade of the course " << courseNumber << ": ";
    std::cin >> course.project;
    while (!IsInRange(course.project)) {
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> course.project;
        std::cin.ignore();
    }

    std::cout << "Enter the final exam grade of the course " << courseNumber << ": ";
    std::cin >> course.exam;
    std::cin.ignore();

    while (!IsInRange(course.exam)) {
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> course.exam;
        std::cin.ignore();
    }
}
int main()
{
    std::cout << "Hello World! This is my C++ classwork!\n";
    //we need a const for the size of an array
    const int nbUserCourses = 3;
    Course userCourses[nbUserCourses];
    //loop for each possible course
    for (int i = 0; i < nbUserCourses; i++)
    {
        //get input of courses
        InputCourseInfo(userCourses[i], i + 1);
        //display courses
        CourseToString(userCourses[i]);
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
