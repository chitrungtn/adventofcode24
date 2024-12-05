#include <bits/stdc++.h>

using namespace std;

const long long mod = 1e9+7;
const int maxn = 1e5+5;

int main() {
    freopen("test.inp", "r", stdin);

    vector<pair<int, int>> rules;
    vector<vector<int>> sequences;

    string line;

    while (getline(cin, line) && line.find('|') != string::npos) {
        size_t pos = line.find('|');
        if (pos != string::npos) {
            int x = stoi(line.substr(0, pos));
            int y = stoi(line.substr(pos + 1));
            rules.emplace_back(x, y);
        }
    }

    do {
        if (!line.empty()) {
            stringstream ss(line);
            string num;
            vector<int> sequence;

            while (getline(ss, num, ',')) {
                sequence.push_back(stoi(num));
            }
            sequences.push_back(sequence);
        }
    } while (getline(cin, line));

    long long sum = 0;
    for (auto& seq : sequences) {
        bool ok = true;
        for (int i=0; i<seq.size() - 1; i++) {
            for (int j=i+1; j<seq.size(); j++) {
                 for (auto& rule : rules) {
                    if ((seq[j] == rule.first ) and (seq[i] == rule.second)) {
                        ok = false;
                        break;
                    };
                }
                if (!ok) {
                    break;
                }
            }
            if (!ok) {
                    break;
                }
        }
        if (ok) {
            sum += seq[seq.size() / 2];
        }

    }
        cout << sum;
    return 0;
}
