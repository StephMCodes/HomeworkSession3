// HomeworkSession3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

//it seems to be bad practice to use "using std" library (research more)


//////////////////////////////////////////////////////////////////////////
//                              TO DO                                   //
//Research \n vs endl; and understand when which is better              //
//Turn the int check into a function                                    //
// Make more checks so its not all 1-100                                //                              //
//Research error handling                                               //
//HOW TO DELETE ARRAYS AND WHATS INSIDE                                 //
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

//for next assignment create a student struct
struct Student
{
    std::string name;
    int id;
    //double grade;
    double* grades;
};

class TimeTravel
{
public: int currentYear, destinationYear;

      TimeTravel(int currentYear, int destinationYear)
          : currentYear(currentYear), destinationYear(destinationYear)
      {
          //set to default value
          this->currentYear = 2025;
          //for now they can be the same
          this->destinationYear = this->currentYear;
      }

      void SetDestination()
      {
          std::cout << "Enter the destination year for the TARDIS: \n";
          std::cin >> this->destinationYear;
          while (!std::cin.good() && this->destinationYear >= 1900 && this->destinationYear <= 2100) {
              //clear error state of cin
              std::cin.clear();
              //clear console. needs the overloads
              std::cin.ignore(INT_MAX, '\n');
              std::cout << "Must be an integer that is valid (1900-2100). Please try again: \n";
              std::cin >> this->destinationYear;
              std::cin.ignore();
          }
      }

      void Travel()
      {
          std::cout << "Travelling to the year... " << this->destinationYear << "!\n";
          this->currentYear = this->destinationYear;
      }

      void Explore(int currentYear)
      {
          if (currentYear < 2000)
          {
              std::cout << "Exploring the year... " << destinationYear << "... you seem to like the past!\n";

          }
          else {
              std::cout << "Exploring the year... " << destinationYear << "... you seem to like the future!\n";
          }
      }
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

    //repeat for ints but there is a caveat: error handling!
    //if user enters a letter, the console freaks out, so we must add extra code
    std::cout << "Enter the midterm grade of the course " << courseNumber << ": ";
    std::cin >> course.midterm;
    std::cin.ignore();
    
    //loop while the method returns false AND the input is not integer
    while (!std::cin.good() || !IsInRange(course.midterm)) {
        //clear console. needs the overloads
        std::cin.clear();
        //clear console. needs the overloads
        std::cin.ignore(INT_MAX, '\n'); 
        //false: display error msg
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> course.midterm;
        std::cin.ignore();
    }

    std::cout << "Enter the project grade of the course " << courseNumber << ": ";
    std::cin >> course.project;
    std::cin.ignore();
    while (!std::cin.good() || !IsInRange(course.project)) {
        //clear error state of cin
        std::cin.clear();
        //clear console. needs the overloads
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> course.project;
        std::cin.ignore();
    }

    std::cout << "Enter the final exam grade of the course " << courseNumber << ": ";
    std::cin >> course.exam;
    std::cin.ignore();

    while (!std::cin.good() || !IsInRange(course.project)) {
        //clear error state of cin
        std::cin.clear();
        //clear console. needs the overloads
        std::cin.ignore(INT_MAX, '\n');
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> course.exam;
        std::cin.ignore();
    }
}

void InputStudentInfo(Student& student) {
    //we output a message
    std::cout << "\nEnter the name of a new student: ";
    //take input
    std::cin >> student.name;
    //remove unwanted characters like the user pressing \n
    std::cin.ignore();

    //repeat for ints but there is a caveat: error handling!
    //if user enters a letter, the console freaks out, so we must add extra code
    std::cout << "Enter the ID (1-100) number of " << student.name << ": ";
    std::cin >> student.id;
    std::cin.ignore();

    //loop while the method returns false AND the input is not integer
    while (!std::cin.good() || !IsInRange(student.id)) {
        //clear console. needs the overloads
        std::cin.clear();
        //clear console. needs the overloads
        std::cin.ignore(INT_MAX, '\n');
        //false: display error msg
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> student.id;
        std::cin.ignore();
    }
}

void StudentToString(Student& student)
{
    std::cout << "\nName: " << student.name << " ID: " << student.id;
}

int main()
{
    int numStudents;
    int numSubjects;
    
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

    //ASSIGNMENT 2
    std::cout << "Enter the number of students (0-100): ";
    std::cin >> numStudents;
    std::cin.ignore();

    //loop while the method returns false AND the input is not integer
    while (!std::cin.good() || !IsInRange(numStudents)) {
        //clear console. needs the overloads
        std::cin.clear();
        //clear console. needs the overloads
        std::cin.ignore(INT_MAX, '\n');
        //false: display error msg
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> numStudents;
        std::cin.ignore();
    }

    std::cout << "Enter the number of subjects (0-100): ";
    std::cin >> numSubjects;
    std::cin.ignore();

    //loop while the method returns false AND the input is not integer
    while (!std::cin.good() || !IsInRange(numSubjects)) {
        //clear console. needs the overloads
        std::cin.clear();
        //clear console. needs the overloads
        std::cin.ignore(INT_MAX, '\n');
        //false: display error msg
        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        std::cin >> numSubjects;
        std::cin.ignore();
    }

    //dynamic allocation of a pointer on student array
    //RESEARCH MORE
    Student* StudentsArray = new Student[numStudents];

    //dynamic heap array
    Course* SubjectsArray = new Course[numSubjects];


    //input student info
    for (int i = 0; i < numStudents; i++)
    {
        InputStudentInfo(StudentsArray[i]);
        /*for (int i = 0; i < nbUserCourses; i++)
        {
        }*/

        //for (int j = 0; j < numSubjects; ++j) {
        //    std::cout << "Enter grade for subject " << j + 1 << ": ";
        //    std::cin >> StudentsArray[i].grade;
        //    std::cin.ignore();

        //    //loop while the method returns false AND the input is not integer
        //    while (!std::cin.good() || !IsInRange(numSubjects)) {
        //        //clear console. needs the overloads
        //        std::cin.clear();
        //        //clear console. needs the overloads
        //        std::cin.ignore(INT_MAX, '\n');
        //        //false: display error msg
        //        std::cout << "Must be an integer between 0 and 100. Please try again: ";
        //        std::cin >> numSubjects;
        //        std::cin.ignore();
        //    }
        //}
    }
    //display student info
    for (int i = 0; i < numStudents; i++)
    {
        StudentToString(StudentsArray[i]);
    }

    //memory cleanup
    for (int i = 0; i < numStudents; ++i)
    {
       // delete[] StudentsArray;
       // delete[] SubjectsArray;
        //RESEARCH
    }








    //reading invalid data error: RESEARCH
    ////loop for each possible course
    //for (int i = 0; i < numSubjects; i++)
    //{
    //    //get input of courses
    //    InputCourseInfo(subjects[i], i + 1);
    //    //display courses
    //    CourseToString(subjects[i]);
    //}
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
