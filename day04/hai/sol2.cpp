#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;

bool checkIndex(int i, int n) {
    return (0 <= i and i < n);
}

int main() {
    freopen("test.inp", "r", stdin);

    int res = 0;

    string line;
    vector<string> row;
    while (getline(cin, line)) {
        stringstream ss(line);
        string number;
        while (ss >> number) {
            row.push_back(number);
        }
    }
    int sum = 0;
    /*int x[8] = {-1, 0, 1, -1, 1, -1, 0, 1};
	int y[8] = {-1, -1, -1, 0, 0, 1, 1, 1};
    for (int i=0; i<row.size(); i++)
        for (int j=0; j <= row[0].size(); j++)
            if (row[i][j] == 'X') {
                for (int d = 0; d < 8; d++) {
                    string sub = "";
                    //cout << i << " " << j << "\n";
                    int posi = i, posj = j;
                    for (int l=1; l <3; l++) {
                        posi += x[d];
                        posj += y[d];
                        //cout << sub << " ";
                        if (checkIndex(posi, row.size()) and checkIndex(posj, row[0].size())) {
                            sub += row[posi][posj];
                        } else {
                            break;
                        }
                    }
                    //cout << "\n";
                    if (sub == "MAS") {
                        sum += 1;
                    }
                }
            }
    cout << sum;*/
    int x[4] = {-1, 1, 1, -1};
	int y[4] = {-1, -1, 1, 1};
    for (int i=0; i<row.size(); i++)
        for (int j=0; j <= row[0].size(); j++)
            if (row[i][j] == 'A') {
                string sub = "";
                for (int d = 0; d < 4; d++) {
                    int posi = i, posj = j;
                    posi += x[d];
                    posj += y[d];
                    //cout << sub << " ";
                    if (checkIndex(posi, row.size()) and checkIndex(posj, row[0].size())) {
                        sub += row[posi][posj];
                    }
                }
                    //cout << "\n";
                if (sub == "MMSS" or sub == "SSMM" or sub == "SMMS" or sub == "MSSM") {
                    sum += 1;
                }
            }
    cout << sum;
    return 0;
}
