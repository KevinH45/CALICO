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
#include <set>

using namespace std;

set<int> sink;
set<int> source;
int num_paths;
int *connections;

int dfs(int i, vector<int> *adj) {
    if (sink.find(i) != sink.end()) {
        num_paths += 1;
        return 1;
    }
    for (int a : adj[i]) {
        connections[i] += dfs(a, adj);
    }
}

int main() {    
    int T; cin >> T;
    for (int t = 0; t < T; ++t) {
        int N; cin >> N;
        int M; cin >> M;
        int S; cin >> S;
        vector<int> adj[N];
        for (int x = 0; x < N; ++x) source.insert(x);
        for (int x = 0; x < N; ++x) adj[x] = vector<int>();
        for (int x = 0; x < M; ++x) {
            int a; cin >> a;
            int b; cin >> b;
            adj[a-1].push_back(b-1);
        }
        for (int x = 0; x < N; ++x) {
            if (adj[x].size() == 0) sink.insert(x);
            for (int i : adj[x]) source.erase(i);
        }
        connections = new int[N];
        num_paths = 0;
        for (int x = 0; x < N; ++x) connections[x] = 0;
        for (int i : source) {
            dfs(i, adj);
        }
        for (int x = 0; x < N; ++x) {
            if (source.find(x) == source.end() && connections[x] == num_paths) {
                cout << x + 1 << endl;
                return 0;
            }
        }
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
}