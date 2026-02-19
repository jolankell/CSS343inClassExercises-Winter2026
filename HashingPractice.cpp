#include <iostream>
#include <ostream>
#include <functional>
#include <unordered_set>
#include <vector>
#include <unordered_map>

using namespace std;

class Shoe {
private:
   double size;
   string color;
   string type;
public:
   Shoe(double size, string color, string type)
      : size(size), color(color), type(type) {;}

    friend ostream& operator<<(ostream& out, const Shoe& shoe) {
        out << shoe.color << " " << shoe.type << " " << shoe.size;
        return out;
    }

    bool operator==(const Shoe& b) const {
        return (this->color == b.color && this->type == b.type && this->size == b.size);
    }

    string getColor() const {
        return this->color;
    }

    string getType() const {
        return this->type;
    }

    double getSize() const {
        return this->size;
    }
};

namespace std {
    template<>
    struct hash<Shoe> {
        size_t operator()(const Shoe& shoe) const noexcept {
            size_t h1 = hash<string>{}(shoe.getType());
            size_t h2 = hash<string>{}(shoe.getColor());
            size_t h3 = hash<double>{}(shoe.getSize());

            size_t seed = h1;
            seed ^= h2 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            seed ^= h3 + 0x9e3779b9 + (seed << 6) + (seed >> 2);
            
            return seed;
        }
    };
}

int main() {
    cout << "** Testing insertion of Shoe objects into hash table **\n"
            "** after insertions, the table will be checked for duplicates **\n\n";

    Shoe shoe1 = {10.0, "Black", "Sambas"};
    Shoe shoe2 = {9.5, "Black", "Terascapes"};
    Shoe shoe3 = {10.0, "Red", "Trainers"};
    Shoe shoe4 = {10.0, "Brown", "Dress Shoes"};
    Shoe shoe5 = {9.0, "Camo", "Crocs"};
    Shoe shoe6 = {10.0, "Black", "Sambas"};
    Shoe shoe7 = {10.0, "Grey", "Trainers"};
    Shoe shoe8 = {10.0, "Brown", "Dress Shoes"};
    Shoe shoe9 = {9.0, "Camo", "Crocs"};
    Shoe shoe10 = {10.0, "Grey", "Sambas"};

    unordered_set<Shoe> hashTable;
    hashTable.insert(shoe1);
    hashTable.insert(shoe2);
    hashTable.insert(shoe3);
    hashTable.insert(shoe4);
    hashTable.insert(shoe5);
    hashTable.insert(shoe6);
    hashTable.insert(shoe7);
    hashTable.insert(shoe8);
    hashTable.insert(shoe9);
    hashTable.insert(shoe10);

    unordered_map<Shoe, int> testMap;
    bool result = true;

    cout << "\n** Printing out table **\n";

    for(Shoe i : hashTable) {
        cout << i << endl;
        testMap[i]++;
    }
    
    for(auto i : testMap) {
        if(i.second != 1) {
            result = false;
        }
    }

    if(result == true) {
        cout << "** Test sucess - No duplicates in hash table **\n\n";
    }
    else {
        cout << "** Test failure - duplicates found\n\n";
    }
}