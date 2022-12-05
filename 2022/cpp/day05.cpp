#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <iostream> 
#include <regex> 
#include <string.h> 
using namespace std;
const string INPUT_STREAM_NAME = "day05.txt";
vector<stack<char>> cargo(10);

void get_p1() {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
        regex re("move (\\d+) from (\\d+) to (\\d+)");
        smatch match;
        regex_match(line, match, re);

        int from = stoi(match[2]);
        int to = stoi(match[3]);
        int amount = stoi(match[1]);
        cout << "Moving " << amount << " from " << from << " to " << to << '\n';
        for(int i = 0; i < amount; i++) {
            cargo[to].push(cargo[from].top());
            cargo[from].pop();
        }
        
    }
    file.close();
    string s;
    for (int i = 1; i < 10; i++) {
            s += cargo[i].top();
            
    }
    cout << s << '\n';
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
        regex re("move (\\d+) from (\\d+) to (\\d+)");
        smatch match;
        regex_match(line, match, re);

        int from = stoi(match[2]);
        int to = stoi(match[3]);
        int amount = stoi(match[1]);
        cout << "Moving " << amount << " from " << from << " to " << to << '\n';
        stack<char> temp;
        for(int i = 0; i < amount; i++) {
            temp.push(cargo[from].top());
            cargo[from].pop();
        }
        while (!temp.empty()) { 
            cargo[to].push(temp.top());
            temp.pop();
        }
        
    }
    file.close();
    string s;
    for (int i = 1; i < 10; i++) {
            s += cargo[i].top();
            
    }
    cout << s << '\n';
    } else cout << "Unable to open file";
}

void initialise_cargo() {
    cargo =  { 
        stack<char>(), stack<char>(), stack<char>(), stack<char>(), stack<char>(), 
        stack<char>(), stack<char>(), stack<char>(), stack<char>(), stack<char>()
    };  
    cargo[1].push('H');
    cargo[1].push('B');
    cargo[1].push('V');
    cargo[1].push('W');
    cargo[1].push('N');
    cargo[1].push('M');
    cargo[1].push('L');
    cargo[1].push('P');

    cargo[2].push('M');
    cargo[2].push('Q');
    cargo[2].push('H');


    cargo[3].push('N');
    cargo[3].push('D');
    cargo[3].push('B');
    cargo[3].push('G');
    cargo[3].push('F');
    cargo[3].push('Q');
    cargo[3].push('M');
    cargo[3].push('L');


    cargo[4].push('Z');
    cargo[4].push('T');
    cargo[4].push('F');
    cargo[4].push('Q');
    cargo[4].push('M');
    cargo[4].push('W');
    cargo[4].push('G');


    cargo[5].push('M');
    cargo[5].push('T');
    cargo[5].push('H');
    cargo[5].push('P');

    cargo[6].push('C');
    cargo[6].push('B');
    cargo[6].push('M');
    cargo[6].push('J');
    cargo[6].push('D');
    cargo[6].push('H');
    cargo[6].push('G');
    cargo[6].push('T');


    cargo[7].push('M');
    cargo[7].push('N');
    cargo[7].push('B');
    cargo[7].push('F');
    cargo[7].push('V');
    cargo[7].push('R');


    cargo[8].push('P');
    cargo[8].push('L');
    cargo[8].push('H');
    cargo[8].push('M');
    cargo[8].push('R');
    cargo[8].push('G');
    cargo[8].push('S');


    cargo[9].push('P');
    cargo[9].push('D');
    cargo[9].push('B');
    cargo[9].push('C');
    cargo[9].push('N');
}


int main() {
// [P]     [L]         [T]            
// [L]     [M] [G]     [G]     [S]    
// [M]     [Q] [W]     [H] [R] [G]    
// [N]     [F] [M]     [D] [V] [R] [N]
// [W]     [G] [Q] [P] [J] [F] [M] [C]
// [V] [H] [B] [F] [H] [M] [B] [H] [B]
// [B] [Q] [D] [T] [T] [B] [N] [L] [D]
// [H] [M] [N] [Z] [M] [C] [M] [P] [P]
//  1   2   3   4   5   6   7   8   9 
    initialise_cargo();
    get_p1();
    initialise_cargo();
    get_p2();
    return 0;
}