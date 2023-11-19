#include <iostream>
#include <utility>
#include <algorithm>
#include <iterator>
#include <vector>
#include <math.h>
#include <unordered_set>
#include <string>
#include <map>
#include <functional>
#include <queue>
#include <bitset>

using namespace std;

int main() {    
    int T; cin >> T;
    for (int x = 0; x < T; ++x) {
        int i; cin >> i;
        if (i == 0) {
            cout << "haha good one" << endl;
            continue;
        }
        else if (i >= 180) {
            cout << "canceled" << endl;
            continue;
        }
        else {
            for (int r = 0; r < i / 10; ++r) {
                cout << "berkeley";
            }
            cout << "time" << endl;
        }
    }
}