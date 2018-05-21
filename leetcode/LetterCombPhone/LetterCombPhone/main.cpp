//
//  main.cpp
//  LetterCombPhone
//
//  Created by Yang Taozheng on 5/19/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <map>

using namespace std;
class Solution {
public:
    vector<string> letterCombinations(string digits) {
        
        vector<string> res;
        if(digits == ""){
            return res;
        }
        
        string charmap[10] = {"0", "1", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
        res.push_back("");
        for (int i = 0; i < digits.size(); i++)
        {
            vector<string> tempres;
            string chars = charmap[digits[i] - '0'];
            for (int c = 0; c < chars.size();c++)
                for (int j = 0; j < res.size();j++)
                    tempres.push_back(res[j]+chars[c]);
            res = tempres;
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    string input = "23";
    vector<string> output = sol.letterCombinations(input);
    std::cout << "Hello, World!\n"<<endl;
    for(vector<string>::const_iterator i=output.begin(); i!=output.end(); ++i){
        cout<<"The result is "<<*i<<endl;
    }
    return 0;
}
