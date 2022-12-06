#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "day06.txt";

void get_p1(int &i) {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
        int l = 0;
        int r = 0;
        int alph[26] = {};
        fill(alph, alph + 26, -1);
        for (;r - l + 1 <= i; r++) {
            // cout << "alph r =>" << alph[line[r] - 'a'] << endl;
            if (alph[line[r] - 'a'] != -1) {
                while (alph[line[r] - 'a'] != -1) { 
                    alph[line[l] - 'a'] -= 1;
                    l++;
                }
            }
            alph[line[r] - 'a'] += 1;
            //cout << line[r] << " " << alph[line[r] - 'a'] << endl;
        }
        
        cout << line.substr(l, r - l) << '\n';
        cout << r << endl;
        file.close();
        return r;
    }
    } else cout << "Unable to open file";
}


int main() {
    int p1 = 4;
    int p2 = 14;
    cout << "P1: " << '\n';
    get_p1(p1);
    cout << "P2: " << '\n';
    get_p1(p2);
    return 0;
}
