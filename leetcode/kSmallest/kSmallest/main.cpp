//
//  main.cpp
//  kSmallest
//
//  Created by Yang Taozheng on 5/23/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

class Solution{
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        int n = matrix.size(),l = matrix[0][0], r = matrix[n-1][n-1], cnt=0;
        while(l<r){
            int m = l+(r-l)/2, cnt=0;
            for(int i = 0, j = n-1; i < n; i++){
                while(j >= 0 && matrix[i][j] > m ) --j;
                cnt +=j+1;
            }
            if (cnt < k) l = m+1;
            else r=m;
        }
        return l;
    }
    
    int numSquares(int n) {
        int count = 0;
        int root;
        int curr = n;
        int minCount = INT_MAX;
        
        for(root = sqrt(curr); root>0; root--){
            curr = n;
            count = 0;
            int temproot = root;
            while(curr>0){
                curr -= temproot*temproot;
                temproot = sqrt(curr);
                count++;
            }
            minCount = min(minCount, count);
        }
        
        
        return minCount;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    vector<vector<int>> matrix = {{1, 5, 9}, {10, 11, 13}, {12, 13, 15}};
    int k = 8;
    int res = sol.kthSmallest(matrix, k);
    std::cout << "The kth smallest element is "<< res << endl;
    
    int n = 12;
    cout<<"The minimum number of sqrt is "<<sol.numSquares(n)<<endl;
    return 0;
}
