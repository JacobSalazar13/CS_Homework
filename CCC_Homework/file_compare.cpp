#include <iostream>
#include <fstream>
#include <queue>
#include <string>
using namespace std;


int main() {
    string filename1, filename2;

    cout << "Enter the first filename: ";
    cin >> filename1;

    cout << "Enter the second filename: ";
    cin >> filename2;

    ifstream file1(filename1), file2(filename2);

    queue<char> queue1, queue2;
    char symbol;

    while (file1.get(symbol)) {
        queue1.push(symbol);
    }

    while (file2.get(symbol)) {
        queue2.push(symbol);
    }

    bool same = true;

    while (!queue1.empty() && !queue2.empty()) {
        if (queue1.front() != queue2.front()) {
            same = false;
            break;
        }
        queue1.pop();
        queue2.pop();
    }

    if (same && queue1.empty() && queue2.empty()) {
        cout << "The files are identical." << endl;
    } 
    else {
        cout << "The files are not the same." << endl;
    }

    file1.close();
    file2.close();

    return 0;
}