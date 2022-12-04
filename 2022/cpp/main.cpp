
#include <iostream>
#include <fstream>  
#include <bits/stdc++.h>
using namespace std;
const string INPUT_STREAM_NAME = "template.cpp";

int main () {
    for (int i = 5; i <= 25; i++) {
        std::ofstream outfile ("day0" + to_string(i) + ".cpp");
        // input file
        std::ofstream input_out ("day0" + to_string(i) + ".txt");
        string line;
        ifstream file(INPUT_STREAM_NAME);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(file.is_open()) {
            while(getline(file, line)) {
                if (line.find("day0X") != string::npos) {
                    line.replace(line.find("day0X"), 5, "day0" + to_string(i));
                }
                outfile << line << endl;
            }
           
            file.close();
        } else cout << "Unable to open file";

        input_out.close();
        outfile.close();
    }
    
    
    return 0;
}
