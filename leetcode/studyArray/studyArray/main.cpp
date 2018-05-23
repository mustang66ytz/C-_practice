//
//  main.cpp
//  studyArray
//
//  Created by Yang Taozheng on 5/21/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int pivot;
        
        int leftSum = 0;
        int rightSum = 0;
        for(pivot=0; pivot<nums.size(); pivot++){
            for(int i=0; i<pivot; i++){
                leftSum += nums[i];
            }
            for(int j=pivot+1; j<nums.size(); j++){
                rightSum += nums[j];
            }
            if(leftSum == rightSum){
                return pivot;
            }
            leftSum = 0;
            rightSum = 0;
        }
        return -1;
    }
    
    int dominantIndex(vector<int>& nums) {
        int max = INT_MIN;
        int maxIndex = 0;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>max){
                max = nums[i];
                maxIndex = i;
            }
        }
        
        int halfMax = max/2;
        
        for(int i=0; i<nums.size(); i++){
            if(nums[i]>halfMax && i!=maxIndex){
                return -1;
            }
        }
        
        return maxIndex;
    }
    
    vector<int> plusOne(vector<int>& digits) {
        int integer = 0;
        for(int i=0; i<digits.size(); i++){
            integer*=10;
            integer+=digits[i];
        }
        
        int resultInt = integer + 1;
        vector<int> resultVec;
        vector<int>::iterator it;
        
        int temp = 0;
        while(resultInt>0){
            temp = resultInt % 10;
            resultInt = resultInt/10;
            it = resultVec.begin();
            resultVec.insert(it, temp);
        }
        
        return resultVec;
    }
};



int main(int argc, const char * argv[]) {
    Solution sol;
    vector<int> input = {1,2,3};
    int res = sol.pivotIndex(input);
    int dominantIndex = sol.dominantIndex(input);
    vector<int> plusone = sol.plusOne(input);
    
    cout << "The result is "<< res << endl;
    cout<<"The dominant index of the input is "<<dominantIndex<<endl;
    
    cout<<"The vector after plus one is "<< endl;
    for(int& x:plusone){
        cout<<x<<" "<<endl;
    }
    return 0;
}
