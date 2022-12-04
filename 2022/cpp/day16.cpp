#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "day16.txt";

void get_p1() {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
            
        cout << "Sum for part 1: " << sum << '\n';
        file.close();
    }
    } else cout << "Unable to open file";
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
