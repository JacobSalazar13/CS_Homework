#include<iostream>
#include <iomanip>
#include<string>

using namespace std;

char getgrade(double average);

struct Student {
    string name;
    string idNum;
    int *tests;
    double average;
    char grade;
};


int main(){
    int numTests;
    int num_students;
    string id;
    int sum;
    int score;
    double avg;

    cout << "How many test scores would you like to input: ";
    cin >> numTests;
    cout << "How many students do you have?: ";
    cin >> num_students;
    for (int i = 0; i < num_students; i++){
        Student temp;
        cout << "Enter the id of the student:";
        cin >> temp.idNum[i];
        for (int x = 0; x < numTests; x++){
            cout << "Enter the score for test number " << (x +1) << "for student number " << (i + 1) << ": " << endl;
            cin >> score;
            while(score < 0){
                cout << "Enter the score for test number " << (i +1) << "that is greater than 0: " << endl;
                cin >> score;
            }
            temp.tests[x] = score;
            sum += score;
            temp.average = sum/numTests;
            temp.grade = getgrade(temp.average);
            cout << "Here are the grades for ";
        }
    
    
    /*couldnt finish */
    

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