#include <iostream>
#include <vector>
using namespace std;


class Fruit {
 public:
    Fruit() {

    }
    virtual void eatMe() { 
        cout << "yum!\n"; 
    }
};

class Watermelon : public Fruit {
 public:
    Watermelon() {

    }
    void eatMe() { 
        cout << "Delicious!\n"; 
    }
};

class Cantaloupe : public Fruit {
 public:
    Cantaloupe() {

    }
    void eatMe() { 
        cout << "Disgusting!\n"; 
    }
};

class Banana : public Fruit {
 public:
    Banana() {

    }
    void eatMe() { 
        cout << "Meh!\n"; 
    }
};

int main() {
    vector<Fruit*> fruits;
    Fruit* wptr = new Watermelon();
    Fruit* cptr = new Cantaloupe();
    Fruit* bptr = new Banana();
    Fruit* fptr = new Fruit();

    fruits.push_back(wptr);
    fruits.push_back(cptr);
    fruits.push_back(bptr);
    fruits.push_back(fptr);

    for(Fruit* fruit : fruits) {
        fruit->eatMe();
    }
}

/*Output without virtual keyword on eatMe in Fruit:
yum!
yum!
yum!
yum!
- No runtime polymorphism, only calls eatMe in Fruit*/

/*Output with virtual keyword on eatMe in Fruit:
Delicious!
Disgusting!
Meh!
yum!
- Yes runtime polymorphism, calls different eatMe based on type*/