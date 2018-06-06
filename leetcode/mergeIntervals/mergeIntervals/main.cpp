//
//  main.cpp
//  mergeIntervals
//
//  Created by Yang Taozheng on 5/29/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <set>
using namespace std;

struct Interval {
     int start;
     int end;
     Interval() : start(0), end(0) {}
     Interval(int s, int e) : start(s), end(e) {}
 };

class Solution {
public:
    vector<Interval> merge(vector<Interval>& intervals) {
        set<int> numbers;
        for(int i=0; i<intervals.size(); i++){
            for(int j=intervals[i].start; j<intervals[i].end; j++){
                numbers.insert(j);
            }
        }
        
        vector<Interval> result;
        
        if(numbers.empty()){
            return result;
        }
        
        int curr = *numbers.begin();
        int prev = curr-1;
        int start = curr;
        for(auto it=numbers.begin(); it!=numbers.end(); it++){
            curr = *it;
            if(prev!=(curr-1)){
                Interval newInterval(start,prev+1);
                start = curr;
                result.push_back(newInterval);
            }
            prev = curr;
        }
        
        Interval newInterval(start, prev+1);
        result.push_back(newInterval);
        
        return result;
    }
};

class Solution2{
public:
    static bool comp(const Interval& a, const Interval& b){
        return a.start<b.start || a.start==b.start&&a.end<b.end;
    }
    vector<Interval> merge(vector<Interval>& intervals) {
        sort(intervals.begin(), intervals.end(), comp);
        vector<Interval> ans;
        for (int i=0; i<intervals.size(); i++) {
            if (!i || intervals[i].start > ans.back().end) ans.push_back(intervals[i]);
            else if (intervals[i].end <= ans.back().end) continue;
            else ans.back().end = intervals[i].end;
        }
        return ans;
    }
    
};

int main(int argc, const char * argv[]) {
    // insert code here...
    Solution sol2;
    vector<Interval> input;
    Interval input1(1,4);
    Interval input2(0,0);
    input.push_back(input1);
    input.push_back(input2);
    vector<Interval> output = sol2.merge(input);
    std::cout << "Hello, World!\n";
    return 0;
}
