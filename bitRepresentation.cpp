#include <iostream>
#include <cctype>
#include <cstdint>
using namespace std;

namespace flags {
    const uint32_t ITS_NOT_YOU_ITS_ME = 1 << 0;             // 1
    const uint32_t I_NEED_TO_FOCUS_ON_MYSELF = 1 << 1;      // 2
    const uint32_t THIS_IS_BETTER_FOR_EVERYONE = 1 << 2;    // 4
    const uint32_t I_DONT_DESERVE_YOU_NEVER_HAVE = 1 << 3;  // 8
    const uint32_t ESCORT_OUT_IMMEDIATE = 1 << 4;           // 16
    const uint32_t ZAP_WITH_LAZER = 1 << 5;                 // 32
}

void terminate(string name, uint32_t flags) {
    cout << "Sorry to tell you " << name << " but,\n";

    if(flags & flags::ITS_NOT_YOU_ITS_ME) {
        cout << "it's not you it's me.\n";
    }
    if(flags & flags::I_NEED_TO_FOCUS_ON_MYSELF) {
        cout << "I need to focus on myself.\n";
    }
    if(flags & flags::THIS_IS_BETTER_FOR_EVERYONE) {
        cout << "this is better for everyone.\n";
    }
    if(flags & flags::I_DONT_DESERVE_YOU_NEVER_HAVE) {
        cout << "I don't deserve you, never have.\n";
    }
    if(flags & flags::ESCORT_OUT_IMMEDIATE) {
        cout << "*escort out immediately.*\n";
    }
    if(flags & flags::ZAP_WITH_LAZER) {
        cout << "*zap with lazer.*\n";
    }

}

int main() {
    uint32_t flags = (flags::ITS_NOT_YOU_ITS_ME | flags::I_NEED_TO_FOCUS_ON_MYSELF | flags::THIS_IS_BETTER_FOR_EVERYONE);
    uint32_t flags2 = (flags::ZAP_WITH_LAZER);
    terminate("Nolan", flags);
    cout << endl << endl;
    terminate("Greg", flags2);
}

/*Output:
Sorry to tell you Nolan but,
it's not you it's me.
I need to focus on myself.
this is better for everyone.


Sorry to tell you Greg but,
*zap with lazer.**/