//
//  main.cpp
//  replaceWords
//
//  Created by Yang Taozheng on 5/26/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <string>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution {
public:
    string replaceWords(vector<string>& dict, string sentence) {
        string resultSentence = "";
        vector<string> originalSentence;
        unordered_set<string> dictSet;
        
        for(string x: dict){
            dictSet.insert(x);
        }
        
        string tempWord = "";
        for(int i=0; i<sentence.length(); i++){
            if(sentence[i] == ' ' || i==sentence.length()-1){
                originalSentence.push_back(tempWord);
                tempWord = "";
                continue;
            }
            else{
                tempWord+=sentence[i];
            }
        }
        
        string wordInSentence;
        int lengthOfWord;
        for(int i=0; i<originalSentence.size(); i++){
            wordInSentence = originalSentence[i];
            lengthOfWord = originalSentence[i].length();
            int currLength = 1;
            
            while(currLength<lengthOfWord){
                string subString = wordInSentence.substr(0, currLength);
                if(dictSet.count(subString)>0){
                    resultSentence += subString;
                    resultSentence += ' ';
                    break;
                }
                currLength++;
            }
            
            if(currLength == lengthOfWord){
                resultSentence += wordInSentence;
                resultSentence += ' ';
            }
        }
        
        resultSentence.erase(resultSentence.end());
        return resultSentence;
    }
};

int main(int argc, const char * argv[]) {
    Solution sol;
    
    vector<string> input = {"cat", "bat", "rat"};
    string sentence = "the cattle was rattled by the battery";
    string output = sol.replaceWords(input, sentence);
    cout<< sentence <<endl;
    std::cout << output <<endl;;
    return 0;
}
