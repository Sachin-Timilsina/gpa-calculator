#include <iostream>
#include <cctype>
#include <string>
#include <algorithm>
#include <iomanip>

/*
  *************************************************
  GPA Calculator (Grade Point Average Calculator.)
  *************************************************

  -The grade points table for the calculation is given in getTotalGradesPoint() function.
  -Formula Used is: GPA = Total Grade Points / Total Credits.
    Here,
    Total Grade Points = sum of all class(grade_points_of_that_class * credit_score_of_that_class.)
    Total Credits = Sum of all classes credits.
*/

//FUNCTION DECLARATIONS
void printInstructions();//Prints Instructions for Input.
int getClassesNumber();//Gets The Amount of class(subjects).
void getClassesInfo(int, std::string*, std::string*, float*);//Fills classes names, grades, credit hours each.
float getTotalCredits(float*, int);//Adds Up all classes credits.
float getTotalGradesPoint(int, std::string*, float*);//Adds up all of (grades_points * credits) of each class.
float calculateGPA(float, float);//Calculates gpa i.e. totalGradesPoints / totalCredits
float processGPA();//All auxiliary functions called from this to get final gpa.
void printGPA(float);//Prints the GPA formatted!


int main(){
  //Final Code...
  printInstructions();

  float gpa = processGPA();

  printGPA(gpa);

  return 0;
}

void printInstructions(){
  std::cout << "------------------------------------------------" << "\n";
  std::cout << "_______________GPA Calculator___________________" << "\n";
  std::cout << "------------------------------------------------" << "\n";
  std::cout <<"\n" << "Enter The Number of Classes You Have Taken." << "\n";
  std::cout << "Enter the class name, grades, credits respectively separated by space." << "\n";
  std::cout << "The Grade Points should be in letter form like: A+, A, B+, etc." << "\n";
  std::cout << "------------------------------------------------" << std::endl;
}

int getClassesNumber(){
  int classesNumber;
  std::cout << "Enter the number of classes: " << "\n";
  std::cin >> classesNumber;
  std::cin.ignore(); //Ignore extra other char in stream.
  return classesNumber;
}

void getClassesInfo(int classNumber, std::string* classNames, std::string* grades, float* credits){
  for (int i = 0; i < classNumber; i++) {
    std::cout << "Enter Class Name, Grades(In Letters), Credits respectively: " << "\n";

    std::cin >> classNames[i] >> grades[i] >> credits[i];
    std::cin.ignore();
  }
}

float getTotalCredits(float* credits, int classesNumber){
  float totalCredits = 0.0f;
  for (int i = 0; i < classesNumber; i++) {
    totalCredits += credits[i];
  }
  return totalCredits;
}

float getTotalGradesPoint(int classesNumber, std::string* grades, float* credits){
  float totalGradesPoint = 0.0f;

  for (int i = 0; i < classesNumber; i++) {
    //Convert string grade points into upperCase.
    std::transform(grades[i].begin(), grades[i].end(), grades[i].begin(), ::toupper);
    if (grades[i] == "A+") {
     totalGradesPoint += credits[i] * 4.0f;
   } else if (grades[i] == "A") {
     totalGradesPoint += credits[i] * 3.75f;
   } else if (grades[i] == "B+") {
     totalGradesPoint += credits[i] * 3.50f;
   } else if (grades[i] == "B") {
     totalGradesPoint += credits[i] * 3.00f;
   } else if (grades[i] == "C+") {
     totalGradesPoint += credits[i] * 2.50f;
   } else if (grades[i] == "C") {
     totalGradesPoint += credits[i] * 2.00f;
   } else if (grades[i] == "D+") {
     totalGradesPoint += credits[i] * 1.50f;
   } else if (grades[i] == "D") {
     totalGradesPoint += credits[i] * 1.00f;
   } else if (grades[i] == "F") {
     totalGradesPoint += credits[i] * 0.00f;
   } else {
     //In condition of invalid grade point output -1
     std::cout << "Invalid Grade Point Given: " << grades[i] << "\n";
     return -1;
   }
  }
  return totalGradesPoint;
}

float calculateGPA(float totalGradesPoint, float totalCredits){
  return totalGradesPoint / totalCredits;
}

float processGPA(){
  int classesNumber = getClassesNumber();
  std::string* classNames = new std::string[classesNumber];
  std::string* grades = new std::string[classesNumber];
  float* credits = new float[classesNumber];

  getClassesInfo(classesNumber, classNames, grades, credits);

  float totalCredits= getTotalCredits(credits, classesNumber);
  float totalGradesPoint = getTotalGradesPoint(classesNumber, grades, credits);
  //Checking for error
  if(totalGradesPoint == -1){
    return -1;
  }

  //Free Dynamic Memory.
  delete[] classNames;
  delete[] grades;
  delete[] credits;

  return calculateGPA(totalGradesPoint, totalCredits);
}

void printGPA(float gpa){
  std::cout << "------------------------------------------------" << "\n";
  std::cout << "_______________GPA: " << std::setprecision(2) << std::fixed << gpa << "__________________" << "\n";
  std::cout << "------------------------------------------------" << "\n";
}
