// This is the main file.
// It uses the other support files to actually
// execute the chess game.
#include <iostream>

using namespace std;


class MyRefPractice
{
public:
  inline MyRefPractice( int & intRef )
    : myIntRef_(intRef)
  { }

  int & myRefMethod( int & anotherIntRef );
  int myMethod( int anotherInt );
  int & getMyIntRef();
  int   getMyInt();

protected:
  int & myIntRef_;
};

int & MyRefPractice::myRefMethod( int & anotherIntRef )
{
  cout << "myRefMethod::&anotherIntRef: " << &anotherIntRef << endl;
  anotherIntRef = 10;
  return anotherIntRef;
}

int MyRefPractice::myMethod( int anotherInt )
{
  cout << "myMethod::&myMethodAnotherInt: " << &anotherInt << endl;
  anotherInt = 35;
  return anotherInt;
}

int & MyRefPractice::getMyIntRef( )
{
  cout << "getMyIntRef::&myIntRef_: " << &myIntRef_ << endl;
  return myIntRef_;
}

int MyRefPractice::getMyInt( )
{
  return myIntRef_;
}

int main( int argc, char ** argv )
{
  int myInt = 2;
  int anotherInt = 5;
  int * myIntPtr = &myInt;
  int & myIntRef = myInt;

  cout << "main::&myInt: " << &myInt << endl;
  MyRefPractice myRefPractice(myInt);

  int & returnedIntRef = myRefPractice.getMyIntRef();
  cout << "main::&returnedIntRef: " << &returnedIntRef << endl;

  int returnedInt      = myRefPractice.getMyInt();
  cout << "main::&returnedInt: " << &returnedInt << endl;

  cout << "main::anotherInt: " << anotherInt << endl;
  int & returnedMyRefMethod = myRefPractice.myRefMethod(anotherInt);
  cout << "main::anotherInt: " << anotherInt << endl;
  cout << "main::returnedMyRefMethod: " << returnedMyRefMethod << endl;
  cout << "main::&returnedMyRefMethod: " << &returnedMyRefMethod << endl;


  cout << "main::anotherInt: " << anotherInt << endl;
  int returnedMyMethod = myRefPractice.myMethod(anotherInt);
  cout << "main::anotherInt: " << anotherInt << endl;
  cout << "main::&returnedMyMethod: " << &returnedMyMethod << endl;
  
  return 0;
}


