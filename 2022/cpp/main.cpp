
#include <iostream>
#include <fstream>  
#include <bits/stdc++.h>
using namespace std;
const string INPUT_STREAM_NAME = "template.cpp";

int main () {
    for (int i = 5; i <= 25; i++) {
        string file_name;
        if (i < 10) {
            file_name = "day0" + to_string(i);
        } else {
            file_name = "day" + to_string(i);
        }
        std::ofstream outfile (file_name + ".cpp");
        // input file
        std::ofstream input_out (file_name + ".txt");
        string line;
        ifstream file(INPUT_STREAM_NAME);
        ios_base::sync_with_stdio(false);
        cin.tie(nullptr);
        cout.tie(nullptr);
        
        if(file.is_open()) {
            while(getline(file, line)) {
                if (line.find("day0X") != string::npos) {
                    line.replace(line.find("day0X"), 5, file_name + to_string(i));
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
