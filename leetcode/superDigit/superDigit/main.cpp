//
//  main.cpp
//  superDigit
//
//  Created by Yang Taozheng on 6/5/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <fstream>
#include <vector>
#include <Eigen>
using namespace std;

vector<string> split_string(string);

// Complete the digitSum function below.
int helper(int curr){
    int currSum = 0;
    while(curr>0){
        currSum += curr%10;
        curr/=10;
    }
    if(currSum>=10){
        return helper(currSum);
    }
    else{
        return currSum;
    }
}

int digitSum(string n, int k) {
    string newN;
    for(int i=0; i<k; i++){
        newN+=n;
    }
    int curr = stoi(newN);
    int result = helper(curr);
    return result;
}

int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));
    
    string nk_temp;
    getline(cin, nk_temp);
    
    vector<string> nk = split_string(nk_temp);
    
    string n = nk[0];
    
    int k = stoi(nk[1]);
    
    int result = digitSum(n, k);
    
    cout<< result <<endl;
    fout << result << "\n";
    
    fout.close();
    
    return 0;
}

vector<string> split_string(string input_string) {
    string::iterator new_end = unique(input_string.begin(), input_string.end(), [] (const char &x, const char &y) {
        return x == y and x == ' ';
    });
    
    input_string.erase(new_end, input_string.end());
    
    while (input_string[input_string.length() - 1] == ' ') {
        input_string.pop_back();
    }
    
    vector<string> splits;
    char delimiter = ' ';
    
    size_t i = 0;
    size_t pos = input_string.find(delimiter);
    
    while (pos != string::npos) {
        splits.push_back(input_string.substr(i, pos - i));
        
        i = pos + 1;
        pos = input_string.find(delimiter, i);
    }
    
    splits.push_back(input_string.substr(i, min(pos, input_string.length()) - i + 1));
    
    return splits;
}

