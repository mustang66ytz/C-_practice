//
//  main.cpp
//  studyLinkedList
//
//  Created by Yang Taozheng on 5/14/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
struct SinglyListNode {
    int val;
    SinglyListNode *next;
    SinglyListNode(int x) : val(x), next(NULL) {}
};

class MyLinkedList {
private:
    SinglyListNode* head;
    SinglyListNode* tail;
    
public:
    /** Initialize your data structure here. */
    MyLinkedList() {
        this->head = NULL;
    }
    
    /** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
    int get(int index) {
        SinglyListNode *temp = this->head;
        int tempidx = 0;
        while(temp!=NULL){
            if(tempidx == index){
                return temp->val;
            }
            tempidx++;
            temp = temp->next;
        }
        return -1;
    }
    
    /** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
    void addAtHead(int val) {
        SinglyListNode *curr = new SinglyListNode(val);
        curr->next = this->head;
        head = curr;
    }
    
    /** Append a node of value val to the last element of the linked list. */
    void addAtTail(int val) {
        SinglyListNode *curr = new SinglyListNode(val);
        SinglyListNode *temp = this->head;
        while(temp->next != NULL){
            temp = temp->next;
        }
        temp->next = curr;
    }
    
    /** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
    void addAtIndex(int index, int val) {
        int tempidx = 0;
        SinglyListNode *curr = new SinglyListNode(val);
        SinglyListNode *temp = this->head;
        while(tempidx<index-1){
            temp = temp->next;
            tempidx++;
        }
        curr->next = temp->next;
        temp->next = curr;
    }
    
    /** Delete the index-th node in the linked list, if the index is valid. */
    void deleteAtIndex(int index) {
        int tempidx = 0;
        SinglyListNode *temp = this->head;
        while(temp->next != NULL && tempidx<index-1){
            temp = temp->next;
            tempidx++;
        }
        temp->next = temp->next->next;
    }
    
    void display()
    {
        SinglyListNode *tmp;
        tmp = head;
        while (tmp != NULL)
        {
            std::cout << tmp->val << " ";
            tmp = tmp->next;
        }
        std::cout<<std::endl;
    }
    
    SinglyListNode* removeNthFromEnd(SinglyListNode* head, int n) {
        
    }
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList obj = new MyLinkedList();
 * int param_1 = obj.get(index);
 * obj.addAtHead(val);
 * obj.addAtTail(val);
 * obj.addAtIndex(index,val);
 * obj.deleteAtIndex(index);
 */


int main(int argc, const char * argv[]) {
    MyLinkedList* linkedList = new MyLinkedList();

    linkedList->addAtHead(1);
    linkedList->display();
    linkedList->addAtTail(3);
    linkedList->display();
    linkedList->addAtIndex(1, 2);  // linked list becomes 1->2->3
    linkedList->display();
    std::cout<<"should return 2 here "<<linkedList->get(1)<<std::endl;
    linkedList->display();
    linkedList->deleteAtIndex(1);  // now the linked list is 1->3
    std::cout<<"should return 3 here "<<linkedList->get(1)<<std::endl;            // returns 3
    
    std::cout << "Hello, World!\n";
    linkedList->display();
    return 0;
}
