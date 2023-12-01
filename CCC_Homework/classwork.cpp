#include <iostream>
#include <string>
using namespace std;

template <class T>
void swapVars(T &a, T &b)
{
	T temp;
	temp = a;

	a = b;
	b = temp;

}

int main()
{
	double x = 1.5, y = 99.5;
	int z = 1, zz = 100;
    string j = "test", jj = "test2";
    char a = '1', aa = '2';

    cout << "Before the swap:\n"
		<< " x = " << x
		<< " y = " << y << endl;
	swapVars(x, y);

	cout << "After the swap:\n"
		<< " x = " << x
		<< " y = " << y << endl;

	cout << "Before the swap:\n"
		<< " z = " << z
		<< " zz = " << zz << endl;
	swapVars(z, zz);

	cout << "After the swap:\n"
		<< " z = " << z
		<< " zz = " << zz << endl;
    cout <<"\n";

    cout << "Before the swap:\n"
		<< " j = " << j
		<< " jj = " << jj << endl;
	swapVars(j, jj);

	cout << "After the swap:\n"
		<< " j = " << j
		<< " jj = " << jj << endl;

    cout << "Before the swap:\n"
		<< " a = " << a
		<< " aa = " << aa << endl;
	swapVars(a, aa);

	cout << "After the swap:\n"
		<< " a = " << a
		<< " aa = " << aa << endl;
}