//
//  main.cpp
//  palindrome
//
//  Created by Yang Taozheng on 5/16/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
class Solution {
private:
    int reversed;
    int temp;
public:
    bool isPalindrome(int x) {
        if(x<0){
            return 0;
        }
        temp = x;
        while(temp!=0){
            reversed = reversed*10 + temp%10;
            temp = temp/10;
        }
        if(x == reversed){
            return 1;
        }
        else{
            return 0;
        }
        
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    int input = 1;
    bool result = sol.isPalindrome(input);
    std::cout << "The result is "<< result;
    std::cout << "Hello, World!\n";
    return 0;
}
