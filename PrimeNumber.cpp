#include <iostream>
#include <vector>

using namespace std;


// I think this design is fine for this simple program, as nothing
// crazy is being executed causing unknown behavior, for a more
// complex program I would probably just impliment the primes vector
// as a private data member to the class for the same behavior, but 
// overall a safer and better practice
int getNextPrime() {
    static vector<int> primes;

    if(primes.size() > 0) {
        int newNum = primes[primes.size() - 1] + 1;
        for(int i = primes.size() - 1; i >= 0; i--) {
            if(newNum % primes[i] == 0) {
                newNum ++;
                i = primes.size() - 1;
                continue;
            }
        }
        primes.push_back(newNum);
        return newNum;
    }
    else {
        primes.push_back(2);
        return 2;
    }
}

int main() {
    vector<int> primes;

    for(int i = 0; i < 10; i++) {
        primes.push_back(getNextPrime());
    }
}