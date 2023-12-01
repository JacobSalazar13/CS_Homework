#include<iostream>
#include <iomanip>
using namespace std;

void binarysearch(int arr[], int value, int size);
void linearsearch(int arr[], int value, int size);
int * sortArray(int arr[], int value, int size);

int main(){
    //Get array from user
    int size;
    int value;
    cout << "How many elements are in your array? : ";
    cin >> size;
    if (size < 20){
        cout << "Your array needs to have 20 elements or more.  Try Again.  How many elements are in your array? : ";
        cin >> size;
    }
2
    int arr[size];
    for (int i=0; i < size; i++){
        cout << "What is the value for element " << (i) << " : ";
        cin >>  arr[i];
    }
    //Get value to search
    cout << "What is the value you would like to search for? : ";
    cin >> value;

    //Call linear search and return element the value is located in and the number of comparisons the function made
    linearsearch(arr, value, size);
    //Call binary search and return element the value is located in and the number of comparisons the function made
    binarysearch(arr, value, size);
    return 0;

}

int * sortArray(int arr[], int value, int size){
    int maxElement;
    for (maxElement = size - 1; maxElement > 0; maxElement--){
        for (int index = 0; index < maxElement; index++){
            if (arr[index] > arr[index + 1]){
                swap(arr[index], arr[index + 1]);
            }
        }
    }
    return arr;
}

void binarysearch(int arr[], int value, int size){
    arr = sortArray(arr, size, value);
    int comparisons = 0;
    int first = 0;
    int last = size - 1;
    int middle;
    int index;
    while (first <= last){
        middle = (first + last) / 2;
        comparisons ++;
        if (arr[middle] == value){
            index = middle;
            cout << "Using a binary search your value " << (value) << " was found at the index " << (index) << "after sorting the array" << endl;
            cout << "Using a binary search there were " << (comparisons) << " comparisons made before finding the above index" << endl;
            break;
        }
        else if (arr[middle] > value){
            last = middle - 1;
        }
        else{
            first = middle + 1;
        }
    
    }
}

void linearsearch(int arr[], int value, int size){
    int comparisons = 0;
    for (int i = 0; i < size; i++){
        if (arr[i] == value){
            cout << "Using a linear search your value " << (value) << " was found at the index " << (i) << endl;
            cout << "Using a linear search there were " << (comparisons) << " comparisons made before finding the above index" << endl;
        }
        comparisons++;
    
    }

}