//
//  main.cpp
//  rotateList
//
//  Created by Yang Taozheng on 5/29/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        vector<int> elements;
        ListNode* temp = head;
        
        while(temp!=NULL){
            elements.push_back(temp->val);
            temp = temp->next;
        }
        
        if(k==0 || head ==NULL){
            return head;
        }
        else{
            k = k%elements.size();
        }
        
        ListNode* newNode = new ListNode(0);
        //ListNode* result = newNode;
        ListNode* curr = newNode;
        vector<int> frontPart;
        
        for(int index=elements.size()-k; index<elements.size(); index++){
            frontPart.push_back(elements[index]);
        }
        for(int index=0; index<elements.size()-k; index++){
            frontPart.push_back(elements[index]);
        }
        for(int index=0; index<frontPart.size(); index++){
            ListNode* newNode2 = new ListNode(frontPart[index]);
            newNode->next = newNode2;
            newNode = newNode->next;
        }
        return curr->next;
    }
};
int main(int argc, const char * argv[]) {
    ListNode input = ListNode(1);
    ListNode input2 = ListNode(2);
    ListNode input3 = ListNode(3);
    ListNode input4 = ListNode(4);
    ListNode input5 = ListNode(5);
    input.next = &input2;
    input2.next = &input3;
    input3.next = &input4;
    input4.next = &input5;
    
    Solution sol;
    ListNode* output = sol.rotateRight(&input, 2);
    
    while(output!=NULL){
        cout<<output->val<<endl;
        output = output->next;
    }
    
    std::cout << "Hello, World!\n";
    return 0;
}
