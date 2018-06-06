//
//  main.cpp
//  spiralMatrix
//
//  Created by Yang Taozheng on 6/3/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int goDirect; //0:up 1:right 2:down 3:left
    int colSize;
    int rowSize;
    int i;
    int j;
    int visited;
    int total;
    vector<vector<int>> wall;
    vector<int> res;
    
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.size() == 0){
            return res;
        }
        rowSize = matrix.size();
        colSize = matrix[0].size();
        total = rowSize*colSize;
        visited = 0;
        goDirect = 1;
        
        for(int k=0; k<rowSize+2; k++){
            vector<int> newRow;
            for(int l=0; l<colSize+2; l++){
                if(k==0 || l==0 || k==rowSize+1 || l==colSize+1){
                    newRow.push_back(1);
                }
                else{
                    newRow.push_back(0);
                }
            }
            wall.push_back(newRow);
        }
        
        while(visited<total-1){
            if(goDirect == 0){
                if(wall[i][j+1] == 1){
                    goDirect = 1;
                }
                else{
                    wall[i+1][j+1] = 1;
                    res.push_back(matrix[i][j]);
                    visited++;
                    i--;
                }
            }
            else if(goDirect == 1){
                if(wall[i+1][j+2] == 1){
                    goDirect = 2;
                }
                else{
                    wall[i+1][j+1] = 1;
                    res.push_back(matrix[i][j]);
                    visited++;
                    j++;
                }
            }
            else if(goDirect == 2){
                if(wall[i+2][j+1] == 1){
                    goDirect = 3;
                }
                else{
                    wall[i+1][j+1] = 1;
                    res.push_back(matrix[i][j]);
                    visited++;
                    i++;
                }
            }
            else if(goDirect == 3){
                if(wall[i+1][j] == 1){
                    goDirect = 0;
                }
                else{
                    wall[i+1][j+1] = 1;
                    res.push_back(matrix[i][j]);
                    visited++;
                    j--;
                }
            }
        }
        res.push_back(matrix[i][j]);
        
        return res;
    }
};

int main(int argc, const char * argv[]) {
    // insert code here...
    vector<vector<int>> input = {{1, 2, 3},{4, 5, 6},{7, 8, 9}};
    Solution sol;
    sol.spiralOrder(input);
    std::cout << "Hello, World!\n";
    return 0;
}
