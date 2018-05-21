//
//  main.cpp
//  removeNthFromEnd
//
//  Created by Yang Taozheng on 5/20/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
private:
    int collen;
    int rowlen;
public:
    bool exist(vector<vector<char>>& board, string word) {
        collen = board[0].size();
        rowlen = board.size();
        
        int pos[2];
        bool temp = 0;
        
        for(int i=0; i<rowlen; i++){
            for(int j=0; j<collen; j++){
                temp = existHelper(pos, 0, word, board);
                if(temp)
                    return 1;
            }
        }
        return 0;
    }
    
    bool existHelper(int prevPos[], int prevIdx, string word, vector<vector<char>> board){
        char curC;
        if( (curC = board[prevPos[0]][prevPos[1]]) != word[prevIdx]){
            return 0;
        }
        if(prevIdx+1 == word.length()){
            return 1;
        }
        char desiredLetter = word[prevIdx+1];
        bool res = 0;
        
        board[prevPos[0]][prevPos[1]] = '*';
        // check up direction
        if(prevPos[0]-1>=0){
            int currPos[2];
            currPos[0] = prevPos[0]-1;
            currPos[1] = prevPos[1];
            res = existHelper(currPos, prevIdx+1, word, board);
        }
        
        // check down direction
        if(prevPos[0]+1<rowlen){
            int currPos[2];
            currPos[0] = prevPos[0]+1;
            currPos[1] = prevPos[1];
            res = existHelper(currPos, prevIdx+1, word, board);
        }
        
        // check left direction
        if(prevPos[1]-1>=0){
            int currPos[2];
            currPos[0] = prevPos[0];
            currPos[1] = prevPos[1]-1;
            res = existHelper(currPos, prevIdx+1, word, board);
        }
        
        // check right direction
        if(prevPos[1]+1<collen){
            int currPos[2];
            currPos[0] = prevPos[0];
            currPos[1] = prevPos[1]+1;
            res = existHelper(currPos, prevIdx+1, word, board);
        }
        
        board[prevPos[0]][prevPos[1]] = curC;
        return res;
    }
};

class Solution2 {
private:
    bool dfs(vector<vector<char>>& board, int row, int col, const string &word, int start, int M, int N, int sLen)
    {
        char curC;
        bool res = false;
        if( (curC = board[row][col]) != word[start]) return false;
        if(start==sLen-1) return true;
        board[row][col] = '*';
        if(row>0) res = dfs(board, row-1, col, word, start+1, M, N, sLen);
        if(!res && row < M-1) res = dfs(board, row+1, col, word, start+1, M, N, sLen);
        if(!res && col > 0)   res = dfs(board, row, col-1, word, start+1, M, N, sLen);
        if(!res && col < N-1) res = dfs(board,  row, col+1, word, start+1, M, N, sLen);
        board[row][col] = curC;
        return res;
    }
    
public:
    bool exist(vector<vector<char>>& board, string word) {
        int M,N,i,j,sLen = word.size();
        if( (M=board.size()) && (N=board[0].size()) && sLen)
        {
            for(i=0; i<M; ++i)
                for(j=0; j<N; ++j)
                    if(dfs(board, i, j, word, 0, M, N, sLen)) return true;
        }
        return false;
    }
};
int main(int argc, const char * argv[]) {
    Solution2 sol;
    vector<vector<char>> board{{'A', 'B', 'C', 'E'},{'S', 'F', 'C', 'S'},{'A', 'D', 'E', 'E'}};
    string targetWord ="ABCCED";
    bool result = sol.exist(board, targetWord);
    
    
    std::cout << "result is "<< result<< std::endl;
    return 0;
}
