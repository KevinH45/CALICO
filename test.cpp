#include <iostream>

using namespace std;

int main() {
    for (int x = 1; x < 50; ++x) {
        cout << (long long) pow(2, x) % 3359232 << endl;
    }
}