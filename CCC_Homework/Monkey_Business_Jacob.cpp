#include<iostream>
#include <iomanip>
using namespace std;

// Constants
const int MONKEYS = 3;
const int DAYS = 5;

// Function prototypes
void getFoodEaten(int food[MONKEYS][DAYS]);
void displayAverageDaily(int food[MONKEYS][DAYS]);
void displayLeastEaten(int food[MONKEYS][DAYS]);
void displayMostEaten(int food[MONKEYS][DAYS]);

int main()
{
    // Get all values from user
    int food[MONKEYS][DAYS];
    // find average for each day which means add the column values and divide by 3 for the number of monkeys
    //displayAverageDaily(food);
    // Array to hold the monkey data
    getFoodEaten(food);
    // Get the amount eaten.
    // getFoodEaten(food);
    // Display the average amount eaten daily
    // by each monkey.
    displayAverageDaily(food);
    // Display the least amount eaten in a day
    // by any one monkey.
    displayLeastEaten(food);
    // Display the most eaten in a day
    // by any one monkey.
    displayMostEaten(food);
    return 0;
}

void getFoodEaten(int food[MONKEYS][DAYS]){
    for (int count = 0; count < MONKEYS; count++){
        for(int day = 0; day < DAYS; day++){
            cout << "Enter the pounds eaten by monkey number " << (count + 1) << " on day " << (day + 1) << ": ";
            cin >> food[count][day];
    }
}
}

void displayAverageDaily(int food[MONKEYS][DAYS]){
    int a = 0;
    for (int i = 0; i < 3; i++){
        a += food[i][0];
    }
    cout << "The average amount eaten on day 1 is " << (a/3) << "\n"; 

    int b = 0;
    for (int i = 0; i < 3; i++){
        b += food[i][1];
    }
    cout << "The average amount eaten on day 2 is " << (b/3) << "\n";

    int c = 0;
    for (int i = 0; i < 3; i++){
        c += food[i][2];
    }
    cout << "The average amount eaten on day 3 is " << (c/3) << "\n"; 

    int d = 0;
    for (int i = 0; i < 3; i++){
        d += food[i][3];
    }
    cout << "The average amount eaten on day 4 is " << (d/3) << "\n"; 

    int e = 0;
    for (int i = 0; i < 3; i++){
        e += food[i][4];
    }
    cout << "The average amount eaten on day 5 is " << (e/3) << "\n";
}

void displayLeastEaten(int food[MONKEYS][DAYS]){
    int leastEaten = 276447232;
    int mk;
    int dey;
    for (int count = 0; count < MONKEYS; count++){
        for(int day = 0; day < DAYS; day++){
            if (food[count][day] < leastEaten){
                leastEaten = food[count][day];
                mk = count;
                dey = day;
            }
            }
            }
    cout << "Monkey number " << (mk + 1) << " ate the least amount of food, " << (leastEaten) << " pound(s), on day " << (dey+1) << endl;

}

void displayMostEaten(int food[MONKEYS][DAYS]){
    int mostEaten = 0;
    int mk;
    int dey;
    for (int count = 0; count < MONKEYS; count++){
        for(int day = 0; day < DAYS; day++){
            if (food[count][day]>mostEaten){
                mostEaten = food[count][day];
                mk = count;
                dey = day;
            }
            }
            }
    cout << "Monkey number " << (mk + 1) << " ate the most amount of food, " << (mostEaten) << " pound(s), on day " << (dey+1) << endl;

}



