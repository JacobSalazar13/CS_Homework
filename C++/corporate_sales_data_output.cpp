#include <iostream>
#include <fstream>
using namespace std;

// Declaration of the Division structure
struct Division
{
    string divName;  // Division name
    int quarter[4];         // Quarter number
    double sales[4];        // Quarterly sales
};

int main()
{
    // File stream object for the corp.dat file
    fstream file("corp.dat", ios::out | ios::binary);

    // Division structure variables for each division
    Division east, west, north, south;

    // Loop counter for each quarter
    cout << "Enter the quarterly sales for the East Division:\n";
    east.divName = "East";
    for(int qtr = 0; qtr < 4; qtr++){
        cout << "Quarter " << (qtr + 1) << ": ";
        cin >> east.sales[qtr];
        while (east.sales[qtr] < 0){
            cout << "Please enter a value greater than 0 " << ": " << endl;
            cin >> east.sales[qtr];
        }
        east.quarter[qtr] = qtr + 1;
    }

    file << "East Quarterly Sales: \n";
    for (int j = 0; j < 4; j++){
        file << "Quarter " << j+1 << ": " << east.sales[j] << endl;
    }



    cout << "Enter the quarterly sales for the West Division:\n";
    west.divName = "West";
    for(int qtr = 0; qtr < 4; qtr++){
        cout << "Quarter " << (qtr + 1) << ": ";
        cin >> west.sales[qtr];
        while (west.sales[qtr] < 0){
            cout << "Please enter a value greater than 0 " << ": " << endl;
            cin >> west.sales[qtr];
        }
        west.quarter[qtr] = qtr + 1;
    }

    file << "West Quarterly Sales: \n";
    for (int j = 0; j < 4; j++){
        file << "Quarter " << j+1 << ": " << west.sales[j] << endl;
    }



    cout << "Enter the quarterly sales for the North Division:\n";
    north.divName = "North";
    for(int qtr = 0; qtr < 4; qtr++){
        cout << "Quarter " << (qtr + 1) << ": ";
        cin >> north.sales[qtr];
        while (north.sales[qtr] < 0){
            cout << "Please enter a value greater than 0 " << ": " << endl;
            cin >> north.sales[qtr];
        }
        north.quarter[qtr] = qtr + 1;
    }

    file << "North Quarterly Sales: \n";
    for (int j = 0; j < 4; j++){
        file << "Quarter " << j+1 << ": " << north.sales[j] << endl;
    }


    cout << "Enter the quarterly sales for the South Division:\n";
    south.divName = "South";
    for(int qtr = 0; qtr < 4; qtr++){
        cout << "Quarter " << (qtr + 1) << ": ";
        cin >> south.sales[qtr];
        while (south.sales[qtr] < 0){
            cout << "Please enter a value greater than 0 " << ": " << endl;
            cin >> south.sales[qtr];
        }
        south.quarter[qtr] = qtr + 1;
    }

    file << "South Quarterly Sales: \n";
    for (int j = 0; j < 4; j++){
        file << "Quarter " << j+1 << ": " << south.sales[j] << endl;
    }
    cout << "Successfully wrote sales data to corp.dat!";

    file.close();
}

