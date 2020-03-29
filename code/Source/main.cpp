// This is the main file.
// It uses the other support files to actually
// execute the chess game.
#include <iostream>

using namespace std;



int main( int argc, char ** argv )
{
  int myInt = 2;
  int * myIntPtr = &myInt;

  cout << "myInt: " << myInt << endl;
  cout << "&myInt: " << &myInt << endl;

  cout << "myIntPtr: " << myIntPtr << endl;
  cout << "&myIntPtr: " << &myIntPtr << endl;
  cout << "*myIntPtr: " << *myIntPtr << endl;
  cout << "&(*myIntPtr): " << &(*myIntPtr) << endl;
}
