// Reading a file
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "day04.txt";


bool contains(pair<int, int> a, pair<int, int> b) {
    return a.first <= b.first && a.second >= b.second || a.first >= b.first && a.second <= b.second;
}

bool partial_contains(pair<int, int> a, pair<int, int> b) {
    return (a.second >= b.first && a.second <= b.second || a.first <= b.second && a.second >= b.second) || 
    (b.second >= a.first && b.second <= a.second || b.first <= a.second && b.second >= a.second);
}



int get_total_lines() {
    ifstream input_stream(INPUT_STREAM_NAME);
    string line;
    int total_lines = 0;
    while (getline(input_stream, line)) {
        total_lines++;
    }
    return total_lines;
}

pair<int, int> get_p1() {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int contained = 0;
    int p_contains = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
            pair<int, int> f; 
            pair<int, int> s;
            int split = line.find(',');
            string a = line.substr(0, split);
            string b = line.substr(split + 1, line.length() - split);
            f.first = stoi(a.substr(0, a.find('-')));
            f.second = stoi(a.substr(a.find('-') + 1, a.length() - a.find('-')));
            
            s.first = stoi(b.substr(0, b.find('-')));
            s.second = stoi(b.substr(b.find('-') + 1, b.length() - b.find('-')));            
            if (contains(f,s)) { 
                contained += 1;
            } 
            if (partial_contains(f,s)) { 
                p_contains += 1;
            }
        }
        cout << "Sum for part 1: " << contained << '\n';
        file.close();
    } else cout << "Unable to open file";

    return {contained, p_contains};
}


void get_p2(pair<int, int> data) {
    
    int p_contains = 0;
    int n = get_total_lines();

    pair<int, int> val = data;
    int _t_c = val.first;
    int t_pc = val.second;
    cout << "Sum for part 2: " << t_pc << '\n';
}

int main() {
    pair<int, int> data = get_p1();
    get_p2(data);
    return 0;
}



