//
//  main.cpp
//  IntegerToRoman
//
//  Created by Yang Taozheng on 5/18/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <map>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string res;
        
        if(num>=1000){
            while(num>=1000){
                res.append("M");
                num-=1000;
            }
        }
        if(num>=100){
            if(num>=900){
                res.append("CM");
                num-=900;
            }
            else if(num>=500){
                res.append("D");
                num-=500;
            }
            else if(num>=400){
                res.append("CD");
                num-=400;
            }
            while(num>=100){
                res.append("C");
                num-=100;
            }
        }
        if(num>=10){
            if(num>=90){
                res.append("XC");
                num-=90;
            }
            else if(num>=50){
                res.append("L");
                num-=50;
            }
            else if(num>=40){
                res.append("XL");
                num-=40;
            }
            while(num>=10){
                res.append("X");
                num-=10;
            }
        }
        if(num>=1){
            if(num>=9){
                res.append("IX");
                num-=9;
            }
            else if(num>=5){
                res.append("V");
                num-=5;
            }
            else if(num>=4){
                res.append("IV");
                num-=4;
            }
            while(num>=1){
                res.append("I");
                num-=1;
            }
        }
        return res;
    }
    
public:
    int temp = 0;
    int romanToInt(string s) {
        std::map<char, int> roman = {
            {'I', 1},
            //{'IV', 4},
            {'V', 5},
            //{'IX', 9},
            {'X', 10},
            //{'XL', 40},
            {'L', 50},
            //{'XC', 90},
            {'C', 100},
            //{'CD', 400},
            {'D', 500},
            //{'CM', 900},
            {'M', 1000}
        };
        int i=0;
        while(i<s.size()){
            if(i+1<s.size()){
                if(s[i] == 'I' && s[i+1] == 'V'){
                    temp += 4;
                    i+=2;
                }
                else if(s[i] == 'I' && s[i+1] == 'X'){
                    temp += 9;
                    i+=2;
                }
                else if(s[i] == 'X' && s[i+1] == 'L'){
                    temp += 40;
                    i+=2;
                }
                else if(s[i] == 'X' && s[i+1] == 'C'){
                    temp += 90;
                    i+=2;
                }
                else if(s[i] == 'C' && s[i+1] == 'D'){
                    temp += 400;
                    i+=2;
                }
                else if(s[i] == 'C' && s[i+1] == 'M'){
                    temp += 900;
                    i+=2;
                }
                else{
                    temp += roman[s[i]];
                    i++;
                }
            }
            else{
                temp += roman[s[i]];
                i++;
            }
        }
    return temp;
    }
    
};

int main(int argc, const char * argv[]) {
    int input = 1994;
    Solution sol;
    string output = sol.intToRoman(input);
    std::cout << "the result is "<<output<<endl;
    
    int backtonumber = sol.romanToInt(output);
    std::cout<<"back to integer: "<<backtonumber<<endl;
    return 0;
}
