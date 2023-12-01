#include<iostream>
#include <iomanip>
#include<string>

using namespace std;

struct Student {
    char name[100];
    char idNum[100];
    int *tests;
    double average;
    char grade;
};

char getgrade(double average);
Student *allocateArray(int numTests, int num_students);
void getdata(Student arr[], int numTests, int num_students);

int main(){
    int numTests;
    int num_students;
    Student *arr;

    cout << "How many test scores would you like to input: ";
    cin >> numTests;
    cout << "How many students do you have?: ";
    cin >> num_students;

    arr = allocateArray(numTests, num_students);
    getdata(arr, numTests, num_students);

    for(int j = 0; j < num_students; j++){
        cout << "Student id: " << arr[j].idNum << endl;
        cout << "Student name: " << arr[j].name << endl;
        cout << "Average test score: " << arr[j].average << endl;
        cout << "Grade: " << arr[j].grade << endl;
    }
    }


Student *allocateArray(int numTests, int num_students){
    Student *ptr;
    ptr = new Student[num_students];

    for (int a = 0; a < num_students; a++){
        ptr[a].tests = new int[numTests];
    }
    return ptr;
}

void getdata(Student arr[], int numTests, int num_students){
    for (int i = 0; i < num_students; i++){
        cin.ignore();
        cout << "Enter the id of the student:";
        cin.getline(arr[i].idNum, 100);
        while(strlen(arr[i].idNum) <= 0){
            cout << "Enter the students id that is longer than 0 characters: ";
            cin.getline(arr[i].idNum, 100);
        }
        cout << "Enter student " << (i+1) << "'s name: ";
        cin.getline(arr[i].name, 100);
        while (strlen(arr[i].name) <= 0){
            cout << "Enter the students name that is longer than 0 characters: ";
            cin.getline(arr[i].name, 100);
        }
        int sum = 0;
        for (int x = 0; x < numTests; x++){
            cout << "Enter the score for test number " << (x +1) << ": " << endl;
            cin >> arr[i].tests[x];
            while (arr[i].tests[x] < 0){
                cout << "Please enter a test score greater than 0 " << ": " << endl;
                cin >> arr[i].tests[x];
            }
            sum += arr[i].tests[x];
        }
        arr[i].average = sum/numTests;
        arr[i].grade = getgrade(arr[i].average);
        }

}

char getgrade(double average){
    char grade;
    if (average > 91.0) {
        grade = 'A';
    }
    else if (average > 81.0) {
        grade = 'B';
    }
    else if (average > 71.0) {
        grade = 'C';
    }
    else if (average > 61.0) {
        grade = 'D';
    }
    else {
        grade = 'F';
    }
    return grade;
}