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
    long long prefix[100005];
    prefix[1] = 1;
    for (long long  x = 2; x < 100005; ++x) {
        prefix[x] = prefix[x-1] + x * x;
    }
    for (int t = 0; t < T; ++t) {
        long long N; cin >> N;
        cout << prefix[N] - N << endl;
    }
    //birthday on n(n-1)+1 day each year
}