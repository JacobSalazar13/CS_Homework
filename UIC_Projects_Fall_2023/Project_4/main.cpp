/** ---------------------------------------------
* This program demonstrates classes, constructors, vectors and other
* helpful concepts in C++ that students need to complete the
* Fourth project Restaurant Inspection.
* Class: CS 141, Fall 2023
* System: ZyBook Lab *
* @author Jacob Salazar
* @version November 1, 2023
* ---------------------------------------------- */

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <iomanip>
#include "restaurant.h"
using namespace std;


//function declarations
void risk_percentages(vector <Restaurant> restaurants);
void inspection_info(vector <Restaurant> restaurants);
void passing_neighborhoods(vector <Restaurant> restaurants);
void search_restaurant_name(vector <Restaurant> restaurants);
void search_restaurant_name(vector <Restaurant> restaurants);


// function that displays the options and takes 
int get_choice(){
    int choice;
    cout << "Select a menu option: " << endl;
	cout << "   1. Display overall inspection information" << endl;
	cout << "   2. Display risk percentages" << endl;
	cout << "   3. Display passing numbers by neighborhood" << endl;
	cout << "   4. Search for restaurant by name" << endl;
	cout << "   5. Exit" << endl;
	cout << "Your choice: " << endl;
    cin >> choice;
    return choice;
}

//This is a function that is used to check if the user inputted a valid choice
int check_choice(int choice){
    if (choice == 5){
        exit(1);
    }
    if (choice > 5 || choice < 1){
        cout << "Please use a valid number" << endl;
        while(choice > 5 || choice < 1){
            choice = get_choice();
        }
    }
    return choice;
}

//This is the function that handles the choice and calls ont of the option functions
void choice_handler(int choice, vector <Restaurant> restaurants){
    if (choice == 1){
        //if one call inspection function
        inspection_info(restaurants);
    }
    else if (choice == 2){
        //if two call risk percentage function
        risk_percentages(restaurants);
    }
    else if (choice == 3){
        //if three call the passing neighborhoods
        passing_neighborhoods(restaurants);
    }
    else if (choice == 4){
        //if four call the search restaurant function
        search_restaurant_name(restaurants);
    }

}


//this function handles the output of the inspection info or option 1
void inspection_info(vector <Restaurant> restaurants){
    int count = restaurants.size();
    int count_passed = 0;
    int day;
    int month;
    int year;
    int recent_year_inspection = 0;
    int recent_day_inspection = 0;
    int recent_month_inspection = 0;

    int index = 0;

    //iterate through the vector and check if the inspection passed or was conditional
    for (int x = 0; x < count; x++){
        if (restaurants[x].getInspection() == "Pass" || restaurants[x].getInspection() == "Conditional"){
            count_passed++;
        }
    }

    //iterate through the vector and check if the inspection passed or was conditional and if it is grab the month day and year from each element in the vector
    for (int x = 0; x < count; x++){
        if (restaurants[x].getInspection() == "Pass" || restaurants[x].getInspection() == "Conditional"){
            //grab substrings from the return of the getDate from the Restaurant class function and turn it into an integer
            month = stoi(restaurants[x].getDate().substr(0, 2));
            day = stoi(restaurants[x].getDate().substr(3, 2));
            year = stoi(restaurants[x].getDate().substr(6, 5));
            //check if the year is greater than the lowest counter
            if(year > recent_year_inspection){
                recent_day_inspection = day;
                recent_month_inspection = month;
                recent_year_inspection = year;
                index = x;
            }
            //if the year is the same then check the month
            else if (year == recent_year_inspection){
                //check if month is the smallest month
                if (month > recent_month_inspection){
                    recent_day_inspection = day;
                    recent_month_inspection = month;
                    recent_year_inspection = year;
                    index = x;
                }
                //if month is the same then check the day
                else if(month == recent_month_inspection){
                    if (day > recent_day_inspection){
                        recent_day_inspection = day;
                        recent_month_inspection = month;
                        recent_year_inspection = year;
                        index = x;
                    }
                }
            }
        }
    }
    //output the count of restaurants the number that passed and the most recent passing inspection using the index found from the for loops above
    cout << "Number of restaurants: " << count << endl;
    cout << "Number that pass: " << count_passed << endl;
    cout << "Most recent passing inspection was of " << restaurants[index].getName() << " on " << restaurants[index].getDate() << endl;
}

//function that calculates the risk percentages
void risk_percentages(vector <Restaurant> restaurants){
    double count = restaurants.size();
    double high_count = 0;
    double medium_count = 0;
    double low_count = 0;
    double high_average = 0;
    double medium_average = 0;
    double low_average = 0;

    //iterate through the vector and count the number of high medium and low with the restaurant vector
    for (int x = 0; x < count; x++){
        if (restaurants[x].getRisk() == 'H'){
            high_count++;
        }
        else if (restaurants[x].getRisk() == 'M'){
            medium_count++;
        }
        else if (restaurants[x].getRisk() == 'L'){
            low_count++;
        }
    }
    //calculate the average of the number of high medium and low
    high_average = (high_count / count) * 100;
    medium_average = (medium_count / count) * 100;
    low_average = (low_count / count) * 100;

    //using the iomanip library I use the fixed stream manipulator that allows for float values to be displayed in fixed point notation
    cout << fixed;
    cout << setprecision(1) << "High risk: " << high_average << "%" << endl;
    cout << setprecision(1) << "Medium risk: " << medium_average << "%" << endl;
    cout << setprecision(1) << "Low risk: " << low_average << "%" << endl;
}

