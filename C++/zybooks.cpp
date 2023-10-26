#include <iostream>
using namespace std;

int main() {
   int age = 18;
	if(18 <= age <=22 ){
      cout << 1;
   }
   if( age>=18 && age<=22 ){
      cout << 2;
   }
   if( (age>=18) && (age<=22) ){
      cout << 3;
   }
   if( (18<=age) && (age<=22) ){
      cout << 4;
   }
}