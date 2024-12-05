#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;


bool check(vector <int> a) {
    bool inc;
    bool isEqual;
    isEqual = false;
    for (int i =1; i<a.size(); i++) {
        if (a[i] != a[i - 1]) {
        isEqual = true;
          if (a[i-1] < a[i]) {
                inc = true;
            } else {
                inc = false;
            }
        }
    }
    if (!isEqual) {
        return false;
    }
    for (int i =1; i<a.size(); i++) {
        if (( abs(a[i] - a[i-1]) > 3 ) || ( abs(a[i] - a[i-1]) < 1))
            return false;
        if (a[i] > a[i-1] != inc ) {
            return false;
        }
    }
    return true;
}

int main() {
    freopen("test.inp", "r", stdin);

    int res = 0;

    string line;
    while (getline(cin, line)) {
        vector<int> row;
        stringstream ss(line);
        int number;
        while (ss >> number) {
            row.push_back(number);
        }
        if (check(row)) {
            res +=1 ;
        }

    }

    cout << res;

    return 0;
}
