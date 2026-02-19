#include <iostream>
#include <ostream>
#include <sstream>
#include <string>
#include <queue>

using namespace std;

class SalesLead {
 public:
    string name;
    int income;

    SalesLead(string name = "Mystery Person", int income = 1) {
        this->name = name;
        this->income = income;
    }
};

class Compare {
 public:
	bool operator()(const SalesLead& a, const SalesLead& b) {
		if(a.income < b.income) {
			return true;
		}
		return false;
	}
};

ostream& operator <<(ostream& out, priority_queue<SalesLead, vector <SalesLead>, Compare>& maxQ) {
    SalesLead lead;

    while(maxQ.empty() == false) {
        lead = maxQ.top();
        maxQ.pop();
        out << lead.name << ": " << "$" << lead.income << " ";
    }
    return out;
}

int main() {
priority_queue<SalesLead, vector <SalesLead>, Compare> maxQ;

SalesLead lead1("Nolan Kelly", 10000);
SalesLead lead2("Ken Griffey Jr", 1000000);
SalesLead lead3("Peter Griffin", 20000);
SalesLead lead4("Bill Gates", 9000000);
SalesLead lead5("Bowser Jr", 10000);
SalesLead lead0;

maxQ.push(lead0);
maxQ.push(lead1);
maxQ.push(lead2);
maxQ.push(lead3);
maxQ.push(lead4);
maxQ.push(lead5);

cout << "** Testing SalesLead object creation and insertion into the max queue **\n"
     << "** after insertion the queue will be printed to test the objects and ordering **\n\n";
cout << "Queue contents: ";

stringstream outputStream;
outputStream << maxQ;

cout << outputStream.str();

if (outputStream.str() == "Bill Gates: $9000000 Ken Griffey Jr: $1000000 Peter Griffin: $20000 Nolan Kelly: $10000 Bowser Jr: $10000 Mystery Person: $1 ") {
    cout << "\n** Test success **\n\n";
}
else {
    cout << "\n** Test failure **\n\n";
}

}