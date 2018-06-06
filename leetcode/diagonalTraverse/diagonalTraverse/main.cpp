//
//  main.cpp
//  diagonalTraverse
//
//  Created by Yang Taozheng on 6/3/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int colSize;
    int rowSize;
    int i;
    int j;
    vector<int> res;
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        rowSize = matrix.size();
        colSize = matrix[0].size();
        i=0;
        j=0;
        
        res.push_back(matrix[0][0]);
        while(i+j < rowSize+colSize-2){
            if((i+j)%2 == 0){
                goRU(matrix);
            }
            else{
                goDL(matrix);
            }
        }
        return res;
    }
    
    void goRU(vector<vector<int>> matrix){
        if(i!=0 && j!=colSize-1){
            i--;
            j++;
            res.push_back(matrix[i][j]);
            return;
        }
        if(i==0 && j!=colSize-1){
            j++;
            res.push_back(matrix[i][j]);
            return;
        }
        if(i!=rowSize-1 && j==colSize-1){
            i++;
            res.push_back(matrix[i][j]);
            return;
        }
        else{
            res.push_back(matrix[i][j]);
            return;
        }
    }
    
    void goDL(vector<vector<int>> matrix){
        if(i!=rowSize-1 && j!=0){
            i++;
            j--;
            res.push_back(matrix[i][j]);
            return;
        }
        if(i==rowSize-1 && j!=colSize-1){
            j++;
            res.push_back(matrix[i][j]);
            return;
        }
        if(i!=rowSize-1 && j==0){
            i++;
            res.push_back(matrix[i][j]);
            return;
        }
    }
};

int main(int argc, const char * argv[]) {
    vector<vector<int>> input = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    Solution sol;
    sol.findDiagonalOrder(input);
    std::cout << "Hello, World!\n";
    return 0;
}
