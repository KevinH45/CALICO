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
    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        int K; cin >> K;
        vector<int> vec;
        for (int x = 1; x <= N; ++x) vec.push_back(x);
        for (int x = 0; x < N; ++x) {
            vec.push_back(vec[x]);
            vec.erase(vec.begin() + x);
        }
        for (int x = 0; x < N; ++x) {
            if (vec[x] == K) {
                cout << x+1 << endl;
                break;
            }
        }
    }
}