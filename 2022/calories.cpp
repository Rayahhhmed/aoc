// Reading a file
#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "cal_input.txt";
int main() 
{
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    if(file.is_open()) {
        int calories = 0;
        priority_queue<int, vector<int>> pq;
        while(getline(file, line)) {
            if (!line.length()) {
                pq.push(calories);
                calories = 0;
            } else { 
                calories += stoi(line);
            }
            
        }
        int top_k = 3;
        int sum = 0;
        while (!pq.empty() && top_k > 0) {
            sum += pq.top();
            cout << pq.top() << endl;
            pq.pop();
            top_k--;
        }
        cout << sum << endl;
        file.close();
    } else cout << "Unable to open file";


   
    
    return 0;
}