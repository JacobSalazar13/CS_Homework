#include <iostream>

#include <iomanip> // std::setprecision

using namespace std;

/* structure declaration for data of a student */

struct StudentData{
    string studentName;
    int studentID;
    int* Tests;
    double average;
    char Grade;

}; 
// end of StudentData structure

// fuctions prototypes

void getStudentData(StudentData[], int, int);
void calculateGrade(StudentData[], int, int);
void displayResults(StudentData[], int);
// start main function

int main(){
// variables declaration
    int numberOfTests;
    int numberOfStudents;
    cout << "How many students do you have? ";
    while(true){
    // prompt the user to enter the number of students
    cin >> numberOfStudents;
    if(numberOfStudents<=0){
        cout<<"Must have at least 1 student!"<<endl;
        cout<<"Please re-enter: ";
        continue;
    }
    else{
        break;
    }
    // prompt the user to enter the number of tests
    cout <<"How many tests do you have grades for?";
    while(true){

    cin >> numberOfTests;

    if(numberOfTests<=0){
        cout<<"Must have at least 2 tests!"<<endl;
        cout<<"Please re-enter:";
        continue;
        }
    else{
        break;
}
// allocate an array of type StudentData dynamically
StudentData *dataOfStudents = new StudentData[numberOfStudents];
/* allocate an array of type Tests for every student dynamically */
int student = 0;
while (student < numberOfStudents){
    dataOfStudents[student].Tests = new int[numberOfTests];
    student++;
} // end while

/* call the getStudentData function to get the data of all students from the user */
getStudentData(dataOfStudents, numberOfStudents, numberOfTests);
/* call the calculateGrade function to find the grades of all students */
calculateGrade(dataOfStudents, numberOfStudents, numberOfTests);
/* call the displayResults function to display the details of all students */
displayResults(dataOfStudents, numberOfStudents);
// pause the system for a while
system("pause");
return 0;

} // end of main function

// getStudentData function definition

void getStudentData(StudentData studentDetails[], int totalStudents, int totalTests){
    int testScore;
// outer loop
    string name;
    for (int student = 0; student < totalStudents; student++){
// prompt the user to enter the name of student
        cout << endl;
        cin.ignore();

cout << "Enter student name :";

getline(cin,name);

studentDetails[student].studentName=name;

/* prompt the user to enter the ID number of student */

cout << "Enter the ID number: ";

cin >> studentDetails[student].studentID;

// inner loop

for (int test = 0; test < totalTests; test++)

{

/* prompt the user to enter test scores for all tests */

cout << "Enter test score " << (test + 1) << ": ";

cin >> testScore;

/* verify whether the test score is a negative number or not */

while (testScore < 0)

{

cout << "Enter a positive value: ";

cin >> testScore;

} // end while

// store the test score

studentDetails[student].Tests[test] = testScore;

} // end inner loop

} // end outer loop

} // end of getStudentData function

// calculateGrade function definition

void calculateGrade(StudentData studentDetails[], int totalStudents, int totalTests)

{

double totalScore;

for (int student = 0; student < totalStudents; student++)

{

// calculate the total score

totalScore = 0;

for (int test = 0; test < totalTests; test++)

totalScore += studentDetails[student].Tests[test];

// calculate the average score

studentDetails[student].average = totalScore / totalTests;

//find the average according to the average score

if (studentDetails[student].average > 90)

studentDetails[student].Grade = 'A';

else if (studentDetails[student].average > 80)

studentDetails[student].Grade = 'B';

else if (studentDetails[student].average > 70)

studentDetails[student].Grade = 'C';

else if (studentDetails[student].average > 60)

studentDetails[student].Grade = 'D';

else

studentDetails[student].Grade = 'F';

}

} // end of calculateGrade function

void displayResults(StudentData stddata[],int no_of_Students)

{

//Setting the precision to one decimal place

std::cout << std::setprecision(1) << std::fixed;

cout<<"Grade Report"<<endl;

cout<<"Name\t\tIDNum\tAverage\tGrade"<<endl;

for(int i=0;i<no_of_Students;i++)

{

cout<<setw(15)<<left<<stddata[i].studentName<<"\t";

cout<<stddata[i].studentID<<"\t";

cout<<stddata[i].average<<"\t";

cout<<stddata[i].Grade<<endl;

}

}