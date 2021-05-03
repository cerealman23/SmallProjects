#include <iostream>
#include <cstring>
#include <cmath>
#include <fstream>

/** Malcolm kahora  */

/** CSC230-01 */

/** Lab Bonus 2         */


;;
using namespace std;

long hashcode(char* s);


int main(int argc, char *argv[])
{

  ifstream input(argv[1]);

  bool array[10007] = {false};
  
  char stringVal[11];

  int collision = 0;
  int input_num = 0;
  
  while (input.getline(stringVal, 11, '\n')) {

    ++input_num;
    
    if (array[hashcode(stringVal) % 10007]) {
      collision++;
    } else {
      array[hashcode(stringVal) % 10007] = true;
    }

  }

  cout << "Collision # is: " << collision << "\n";
  cout << "Input # is: " << input_num << "\n";

  return 0;
}


long hashcode(char* c) {

  int lengthOfString = strlen(c);

  long x = 0;

  for (int i = 0; i < lengthOfString; ++i) {
    
    x += long(c[i]) * pow(31, lengthOfString - 1 - i);

  }

  return x;

}
