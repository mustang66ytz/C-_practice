//
//  main.cpp
//  insertCycliclist
//
//  Created by Yang Taozheng on 6/1/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
using namespace std;

class Node {
public:
    int val = NULL;
    Node* next = NULL;
    
    Node() {}
    
    Node(int _val, Node* _next) {
        val = _val;
        next = _next;
    }
};


class Solution {
public:
    Node* insert(Node* head, int insertVal) {
        if(!head){
            Node* newNode = new Node(insertVal, NULL);
            newNode->next = newNode;
            return newNode;
        }
        while(head->val > insertVal){
            head = head->next;
        }
        while(head->next->val <= insertVal){
            head = head->next;
        }
        Node* newNode = new Node(insertVal, head->next);
        head->next = newNode;
        return newNode->next;
    }
};


int main(int argc, const char * argv[]) {
    Node* node1 = new Node(1, NULL);
    Node* node2 = new Node(3, NULL);
    Node* node3 = new Node(4, NULL);
    
    node1->next = node2;
    node2->next = node3;
    node3->next = node1;
    
    Solution sol;
    Node* result = sol.insert(node2, 2);

    std::cout << "Hello, World!\n";
    return 0;
}
