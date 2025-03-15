// HomeworkSession3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <windows.h>

//it seems to be bad practice to use "using std" library (research more)


//////////////////////////////////////////////////////////////////////////
//                              TO DO                                   //
//Research \n vs endl; and understand when which is better              //
//Turn the int check into a function                                    //
// Make more checks so its not all 1-100                                //                              //
//Research error handling                                               //
//HOW TO DELETE ARRAYS AND WHATS INSIDE                                 //
//Binary search trees and complexity level                              //
//Study recursion                                                       //
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
          while (!std::cin.good() || this->destinationYear <= 1900 || this->destinationYear >= 2100) {
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
    std::cout << "\nName: " << student.name << " ID: " << student.id << std::endl;
}

int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
void findDuplicates(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                std::cout << "Duplicate: " << arr[i] << std::endl;
            }
        }
    }
}

int binarySearch(int arr[], int left, int right, int target) {
    while (left <= right) {
        //get the middle value to see if the searched value is higher or lower
        int mid = left + (right - left) / 2; //we truncate the value (no decimals)
        //check if its actually the middle value if so return it (best case scenario)
        if (arr[mid] == target) return mid;
        //else if its above the midpoint, adjust the left so we start there next loop
        else if (arr[mid] < target) left = mid + 1;
        //else if under midpoint, adjust likewise
        else right = mid - 1;
    }
    return -1; //return false if its not there
}

int main()
{
    //ASSIGNMENT 4
    LARGE_INTEGER start, end, freq;
    double elapsedTime;

    QueryPerformanceFrequency(&freq);
    QueryPerformanceCounter(&start);
    //COMPLEXITY EXAMPLE 1
    /*int arr[] = {1, 2, 3, 4, 5};
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Sum: " << sumArray(arr, n) << endl;*/
    //RESULTS
    /*Time complexity: O(n) linear time(more values / complexity = more time)
        Different test values :
        Sum 15 : Time taken : 0.0004721 to 0.0008021
        Sum : 55 Time taken : 0.0016786
        Sum : 210 Time taken : 0.0017592
        Growth Observations : it grows the more values
        we have in the array to add*/


    //ex2
   /* int arr[] = { 1, 2, 3, 2, 5, 5,5,5,4,4,3,2,1,1 };
    int n = sizeof(arr) / sizeof(arr[0]);
    findDuplicates(arr, n);*/
    //RESULTS
//    Time complexity using  Big o annotation : quadratic
//        Different test values :
//Duplicate: 1
//Duplicate : 2
//Time : 0.0018899
//Duplicate : 1
//Duplicate : 1
//Duplicate : 2
//Duplicate : 2
//Duplicate : 3
//Duplicate : 2
//Duplicate : 5
//Duplicate : 5
//Duplicate : 5
//Duplicate : 5
//Duplicate : 5
//Duplicate : 5
//Duplicate : 4
//Duplicate : 1
//Time : 0.0074998
//Growth Observations : simple nested loop

    //ex3
    int arr[] = { 1, 2, 3, 4, 5,6, 7,8, 9,10, 11,12,13,14,15,16,17,18,19,20,21,22,23,244,25,26,27,28,29,30,31,32,34,35,36,37,38,39,40 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 23;
    int index = binarySearch(arr, 0, n - 1, target);
    if (index != -1) std::cout << "Found at index: " << index << std::endl;
    else std::cout << "Not found" << std::endl;

    //COMPLEXITY RESULT
    //big o: o(log) (unless found on first try o(1))
    //it gets more constant the bigger the number because we use halving technique
    //Found at index : 3, Time : 0.0005498
    //Not found, Time: 0.0009344
    //Found at index : 17, Time : 0.0015286
    //Found at index : 22 Time : 0.0012976

    QueryPerformanceCounter(&end);
    elapsedTime = static_cast<double>(end.QuadPart - start.QuadPart) / freq.QuadPart;
    std::cout << "Time: " << elapsedTime << std::endl;
    return 0;

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

    //ASSIGNMENT 3
    //create instance of timetravel object
    TimeTravel tardis(0, 0);
    //ask for destination and check if its valid
    tardis.SetDestination();
    //change current year to destination
    tardis.Travel();
    //display a small message based on your current year
    tardis.Explore(tardis.currentYear);

    //ASSIGNMENT 4





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