//this is the function that calculates the passing neighborhoods
void passing_neighborhoods(vector <Restaurant> restaurants){
    int count = restaurants.size();
    vector <string> neighborhoods;

    //iterate through the restaurant vector and grab all of the neighborhoods from each element in the Restaurant vector and save it in a string vector
    for (int i = 0; i < count; i++){
        neighborhoods.push_back(restaurants[i].getNeighborhood());
    }
    //sort the string vector
    sort(neighborhoods.begin(), neighborhoods.end());
    //using the erase function and the unique method I delete all of the duplicate values within the neighborhoods vector
    neighborhoods.erase(unique(neighborhoods.begin(), neighborhoods.end()), neighborhoods.end());

    //display the start of the output of the neighborhoods and their inspection values
    cout << "Neighborhood     Passed     Cond. Pass     Failed" << endl;
    cout << "============     ======     ==========     ======" << endl;

    //iterate through the neighborhoods vector
    for(int j = 0; j < neighborhoods.size(); j++){
        int passed_count = 0;
        int failed_count = 0;
        int cond_count = 0;
        //for each value in the neighborhoods vector check the restaurants vector and count the number that were passed conditional and failed
        for(int i = 0; i < count; i++){
            if (restaurants[i].getNeighborhood() == neighborhoods[j] && restaurants[i].getInspection() == "Pass"){
                passed_count++;
            }
            else if(restaurants[i].getNeighborhood() == neighborhoods[j] && restaurants[i].getInspection() == "Conditional"){
                cond_count++;
            }
            else if (restaurants[i].getNeighborhood() == neighborhoods[j] && restaurants[i].getInspection() == "Fail"){
                failed_count++;
            }
        }
        //display each neighborhood and the counts for the inspection 
        cout << neighborhoods[j] << "     " << passed_count << "     " << cond_count << "     " << failed_count << endl;
    }
}


//this function allows the user to input keywords and find restaurants with names that contain the keyword
void search_restaurant_name(vector <Restaurant> restaurants){
    int count = restaurants.size();
    string keyword;
    string keyword1;
    string keyword2;
    int checking;
    vector <int> indexes;

    //get the restaurant name keyword from the user was having trouble with getline so had to use cin and take in two keywords
    cout << "Enter restaurant to search for:";
    cin >> keyword1 >> keyword2;
    keyword = keyword1 + " " + keyword2;

    //turn the keyword to upper because the input file is capitalized
    for (int i = 0; i < keyword.length(); i++){
        keyword[i] = toupper(keyword[i]);
    }    
    //iterate through the restaurant vector and check if the name contains the keyword
    for (int i = 0; i < count; i++){
        checking = restaurants[i].getName().find(keyword);
        //if the keyword was found save the index in an integer vector called indexes
        if(checking != string::npos){
            indexes.push_back(i);
        }
    }

    //for each index in the index vector display the associated Restaurant object attributes
    for (int j = 0; j < indexes.size(); j++){
        cout << "Restaurant: " << restaurants[indexes[j]].getName() << endl;
        cout << "Address: " << restaurants[indexes[j]].getAddress() << endl;
        cout << "Inspection Date: " << restaurants[indexes[j]].getDate() << endl;
        cout << "Inspection Result: " << restaurants[indexes[j]].getInspection() << endl;
        cout << endl;
    }

}

//prompt to grab filename from user
string get_file(){
    string filename;
    cout << "Enter the data file to use: ";
    cin >> filename;
    return filename;
}


int main() {
    string filename;
    string restaurantName;
    string restaurantAddress;
    string restaurantDate;
    string restaurantInspection;
    string restaurantNeighborhood;
    string row;
    vector<Restaurant> restaurants;
    Restaurant restaurant;
    int choice;

    //call get file function
    filename = get_file();
    //open file name
    ifstream file(filename);

    //loop to grab each row from the txt file from the user
    while (getline(file, row)){
        //for each row in the txt file we need to set the attributes to empty strings
        restaurantName = "";
        restaurantAddress = "";
        restaurantDate = "";
        char restaurantRisk;
        restaurantInspection = "";
        restaurantNeighborhood = "";
        int count = 0;
        //iterate through the each character in the row and check if it is a comma
        for (int i = 0; i < row.length(); i++){
            if (row[i] != ','){
                //if character is not a comma then check count to see where in the row you are and save it to the associated variable
                if (count == 0){
                    restaurantName += row[i];
                }
                else if (count == 1){
                    restaurantAddress += row[i];
                }
                else if (count == 2){
                    restaurantDate += row[i];
                }
                else if (count == 3){
                    restaurantRisk = row[i];
                }
                else if (count == 4){
                    restaurantInspection += row[i];
                }
                else if (count == 5){
                    restaurantNeighborhood += row[i];
                }
            }
            else{
                //if the character is a comma then increment count so that we know which variable we are handling in the row this count gets set back to 0 for each row
                count++;
            }

        }
        //create restaurant object using the variables from each row in the file
        restaurant.setAttributes(restaurantName, restaurantAddress, restaurantDate, restaurantRisk, restaurantInspection, restaurantNeighborhood);
        //save the object in the vector restaurant vector
        restaurants.push_back(restaurant);
    }
    //close the file
    file.close();

    //call get choice then check the choice and call the choice handler functions
    choice = get_choice();
    choice = check_choice(choice);
    choice_handler(choice, restaurants);

    return 0;
}