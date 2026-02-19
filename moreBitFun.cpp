#include <iostream>
#include <sstream>
#include <cstdint>
#include <vector>

using namespace std;

class BitWriter {
 private:
    vector<uint8_t> bytes;
    int bitsWritten;
 public:

    BitWriter() {
        uint8_t byte = 0;
        bytes.push_back(byte);
        bitsWritten = 0;
    }

    // adds a bit to the BitWriters internal state.
    void write(bool bitValue) {
        static int position = 7;
        
        if(bitValue == true){
            bool bitSet = false;

            while(bitSet == false){
                if(position >= 0) {
                    bytes[bytes.size() - 1] |= (1 << position);
                    position--;
                    bitsWritten++;
                    bitSet = true;
                }
                else {  // position == -1
                    uint8_t byte = 0;
                    bytes.push_back(byte);
                    position = 7;
                }
            }
        }
        else {
            if(position < 0) {
                uint8_t byte = 0;
                bytes.push_back(byte);
                position = 7;
            }
            bitsWritten++;
            position--;
        }
    }

    // returns the number of bits written
    // all of the bits that have been written are returned in out

    size_t getData(vector<uint8_t>& out) {
        for(uint8_t byte : bytes) {
            out.push_back(byte);
        }
        return bitsWritten;
    }

    string toHexString(vector<uint8_t> ourBytes, const string& delim = "") {
        stringstream outputStream;

        for(uint8_t byte : ourBytes) {
            outputStream << hex << showbase << uppercase << static_cast<int>(byte);
            outputStream << delim;
            //cout << outputStream.str();
        }
        return outputStream.str();
    }
};

int main() {
    BitWriter bits;
    bits.write(true);
    bits.write(true);
    bits.write(true);
    bits.write(true);
    bits.write(true);
    bits.write(true);
    bits.write(true);
    bits.write(true);
    bits.write(false);
    bits.write(true);

    cout << "** Writing bits 1111 1111 01 to BitWriter object \n**"
         << "after writing bits, they will be put into a vector and checked for accuracy **\n";

    vector<uint8_t> myBytes;
    bits.getData(myBytes);

    vector<int> test;

    for(uint8_t byte : myBytes) {
        test.push_back(static_cast<int>(byte));
    }

    if(test[0] == 255 && test[1] == 64) {
        cout << "Bits written represent these integers: 255, 64\n";
        cout << "** Test success **\n\n";
    }
    else {
        cout << "** Test failure **\n\n";
    }

    cout << "** Testing hexadecimal conversion **\n";

    string tester = bits.toHexString(myBytes, " ");
    cout << tester << endl;

    if(tester == "0XFF 0X40 ") {
        cout << "** Test success **\n\n";
    }
    else {
        cout << "** Test failure **\n\n";
    }
}