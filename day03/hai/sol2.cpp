
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

pair <int, bool> checkDont(string s, int i) {
    if (i >= s.length()) {
        return make_pair(-1, false);
    }
    if (i + 7 >= s.length()) {
        return make_pair(-1, false);
    }
    //cout << i << " " << s.substr(i, 7) << "\n";
    if (s.substr(i, 7) == "don't()") {
        //cout << "acccc" << s.substr(i, 7);
        return make_pair(i + 7, true);
    }
    return make_pair(-1, false);
}

pair <int, bool> checkDo(string s, int i) {
    if (i >= s.length()) {
        return make_pair(-1, false);
    }
    if (i + 4 >= s.length()) {
        return make_pair(-1, false);
    }
     //cout << i << " " << s.substr(i, 4) << "\n";
    if (s.substr(i, 4) == "do()") {
        // << "acccc" << s.substr(i, 4);
        return make_pair(i + 4, true);
    }
    return make_pair(-1, false);
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
    freopen("test1.inp", "r", stdin);

    int res = 0;

    string line;
    string inp = "";
    while (getline(cin, line)) {
       inp = inp + line;
    }
    int i = 0;
    long long sum = 0;
    bool isDo = true;

    while (i < inp.length()) {
        //cout <<"\n" << i << ": ";
        pair <int, bool> idont = checkDont(inp, i);
        if (idont.second) {
            i = idont.first;
            isDo = false;
        }

        idont = checkDo(inp, i);
        if (idont.second) {
            i = idont.first;
            isDo = true;
        }
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
                            if (isDo) {
                                sum = sum + firstNum * il.second;
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
        } else {
            i++;
        }
    }
    cout << sum;

    return 0;
}
