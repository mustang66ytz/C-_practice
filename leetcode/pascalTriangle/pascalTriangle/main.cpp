//
//  main.cpp
//  pascalTriangle
//
//  Created by Yang Taozheng on 6/3/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        
        vector<vector<int>> res;
        if(numRows == 0){
            return res;
        }
        vector<int> firstRow(1,1);
        res.push_back(firstRow);
        if(numRows == 1){
            return res;
        }
        
        int count = 2;
        for(int k=1; k<numRows; k++){
            vector<int> newRow;
            count++;
            for(int l=0; l<count-1; l++){
                if(l==0 || l==count-2){
                    newRow.push_back(1);
                }
                else{
                    int temp = res[k-1][l-1]+res[k-1][l];
                    newRow.push_back(temp);
                }
            }
            res.push_back(newRow);
        }
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol;
    vector<vector<int>> output;
    output = sol.generate(5);
    std::cout << "Hello, World!\n";
    return 0;
}
