// Reading a file
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "day02.txt";

enum Opcode {
    OPPONENT, 
    ME
};

uint8_t translate(char s, enum Opcode o) {
    switch(o) {
        case OPPONENT:
            return s - 'A' + 1;
        case ME:
            return s - 'X' + 1;
    }
    return 0;
}


int pos_residue(int a, int b) {
    a = a % b;
    while (a < 0) {
        a += b;
    }
    return a;
}

void get_p1() {
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0;
    if(file.is_open()) {
        while(getline(file, line)) {
            int opponent = translate(line[0], OPPONENT);
            int me = translate(line[2], ME);

            sum += me;
            int res = pos_residue((opponent - me), 3);
            cout << "Opponent: " << opponent << " Me: " << me << " Residue: " << res << '\n';
            
            switch(res){
                case 0:
                // Draw
                    sum += 3;
                    break;
                case 1:
                    break;
                case 2:
                    // Win
                    sum += 6;
                    break;
            }
        }
        cout << "Sum for part 1: " << sum << '\n';
        file.close();
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
            int opponent = translate(line[0], OPPONENT);
            int me = translate(line[2], ME);

            sum += me;
            int res = pos_residue((opponent - me), 3);
            cout << "Opponent: " << opponent << " Me: " << me << " Residue: " << res << '\n';
            
            switch(res){
                case 0:
                // Draw
                    sum += 3;
                    break;
                case 1:
                    break;
                case 2:
                    // Win
                    sum += 6;
                    break;
            }
        }
        cout << "Sum for part 1: " << sum << '\n';
        file.close();
    } else cout << "Unable to open file";
}

int main() {
    
    get_p1();
    get_p2();
    return 0;
}


