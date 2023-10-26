#include<iostream>
#include <iomanip>

using namespace std;

int main(){
    //create the array of string for the given names and numbers
    string ls[] = {"Alejandra Cruz, 555-1223", "Joe Looney, 555-0097", "Geri Palmer, 555-8787", "Li Chen, 555-1212", "Holly Gaddis, 555-8878", "Sam Wiggins, 555-0998", 
    "Bob Kain, 555-8712", "Tim Haynes, 555-7676", "Warren Gaddis, 555-9037", "Jean James, 555-4939", "Ron Palmer, 555-2783"};

    //Ask user for the string to search for
    char name[20];
    cout << "Please enter a name or a partial name to search for in the array: ";
    cin.getline(name, 20);

    //iterate through the array to compare the given string to search for
    for (int i = 0; i < 11; i++){
        //use the find function which returns a value of size_t
        auto output = ls[i].find(name);
        //npos is a static member constant value with the greatest possible value for an element of type size_t
        if (output != string::npos){
            //print the value in the array for when the ouput is not equal
            cout << ls[i] << endl;
        }
    }
}