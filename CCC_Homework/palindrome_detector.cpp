#include <iostream>
#include <string>
using namespace std;



bool is_palindrome(string word, int start, int end) {
    if (start >= end) {
        return true;
    } else if (word[start] != word[end]) {
        return false;
    } else {
        return is_palindrome(word, start + 1, end - 1);
    }
}


int main() {
    string test_string;
    bool response;
    string result;
    string test_strings[] = {
        "civic",
        "Jacob",
        "radar",
        "coding",
        "level",
    };

    int array_length = sizeof(test_strings)/sizeof(test_strings[0]);

    for (int i = 0; i < array_length; ++i) {
        test_string = test_strings[i];
        response = is_palindrome(test_string, 0, test_string.length() - 1);
        if (response == 0){
            result = "False";
        }
        else{
            result = "True";
        }
        cout << "Is '" << test_string << "' a palindrome? "<< result << endl;
        }
    return 0;
}
