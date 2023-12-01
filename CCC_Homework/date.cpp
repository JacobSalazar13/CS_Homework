#include <iostream>
using namespace std;

class Date {       
  public:             
    int day;        
    int month;  
};

bool dayIsValid(int number)
{
    if (number < 1 || number > 31)
    {
        string InvalidDay = "ERROR: day number has to be < 1 or > 31.\n";
        throw InvalidDay;
    }
    return true;
}

bool monthIsValid(int number)
{
    if (number < 1 || number > 12)
    {
        string InvalidMonth = "ERROR: month number has to be < 1 or > 12.\n";
        throw InvalidMonth;
    }
    return true;
}

int main() {
    Date myDate;
    bool dayValidity;
    bool monthValidity;

    cout << "Enter a day number: ";
    try
    {
        cin >> myDate.day;
        dayValidity = dayIsValid(myDate.day);
    }
    catch(string InvalidDay)
    {
        cout << InvalidDay;
    }

    cout << "Enter a month number: ";
    try
    {
        cin >> myDate.month;
        monthValidity = monthIsValid(myDate.month);
    }
    catch(string InvalidMonth)
    {
        cout << InvalidMonth;
    }
    cout << "End of program.\n";
    return 0;
}