//
//  main.cpp
//  atoi
//
//  Created by Yang Taozheng on 5/16/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <stdlib.h>
#include <cmath>
using namespace std;

class Solution {
private:
    bool sign = 0;
    bool flag = 0;
    bool containsDot = 0;
    int temp = 0;
    int lasttemp = 0;
public:
    int myAtoi(string str) {
        for(int i=0; i<str.length(); i++){
            
            if(str[i]==43){
                sign = 0;
            }
            if(str[i]==45){
                sign = 1;
            }
            if(str[i]==46){
                containsDot = 1;
            }
            if(str[i]<=57 && str[i]>=48 && !containsDot){
                flag = 1;
                if(sign == 0){
                    lasttemp = temp;
                    temp = temp*10 + (str[i]-48);
                    if(lasttemp>temp){
                        return INT_MIN;
                    }
                }
                else{
                    lasttemp = temp;
                    temp = temp*10 - (str[i]-48);
                    if(lasttemp<temp){
                        return INT_MIN;
                    }
                }
            }
            
            if(flag==0 && str[i]!=32 && str[i]!=45 && str[i]!=43 && (str[i]<48 || str[i]>57)){
                return 0;
            }
        }
        return temp;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    std::cout << "Hello, World!\n";
    // initialize a string
    string input = "+3.24";
    Solution output;
    int res = output.myAtoi(input);
    cout<<"The result is "<<res<<endl;
    return 0;
}
