//
//  main.cpp
//  studyHash
//
//  Created by Yang Taozheng on 5/24/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class MyHashSet {
private:
    vector<vector<int>> buckets;
    vector<vector<int>>::iterator bucketsIt;
public:
    /** Initialize your data structure here. */
    MyHashSet():buckets(100) {
        
    }
    
    void add(int key) {
        bucketsIt = buckets.begin();
        int bucketsNum = hashCode(key);
        if(!contains(key)){
            buckets[bucketsNum].push_back(key);
        }
    }
    
    void remove(int key) {
        int bucketsNum = hashCode(key);
        int indexRemove;
        if(contains(key)){
            for(int i=0; i<buckets[bucketsNum].size(); i++){
                if(buckets[bucketsNum][i] == key){
                    indexRemove = i;
                    break;
                }
            }
            buckets[bucketsNum].erase(buckets[bucketsNum].begin()+indexRemove);
        }
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        int bucketsNum = hashCode(key);
        for(int i=0; i<buckets[bucketsNum].size(); i++){
            if(buckets[bucketsNum][i] == key){
                return 1;
            }
        }
        return 0;
    }
    
    int hashCode(int key){
        return key%100;
    }
    
};

struct Node {
    int key;
    int val;
    Node(int x, int y): key(x), val(y){}
};




class MyHashMap {
private:
    vector<vector<Node>> buckets;
    vector<vector<Node>>::iterator bucketsIt;
public:
    /** Initialize your data structure here. */
    MyHashMap():buckets(100) {
        
    }
    
    /** value will always be positive. */
    void put(int key, int value) {
        bucketsIt = buckets.begin();
        int bucketsNum = hashCode(key);
        
        if(!contains(key)){
            Node newNode(key, value);
            buckets[bucketsNum].push_back(newNode);
        }
        
        else{
            for(int i=0; i<buckets[bucketsNum].size(); i++){
                if(key == buckets[bucketsNum][i].key){
                    buckets[bucketsNum][i].val = value;
                }
            }
        }
        
    }
    
    /** Returns the value to which the specified key is mapped, or -1 if this map contains no mapping for the key */
    int get(int key) {
        int bucketsNum = hashCode(key);
        for(int i=0; i<buckets[bucketsNum].size(); i++){
            if(key == buckets[bucketsNum][i].key){
                return buckets[bucketsNum][i].val;
            }
        }
        return -1;
    }
    
    int hashCode(int key){
        return key%100;
    }
    
    /** Removes the mapping of the specified value key if this map contains a mapping for the key */
    void remove(int key) {
        int bucketsNum = hashCode(key);
        int indexRemove;
        if(contains(key)){
            for(int i=0; i<buckets[bucketsNum].size(); i++){
                if(buckets[bucketsNum][i].key == key){
                    indexRemove = i;
                    break;
                }
            }
            buckets[bucketsNum].erase(buckets[bucketsNum].begin()+indexRemove);
        }
    }
    
    /** Returns true if this set did not already contain the specified element */
    bool contains(int key) {
        int bucketsNum = hashCode(key);
        for(int i=0; i<buckets[bucketsNum].size(); i++){
            if(buckets[bucketsNum][i].key == key){
                return 1;
            }
        }
        return 0;
    }
    
};


class TwoSum {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, vector<int>> map;
        vector<int> result;
        
        int index=0;
        for(int key: nums){
            if(map.count(key)<=0){
                vector<int> newVec;
                newVec.push_back(index);
                map.insert(make_pair(key, newVec));
            }
            else{
                map[key].push_back(index);
            }
            index++;
        }
        
        for(int key: nums){
            int temp = target - key;
            if(map.count(temp)>0){
                if(temp == key){
                    if(map[temp].size()>1){
                        result.push_back(map[temp][0]);
                        result.push_back(map[temp][1]);
                        break;
                    }
                }
                else{
                    result.push_back(map[key][0]);
                    result.push_back(map[temp][0]);
                    break;
                }
            }
        }
        
        return result;
    }
};

/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet obj = new MyHashSet();
 * obj.add(key);
 * obj.remove(key);
 * bool param_3 = obj.contains(key);
 */

int main(int argc, const char * argv[]) {
    MyHashSet hsh;
    hsh.add(1);
    hsh.add(2);
    cout<<"contains 1? "<<hsh.contains(1)<<endl;    // returns true
    cout<<"contains 3? "<<hsh.contains(3)<<endl;    // returns false (not found)
    hsh.add(2);
    cout<<"contains 2? "<<hsh.contains(2)<<endl;    // returns true
    hsh.remove(2);
    cout<<"contains 2? "<<hsh.contains(2)<<endl;    // returns false (already removed)
    std::cout << "Hello, World!\n";
    
    
    MyHashMap hmp;
    hmp.put(1, 1);
    hmp.put(2, 2);
    cout<<"get 1? "<<hmp.get(1)<<endl;    // returns 1
    cout<<"get 1? "<<hmp.get(3)<<endl;    // returns -1
    hmp.put(2, 1);          // update the existing value
    cout<<"get 2? "<<hmp.get(2)<<endl;    // returns 1
    hmp.remove(2);          // remove the mapping for 2
    cout<<"get 2? "<<hmp.get(2)<<endl;            // returns -1 (not found)
    
    
    cout<<"twoSum part"<<endl;
    TwoSum twosum;
    vector<int> input = {3, 3};
    int target = 6;
    vector<int> output = twosum.twoSum(input, target);
    for(int x:output){
        cout<<x<<endl;
    }
    
    return 0;
}
