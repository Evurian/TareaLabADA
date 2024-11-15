#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
using namespace std;

static const int MAX_VALUE = 300;
typedef unsigned long long ull_t;

unordered_map<string, ull_t> memo;

ull_t countWays(int amount, int maxCoin) {
    if (amount == 0) return 1;  
    if (amount < 0 || maxCoin == 0) return 0;  

    string key = to_string(amount) + "," + to_string(maxCoin);

    if (memo.find(key) != memo.end()) return memo[key];

    memo[key] = countWays(amount, maxCoin - 1) + countWays(amount - maxCoin, maxCoin);

    return memo[key];
}

int main() {  
    string s;
    while (getline(cin, s)) {
        vector<int> N;
        stringstream ss(s);
        int input;
        while (ss >> input) N.push_back(input);

        int L1, L2;
        switch (N.size()) {
            case 1:
                L1 = 0;
                L2 = N[0];
                break;
            case 2:
                L1 = 0;
                L2 = N[1];
                break;
            default:
                L1 = N[1];
                L2 = N[2];
        }

        if (N[0] == 0) {
            cout << "1" << endl;
        } else {
            ull_t result = countWays(N[0], min(MAX_VALUE, L2)) - 
                           (L1 > 0 ? countWays(N[0], L1 - 1) : 0);
            cout << result << endl;
        }
    }
    return 0;
}
