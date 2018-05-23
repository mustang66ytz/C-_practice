//
//  main.cpp
//  dataSturctO1
//
//  Created by Yang Taozheng on 5/23/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class RandomizedSet {
private:
    vector<int> nums;
    unordered_map<int, int> m;
public:
    /** Initialize your data structure here. */
    RandomizedSet() {
        
    }
    
    /** Inserts a value to the set. Returns true if the set did not already contain the specified element. */
    bool insert(int val) {
        if (m.find(val) != m.end()) return false;
        nums.emplace_back(val);
        m[val] = nums.size() - 1;
        return true;
    }
    
    /** Removes a value from the set. Returns true if the set contained the specified element. */
    bool remove(int val) {
        if (m.find(val) == m.end()) return false;
        int last = nums.back();
        m[last] = m[val];
        nums[m[val]] = last;
        nums.pop_back();
        m.erase(val);
        return true;
    }
    
    /** Get a random element from the set. */
    int getRandom() {
        return nums[rand() % nums.size()];
    }
    
};

int main(int argc, const char * argv[]) {
    RandomizedSet obj;
    bool param_1 = obj.insert(0);
    cout<<param_1<<endl;
    bool param_2 = obj.insert(1);
    cout<<param_2<<endl;
    bool param_3 = obj.remove(0);
    cout<<param_3<<endl;
    bool param_4 = obj.insert(2);
    cout<<param_4<<endl;
    bool param_5 = obj.remove(1);
    cout<<param_5<<endl;
    int param_6 = obj.getRandom();
    cout<<param_6<<endl;
    
    return 0;
}
