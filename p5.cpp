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
    const unsigned long long mod = 3359232; // 2^9 * 3^8
    for (int t = 0; t < T; ++t) {
        unsigned long long N; cin >> N;
        if (N%3 != 0) N -= N % 3;
        unsigned long long height = N/3;
        if (height < 1) {cout << "0" << endl; continue;}
        //num can be represented in binary ex:
        //height of 1 = "1", height of 2 = "11"
        //2^(height+1) % mod - 1
        height += 1;
        unsigned long long ret = 2;
        unsigned long long power = 1;

        while (power < height) {
            if (power*2 <= height) {
                power *= 2;
                ret = (ret * ret) % mod;
            }
            else {
                for (unsigned long long x = 0; x < height - power; ++x) {
                    ret = (ret * 2) % mod;
                }
                power = height;
            }
        }

        ret -= 1; //account for - 1
        ret -= 1; //account for exclude bottom case
        cout << ret << endl;
    }
}