// Reading a file
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const int ROCK_POINT = 1;
const int PAPER_POINT = 2;
const int SCISSORS_POINT = 3;

const string INPUT_STREAM_NAME = "day02.txt";
const int DRAW = 3;
const int WIN = 6;





char translate(char s) {
    if (s == 'A' || s == 'X') {
        return 'R';
    } else if (s == 'B' || s == 'Y') {
        return 'P';
    } else if (s == 'C' || s == 'Z') {
        return 'S';
    } 
    return 'X';
}


int get_point(char s) {
    if (s == 'R') {
        return ROCK_POINT;
    } else if (s == 'P') {
        return PAPER_POINT;
    } else if (s == 'S') {
        return SCISSORS_POINT;
    } 
    return 0;
}

void get_p1() { 
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0;

    /**
     * @brief 
     * Y > X
     * Z > Y
     * X > Z  
     */
    if(file.is_open()) {
      
        while(getline(file, line)) {
            char opponent = translate(line[0]);
            char me = translate(line[2]);
            if (opponent == me) {
                sum += DRAW + get_point(me);
            } else if (opponent == 'S' && me == 'R' || opponent == 'P' && me == 'S' || opponent == 'R' && me == 'P') {
                sum += WIN + get_point(me);
            } else { 
                sum += get_point(me);
            }
        }
        cout << sum << endl;
        file.close();
    } else cout << "Unable to open file";
}

char translate_elvish(char s, char t) {
    switch(t) {
        case 'X':
            // lose
            if (s == 'R') {
                return 'S';
            } else if (s == 'P') {
                return 'R';
            } else if (s == 'S') {
                return 'P';
            }
        case 'Y':
            return s;
        case 'Z':
            // win
            if (s == 'R') {
                return 'P';
            } else if (s == 'P') {
                return 'S';
            } else if (s == 'S') {
                return 'R';
            }
    }
    return 'X';
}

void get_p2() { 
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = 0;

    /**
     * @brief 
     * Y > X
     * Z > Y
     * X > Z  
     */
    if(file.is_open()) {
      
        while(getline(file, line)) {
            char opponent = translate(line[0]);
            char me = translate_elvish(opponent, line[2]);
            if (opponent == me) {
                sum += DRAW + get_point(me);
            } else if (opponent == 'S' && me == 'R' || opponent == 'P' && me == 'S' || opponent == 'R' && me == 'P') {
                sum += WIN + get_point(me);
            } else { 
                sum += get_point(me);
            }
        }
        cout << sum << endl;
        file.close();
    } else cout << "Unable to open file";
}

int main() {
    
    get_p2();

   
    
    return 0;
}