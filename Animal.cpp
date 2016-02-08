#include <string>
#include <iostream>

using namespace std;

class Animal {

  private:
    int height;
    int weight;
    string name;

    static int numOfAnimals;

  public:
    int getHeight() { return height; }
    int getWeight() { return weight; }
    string getName() { return name; }
    void setHeight(int cm) { height = cm; }
    void setWeight(int kg) { weight = kg; }
    void setName(string animalName) { name = animalName; }

    // void setAll(int, int, string); // prototype of function to be defined later

    Animal(int, int, string); // prototype of constructor

    ~Animal(); // destructor

    Animal(); // constructor that doesn't receive anything

    static int getNumOfAnimals() { return numOfAnimals; }

    void toString();

};

int Animal::numOfAnimals = 0;

Animal::Animal(int height, int weight, string name) {
  this -> height = height;
  this -> weight = weight;
  this -> name = name;
  Animal::numOfAnimals++;
}

Animal::~Animal() {
  cout<<"Animal " << this -> name << " destroyed" << endl;
}

Animal::Animal() {
  Animal::numOfAnimals++;
}

void Animal::toString() {
  cout << this -> name << " is " << this -> height <<
  " cms tall and " << this -> weight << " kgs in weight" << endl;
}


class Dog : public Animal { // extend Animal
  private:
    string sound = "Woof";
  public:
    void getSound() {
      cout << sound << endl;
    }

    Dog(int, int, string, string);

    Dog() : Animal(){}; // Call the default Animal constructor

    void toString();
};

Dog::Dog(int height, int weight, string name, string bark) :
Animal(height, weight, name) { // have the animal constructor handle these variables
  this -> sound = bark; // and just add whatever is different
}

void Dog::toString() {
  cout << this -> getName() << " is " << this -> getHeight() <<
  " cms tall and " << this -> getWeight() << " kgs in weight" <<
  " and says" << this -> sound << endl;
}

int main() {

  Animal fred;

  fred.setHeight(33);
  fred.setWeight(10);
  fred.setName("Fred");

  cout << fred.getName() << " is " << fred.getHeight() <<
  " cms tall and " << fred.getWeight() << " kgs in weight" << endl;

  Animal tom(36, 15, "Tom");

  cout << tom.getName() << " is " << tom.getHeight() <<
  " cms tall and " << tom.getWeight() << " kgs in weight" << endl;

  Dog spot(38, 16, "Spot", "Woof");

  cout << "Number of Animals " << Animal::getNumOfAnimals() << endl;

  spot.getSound();
  tom.toString();

  spot.Animal::toString(); // call the superclass method

  return 0;

}