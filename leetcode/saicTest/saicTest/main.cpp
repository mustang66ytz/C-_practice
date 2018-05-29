//
//  main.cpp
//  saicTest
//
//  Created by Yang Taozheng on 5/25/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> &A, int X, int Y, int Z) {
    // write your code in C++14 (g++ 6.2.0)
    vector<int> dispcapacity = {X, Y, Z};
    vector<int> dispoccupy = {0, 0, 0};
    vector<int> dispwait = {0, 0, 0};
    int wait = 0;
    int result = 0;
    
    int i=0;
    
    while(A.size()>0){
        if(dispoccupy[0]==1 && dispoccupy[1]==1 && dispoccupy[2]==1){
            int minWait = INT_MAX;
            for(int k=0; k<dispwait.size(); k++){
                if(dispcapacity[k]>=A[i]){
                    if(minWait>=A[i]){
                        minWait = A[i];
                    }
                }
            }
            result += minWait;
            i=0;
        }
        for(int j=0; j<dispoccupy.size(); j++){
            if(dispoccupy[j] == 0 && dispcapacity[j] >= A[i]){
                dispoccupy[j] = 1;
                dispcapacity[j]-=A[i];
                dispwait[j] = A[i];
                
                if(A[i]>=wait){
                    wait = A[i];
                }
                A.erase(A.begin()+i);
            }
        }
        i++;
    }
    
    return result;
}

int main() {
    vector<int> A = {2, 8, 4, 3, 2};
    int X = 7;
    int Y = 11;
    int Z = 3;
    int res = solution(A, X, Y, Z);
    cout<<res<<endl;
    return 0;
}
