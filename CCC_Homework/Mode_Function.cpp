//In statistics, the mode of a set of values is the value that occurs most often or with the greatest frequency. Write a function that accepts as arguments the following:
// A) An array of integers
// B) An integer that indicates the number of elements in the array
// This function should determine the mode of the array. That is, it should determine which value in the array occurs most often.  The mode is the value the function should return.  If the array has no mode (none of the values occur more than once), the function should return -1. (Assume the array will always contain nonnegative values)
//Demonstrate your pointer prowess by using pointer notation instead of array notation in this function

#include<iostream>
#include <iomanip>
using namespace std;


int mode_function(int arr[], int size);

int main(){
    int mode;
    int size;
    cout << "How many elements are in your array? : ";
    cin >> size;
    int arr[size];

    for (int i=0; i < size; i++){
        cout << "What is the value for element " << (i) << " : ";
        cin >>  arr[i];
    }

    mode = mode_function(arr, size);

    cout << "The mode of your given array is: " << (mode);
}

int mode_function(int arr[], int size){
    //Initial placeholder variables
    int value = 0;
    int count_1 = 0;

    //iterate through the size of the array
    for (int i = 0; i < size; i++){
        //Set count equal to zero so that when you search you can count the occurences
        int count_2 = 0;
        //iterate the same size again so that we can compare all of the elements to the first element and so on and so forth
        for (int j = 0; j < size; j++){
            //if pointer value of the first loop for example 0, will be compared to pointer value of j and j is increasing.  So we are comparing the first element to all other elements in the array
            if (*(arr + j) == *(arr + i)){
            //If they are equal then increase count_2
                count_2++;
            }
        }
        //If the for loop found matches then the count_2 should be greater then count_1
        if (count_2 > count_1){
            //set count_1 equal to count_2 as a placeholder for the amount of occurrences
            count_1 = count_2;
            //Grab the value that had the most occurences
            value = *(arr +i);
        }
        //and if at the end count_1 is equal to 1 (case that there was no values repeating in the array) set the value to -1
        else if (count_1 == 1){
            value = -1;
        }

    }
    //return the value
    return value;


}