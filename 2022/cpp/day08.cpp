#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;
const string INPUT_STREAM_NAME = "day08.txt";
vector<vector<int>> tree;
vector<pair<int, int>> nodes;


int count_scenic_score(int y,  int x) { 
    if (y <= 0 || y >= tree.size() - 1 || x <= 0 || x >= tree[0].size() - 1) return 1;
    int s_1 = 0;
    int val = tree[y][x];

    cout << "val: " << val << '\n';
    cout << "y: " << y << '\n';
    cout << "x: " << x << '\n';
    // cols
    
    for (int i = y - 1; i >= 0; i--) {
        if (tree[i][x] < val) {
            s_1 += 1;
        }

        if (tree[i][x] >= val) {
            s_1 += 1;
            break;
        }
        
    }

    int s_2 = 0;
    for (int i = y + 1; i <= tree.size() - 1; i++) { 
        if (tree[i][x] < val) {
            s_2 += 1;
        }

        if (tree[i][x] >= val) {
            s_2 += 1;
            break;
        }
        
    }

    // rows
    int s_3 = 0;
    for (int i = x - 1; i >= 0; i--) {
        if (tree[y][i] < val) {
            s_3 += 1;
        }
        if (tree[y][i] >= val) {
            s_3 += 1;
            break;
        }
        
    }

    int s_4 = 0;
    for (int i = x + 1; i <= tree[0].size() - 1; i++) {
        if (tree[y][i] < val) {
            s_4 += 1;
        }
        if (tree[y][i] >= val) {
            s_4 += 1;
            break;
        }
        

    }
    cout << "s_1: " << s_1 << '\n';
    cout << "s_2: " << s_2 << '\n';
    cout << "s_3: " << s_3 << '\n';
    cout << "s_4: " << s_4 << '\n';
    cout << s_1 * s_2 * s_3 * s_4 << '\n';
    return s_1 * s_2 * s_3 * s_4;

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
            vector<int> row(line.length());
            for (int i = 0; i < line.length(); i++) { 
                row[i] = line[i] - '0';
            }
            tree.emplace_back(row);
        }
        vector<vector<bool>> bool_matrix(tree.size(), vector<bool>(tree[0].size(), false));
        
        // rows
        for (int i = 0; i < tree.size(); i++) { 
            int l = 0;
            int max_from_left = tree[i][l];
            int r = tree[0].size() - 1;
            int max_from_right = tree[i][r];
            bool_matrix[i][l] = true;
            bool_matrix[i][r] = true;
            while (l <= tree[0].size() - 1 && r >= 0) {
                if (tree[i][l] > max_from_left) {
                    max_from_left = tree[i][l];
                    bool_matrix[i][l] = true;
                }

                if (tree[i][r] > max_from_right) {
                    max_from_right = tree[i][r];
                    bool_matrix[i][r] = true;
                }
                l++;
                r--;
            }
        }

        // cols 

        for (int i = 0; i < tree[0].size(); i++) { 
            int t = 0;
            int max_from_top = tree[t][i];
            int b = tree.size() - 1;
            int max_from_bot = tree[b][i];
            bool_matrix[t][i] = true;
            bool_matrix[b][i] = true;
            while (t <= tree.size() - 1 && b >= 0) {
                if (tree[t][i] > max_from_top) {
                    max_from_top = tree[t][i];
                    bool_matrix[t][i] = true;
                }

                if (tree[b][i] > max_from_bot) {
                    max_from_bot = tree[b][i];
                    bool_matrix[b][i] = true;
                }
                t++;
                b--;
            }
        }

        file.close();


        int c = 0;
        for (int i = 0; i < tree.size(); i++) { 
            for (int j = 0; j < tree[0].size(); j++) {
                c += bool_matrix[i][j];
                if (bool_matrix[i][j]) {
                    nodes.emplace_back(i, j);
                }
                cout << bool_matrix[i][j] << ' ';
            }
            
            cout << '\n';
        }

        cout << c << '\n';
    } else cout << "Unable to open file";
}

void get_p2() {    
    string line;
    ifstream file(INPUT_STREAM_NAME);
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int sum = INT_MIN;
    for (auto i: nodes) { 
        sum = max(count_scenic_score(i.first, i.second), sum);
    }

    cout << sum << '\n';

}



int main() {
    get_p1();
    get_p2();
    return 0;
}
