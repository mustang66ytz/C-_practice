//
//  main.cpp
//  groupAnagrams
//
//  Created by Yang Taozheng on 5/21/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // result is for storing the resulting 2d vector
        // map is for storing keys appeared
        vector<vector<string>> result;
        map<string, int> test;
        int nums = strs.size();
        
        for(int i = 0; i < nums; i++)
        {
            string temp = strs[i];
            //sort through all the words in the input list to extract all the unique keys
            sort(temp.begin(), temp.end());
            // if the key is not in the map, use the map to track the key's row number, and increase the result vector by one row
            if(test.count(temp) == 0)
            {
                test[temp] = result.size();
                vector<string> v;
                v.push_back(strs[i]);
                result.push_back(v);
            }
            // if the key is already in the hashmap, retrive the number of row it should be inserted into, and insert it into that row of vector
            else
            {
                result[test[temp]].push_back(strs[i]);
            }
        }
        
        return result;
    }
};

int main(int argc, const char * argv[]) {
    vector<string> input = {"eat", "tea", "tan", "ate", "nat", "bat"};
    Solution sol;
    vector<vector<string>> res = sol.groupAnagrams(input);
    
    for(int i=0; i<res.size(); i++){
        for(int j=0; j<res[i].size(); j++){
            cout<<res[i][j]<<endl;
        }
    }
    return 0;
}
