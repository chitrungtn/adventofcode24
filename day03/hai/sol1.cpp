
#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;


int findMul(string s, int i) {
    // mul(
    if (i >= s.length()) {
        return -1;
    }
    if (i + 3 >= s.length()) {
        return -1;
    }
    //cout << s.substr(i, 4) << " ";
    if (s.substr(i, 4) == "mul(") {
        //cout << i << " ";
        return i + 3 + 1;
    }
    return -1;
}

int findComma(string s, int i) {
    //","
    if (i >= s.length()) {
        return -1;
    }
    if (s[i] == ',') {
        return i+1;
    }
    return -1;
}

int findClose(string s, int i) {
    if (i >= s.length()) {
        return -1;
    }
    if (s[i] == ')') {
        return i+1;
    }
    return -1;
}

pair<int, long long> findNumber(string s, int i) {
    if (i >= s.length()) {
         return make_pair(-1, -1);
    }
    long long num = 0;
    for (int j = i; j < s.length(); j++) {
        if (s[j] >= '0' and s[j] <= '9') {
            num = num * 10 + s[j] - '0';
        } else {
            if (j == i) {
                return make_pair(-1, -1);
            } else {
                return make_pair(j, num);
            }
        }
    }
    return make_pair(-1, -1);
}

int main() {
    freopen("test.inp", "r", stdin);

    int res = 0;

    string line;
    string inp = "";
    while (getline(cin, line)) {
       inp = inp + line;
    }
    int i = 0;
    long long sum = 0;

    while (i < inp.length()) {
        //cout <<"\n" << i << ": ";
        int iMul = findMul(inp, i);
        if (iMul != -1) {
            i = iMul;
            pair<int, long long> il = findNumber(inp, i);
            if (il.first != -1) {
                long long firstNum = il.second;
                i = il.first;
                int iComma = findComma(inp, i);
                if (iComma != -1) {
                    i = iComma;
                    pair<int, long long> il = findNumber(inp, i);
                    if (il.first != -1) {
                        i = il.first;
                        int iC = findClose(inp, i);
                        if (iC != -1) {
                            i = iC;
                            // cout << firstNum << " " << il.second << "\n";
                            sum = sum + firstNum * il.second;
                        } else {
                            i++;
                        }
                    } else {
                        i++;
                    }
                } else {
                    i++;
                }
            } else {
                i++;
            }
        } else {
            i++;
        }
    }
    cout << sum;

    return 0;
}
