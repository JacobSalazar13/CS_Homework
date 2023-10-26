#include <iostream>
using namespace std;

double factorial(int n) {
    double result = 1;
    for(int i = 1; i <= n; ++i) {
        result *= i;
    }
    return result;
}

int main() {
    int test_values[] = {0, 1, 2, 3, 4, 5, 10, 31};
    for(int i = 0; i < 8; ++i) {
        cout << "Factorial of " << test_values[i] << " is: " << factorial(test_values[i]) << endl;
    }
    return 0;
}