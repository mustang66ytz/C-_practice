//
//  main.cpp
//  minTimeDiff
//
//  Created by Yang Taozheng on 5/23/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    int findMinDifference(vector<string>& timePoints) {
        int min = INT_MAX;
        int temp;
        for(int i=0; i<timePoints.size(); i++){
            for(int j=i+1; j<timePoints.size(); j++){
                temp = differenceBetweenTwoPts(timePoints[i], timePoints[j]);
                if(temp<min){
                    min = temp;
                }
            }
        }
        return min;
    }
    
    int differenceBetweenTwoPts(string& t1, string& t2){
        int t1Int = convertToInt(t1);
        int t2Int = convertToInt(t2);
        
        if(t1Int<t2Int){
            if((t2Int-t1Int) < t1Int+24*60-t2Int){
                return t2Int-t1Int;
            }
            else{
                return t1Int+24*60-t2Int;
            }
        }
               
       else{
           if(t1Int-t2Int < t2Int+24*60-t1Int){
               return t1Int-t2Int;
           }
           else{
               return t2Int+24*60-t1Int;
           }
       }
    }
               
   int convertToInt(string& timeStr){
       bool flag = 0;
       int result1 = 0;
       int result2 = 0;
       
       for(int i=0; i<timeStr.length(); i++){
           if(flag == 0 && timeStr[i]!=':'){
               result1*=10;
               result1 += timeStr[i]-'0';
           }
           if(timeStr[i] == ':'){
               result1*=60;
               flag = 1;
           }
           if(flag == 1 && timeStr[i]!=':'){
               result2*=10;
               result2 += timeStr[i]-'0';
           }
       }
       
       return result1+result2;
   }
};
               
int main(int argc, const char * argv[]) {
    Solution sol;
    vector<string> input = {"23:59","00:00"};
    int res=sol.findMinDifference(input);
    std::cout << "The minimum difference is: "<<res<<endl;
    return 0;
}
