#include <iostream>
#include <iomanip>

using namespace std;

int prompt(){
    int choice;
    cout << "Program 1: Step Pyramids" << endl;
    cout << "Which option would you like?" << endl;
    cout << "  1. Display original graphic" << endl;
    cout << "  2. Display Step Pyramid" << endl;
    cout << "Your choice: ";
    cin >> choice;
    return choice;
}

int original_art(){
    int count = 1;
    for (int level = 0; level <= 17; level++){
        if (level == 0){
            cout << setw(3) << " " << "+++++++     +++++++" << setfill(' ') << setw(3) << endl;
            cout << setw(2) << " " << "+++++++++   +++++++++" << setfill(' ') << setw(2) << endl;
            cout << setw(1) << " " << "+++++++++++ +++++++++++" << setfill(' ') << setw(1) << endl;
        }
        else if((level >= 1) && (level <= 4)){
            cout << "+++++++++++++++++++++++++" << endl;
        }
        else{
            cout << setfill(' ') << setw(count) << " " << setfill('+') << setw(25 - (2 * count)) << "" << endl;
            count++;
        }
    }
    return 0;
}

int pyramid_art(int levels){
    int count = 0;
    int start = 2;
    for (int level_count = 1; level_count < (levels + 1); level_count++){

        if (level_count == 1){
            cout << setw(start + ((levels - 1) * 6)) << " " << "   _______" << endl;
            cout << setw(start + ((levels - 1) * 6)) << " " << "  |_______| " << endl;
            cout << setw(start + ((levels - 1) * 6)) << " " << "  |  ___  |  " << endl;
            cout << setw(start + ((levels - 1) * 6)) << " " << "__|__[_]__|__" << endl;
            cout << setw((start + ((levels - 1) * 6)) - 1) << " " << "/" << setw(4) << " " << "[===]" << setw(5) << "\\" << endl;
            cout << setw((start + ((levels - 1) * 6)) - 2) << " " << "/" << setw(5) << " " << "[===]" << setw(6) << "\\" << endl;
        }
        else if(level_count == levels){
            cout << setw(2) << " " << setfill('+') << setw(15 + count) << "[===]" << setfill('+') << setw(10 + count) << "" << endl;
            cout << setfill(' ') << setw(2) << "/" << setw(15 + count) << "[===]" << setw(11 + count) << "\\" << endl;
            cout << setfill(' ') << setw(1) << "/" << setw(16 + count) << "[===]" << setw(12 + count) << "\\" << endl;
        }
        else {
            cout << setw((start + ((levels - level_count) * 6))) << " " << setfill('+') << setw(15 + count) << "[===]" << setfill('+') << setw(10 + count) << "" << endl;
            cout << setfill(' ') << setw((start + ((levels - level_count) * 6))) << "/" << setw(15 + count) << "[===]" << setw(11 + count) << "\\" << endl;
            cout << setfill(' ') << setw((start + ((levels - level_count) * 6)) - 1) << "/" << setw(16 + count) << "[===]" << setw(12 + count) << "\\" << endl;
            count += 6;
        }
        }
    return 0;
}

int main() {
    // The menu output. Don't modify this, so that it outputs exactly as expected
    int choice;
    int levels;
    choice = prompt();

    if (choice < 0){
        while (choice < 0 || choice > 2){
            cout << "Please enter a valid integer" << endl << endl;
            choice = prompt();
        }
    }
    else if(choice == 2){
        int response;
        cout << "How many levels should be in the step pyramid? " << endl;
        cin >> levels;
        response = pyramid_art(levels = levels);
        return response;
    }
    else if(choice == 1){
        int response;
        response = original_art();
        if (response == 0){
            return 0;
        }
    }
}