#include <iostream>
#include <string>

using namespace std;

// Define a base class Animal
class Animal {
public:
    virtual string sound() const {
        return "Some generic animal sound";
    }
    virtual ~Animal() {} // Virtual destructor
};

// Define a derived class Dog
class Dog : public Animal {
public:
    string sound() const override {
        return "Bark";
    }
};

// Define a derived class Cat
class Cat : public Animal {
public:
    string sound() const override {
        return "Meow";
    }
};

int main() {
    // Create objects of Dog and Cat
    Animal* dog = new Dog();
    Animal* cat = new Cat();

    // Call the sound() function through the base class pointer
    cout << "Dog: " << dog->sound() << endl;
    cout << "Cat: " << cat->sound() << endl;

    // Free the allocated memory
    delete dog;
    delete cat;

    return 0;
}
