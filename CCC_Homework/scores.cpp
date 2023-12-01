#include <iostream>
using namespace std;

bool isValid(int number)
{
    if (number < 0 || number > 100)
    {
        string InvalidScore = "ERROR: score is either negative or above 100.\n";
        throw InvalidScore;
    }
    return true;
}

int main(){
    int numTests;
    bool validity;
    int num = 0;
    int mean;

    cout << "Enter the number of test scores: ";
    cin >> numTests;

    // Dynamically allocate memory for input test scores
    int arr[numTests];

    try 
    {
        for (int i = 0; i < numTests; i++) 
        {
            cout << "Enter the test scores: " << '\n';
            cin >> arr[i];
            validity = isValid(arr[i]);
            num += arr[i];
        }
        mean = num/numTests;
        cout << "Mean: " << mean << "\n.";
    }

    catch(string InvalidScore)
    {
        cout << InvalidScore;
    }
    cout << "End of program.\n";
    return 0;
}
