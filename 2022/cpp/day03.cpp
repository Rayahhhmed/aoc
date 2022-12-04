// Reading a file
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "day04.txt";

void get_p1() {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
            int c[53];

            int n = line.length();
            string a = line.substr(0, n/2);
            string b = line.substr(n/2, n/2);
            fill(c, c + 53, 0);
            for (int i = 0; i < a.length(); i++) {
                if(isupper(a[i])) {
                    c[a[i] - 'A' + 27]++;
                } else {
                    c[a[i] - 'a' + 1]++;
                }
                
            }
            // Debug statements cause im stupid
            // Children remember substr is not representing the bounds.
            cout << a << " " << b << endl;
            for (int i = 1; i <= 52; i++) {  
                if (i <= 26) {
                    cout << (char)(i + 'a' - 1) << " ";
                } else { 
                    cout << (char)(i + 'A' - 27) << " ";
                }
                
            }
            cout << endl;

            for (int i = 1; i <= 52; i++) {  
                cout << c[i] << " ";
            }
            cout << endl;
            cout << endl;
            ///////////////////////////////////////////////////
            int temp = INT_MAX;
            for (int i = 0; i < b.length(); i++) {
                char val = b[i];
                
                if(isupper(val) && c[val - 'A' + 27]) {
                    temp = min(val - 'A' + 27, temp);
                } else if(islower(val) && c[val - 'a' + 1]){
                    temp = min(val - 'a' + 1, temp);
                }

            }
            if (temp != INT_MAX) {
                sum += temp;
            }
            cout << sum << '\n';
        }
        cout << "Sum for part 1: " << sum << '\n';
        file.close();
    } else cout << "Unable to open file";
}

int *mark_arr(string f, int c[], int n) {
    for (int i = 0; i < f.length() ; i++) {
        char l;
        if(isupper(f[i])) {
            l = f[i] - 'A' + 27;  
        } else {
            l = f[i] - 'a' + 1;
        }

        if (c[l] == n - 1) {
            c[l] = n;
        }
    }
    return c;
}
void get_p2() {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
            int c[53];
            fill(c, c + 53, 0);
            mark_arr(line, c, 1);
            for (int i = 2; i <= 3; i++) { 
                getline(file, line);
                mark_arr(line, c, i);
            }

            for (int i = 1; i <= 52; i++) {
                if (c[i] == 3) {
                    sum += i;
                    break;
                }
            }
        }
        cout << "Sum for part 2: " << sum << '\n';
        file.close();
    } else cout << "Unable to open file";
}

int main() {
    get_p1();
    get_p2();
    return 0;
}



