//
//  main.cpp
//  ladderLength
//
//  Created by Yang Taozheng on 5/21/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <string>
#include <queue>
using namespace std;

class Solution {
private:
    // return true if and only if there is one letter difference between two input string
    bool oneDiff(string& a, string& b) {
        // return false if two strings' sizes are different
        if (a.size() != b.size()) return false;
        int count = 0;
        for (int i = 0; i < a.size(); ++i) {
            if (a[i] == b[i]) ++count;
        }
        // return true if size is one greater than the cout of same letters
        return a.size() - count == 1;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        //min is the result
        //total tracks the number of word to be checked in the next level
        //remain tracks the number of word to be checked in the queue and in the current level, initialized to be 1 means there is one word to be checked, which is the beginWord
        //level tracks the number of transformation
        
        int min = 0, total = 0, remain = 1, level = 0;
        //initializa a queue of words
        queue<string> q;
        q.push(beginWord);
        
        //while the queue is not empty, set the current word to be the head of the queue
        while (q.size()) {
            string current = q.front();
            // if found the target, return the level+1
            if (current == endWord) {
                min = ++level;
                break;
            }
            // for each dequeue, decrease the remain by 1
            --remain;
            q.pop();
            
            // if the list is not empty, iterate to find the word with one letter difference from the current word, enqueue if found, increase the total number of words to be processed by 1, and erase the word from the wordlist
            if (!wordList.empty()) {
                for (long i = wordList.size()-1; i >= 0; --i) {
                    if (oneDiff(wordList[i], current)) {
                        q.push(wordList[i]);
                        ++total;
                        wordList.erase(wordList.begin()+i);
                    }
                }
            }
            
            // if all tasks in the current level are processed and more tasks to be finished, increase the level, update the remain with the total, and set the tasks to be processed in the next level to zero: total = 0
            if (!remain && total > 0) {
                ++level;
                remain = total;
                total = 0;
            }
        }
        // return the result if reach the end of the function
        return min;
    }
};

int main(int argc, const char * argv[]) {
    string beginWord = "hit";
    string endWord = "cog";
    vector<string> wordList{"hot","dot","dog","lot","log","cog"};
    Solution sol;
    int res = sol.ladderLength(beginWord, endWord, wordList);
    cout << "shortest path length is "<< res << endl;
    return 0;
}
