#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

void makeMeYoung(int* age) {
  cout << "I used to be " << *age << endl;
  *age = 21;
}

int main() {

  // cout << "Hello World" << endl;
  //
  // const double PI = 3.1415926535;
  //
  // char myGrade = 'A';
  //
  // bool isHappy = false;
  //
  // int myAge = 39;
  //
  // float favNumber = 3.14;
  //
  // double otherFavNum = 1.5829582;
  //
  // cout << "Favorite Number " << favNumber << endl;
  //
  // cout << "Size of int " << sizeof(myAge)
  //   << " bytes" << endl;

  // int myFavNums[2][5] = {{1, 5, 3, 6, 1}, {2, 5, 1, 6, 4}};
  //
  // cout << "What will I print? " << myFavNums << endl;
  //
  // for (int i = 0; i < 2; i++) {
  //   for (int j = 0; j < 5; j++) {
  //     cout << "Printing "  << i << " " << j  << " " << myFavNums[i][j] << "\n";
  //   }
  // }
  //
  // cout << endl;
  //
  // int age = 39;
  // int* agePtr = &age;
  //
  // cout<<"Address of age "<<&age<<endl;
  // cout << "Address of agePtr " << agePtr << endl;
  // cout<<"What is the data that agePtr points to? "<<*agePtr<<endl;

  // We can pass a reference such that we can modify the actual value
  // We get an the address of the variable like this &theNum
  int age = 39;

  makeMeYoung(&age);

  cout << "I'm " << age << " years old now" << endl;

  int& anotherAge = age;
  anotherAge++;

  cout << "This is what incrementing a reference will do to you " << age << endl;

  // When to use references when pointers?
  // Pointers are useful for pointing to multiple objects
  // Use a pointer if you don't want to have to initialize at declaration
  // With a pointer I don't have to immediately initialize
  // References are stuck with whatever they're referencing
  // So if you don't need to change whatever you're pointing at, use a reference
  

  return 0;

}