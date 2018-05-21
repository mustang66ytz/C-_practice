//
//  main.cpp
//  wordBreak
//
//  Created by Yang Taozheng on 5/21/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <set>

using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        //initialize a queue to store the strings to be checked
        //initialize a set to mark the visited string
        queue<string> toCheck;
        set<string> visited;
        
        //insert the string to the queue
        toCheck.push(s);
        
        //keep checking the string if the queue is not empty and the string to be checked is not visited yet
        while(!toCheck.empty()){
            //extract the current string to be checked
            string curr = toCheck.front();
            //remove the current string from the queue
            toCheck.pop();
            
            //if the current string is empty, means finished all the checking, return true
            if(curr.length() == 0){
                return 1;
            }
            
            //if current string is not visited, marked it as visited, and iterate through the dictionary to check for matching word
            if(visited.find(curr) == visited.end()){
                visited.insert(curr);
                for(auto &x: wordDict){
                    //if get the matching word, insert the substring to be checked into the queue
                    if(contains(curr, x)){
                        string temp = curr.substr(x.size());
                        toCheck.push(temp);
                    }
                }
            }
        }
        //not succedded in finding the combination, then return false
        return 0;
    }
    
    bool contains(string current, string& wordCandidate){
        bool res = 1;
        for(int i=0; i<wordCandidate.length(); i++){
            if(wordCandidate[i]!=current[i]){
                res = 0;
                break;
            }
        }
        return res;
    }
};

int main(int argc, const char * argv[]) {
    string s = "applepenapple";
    vector<string> wordDict = {"apple", "pen"};
    Solution sol;
    bool res = sol.wordBreak(s, wordDict);
    cout << "the result is "<<res<<endl;
    return 0;
}
