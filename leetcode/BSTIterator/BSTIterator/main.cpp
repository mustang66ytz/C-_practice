//
//  main.cpp
//  BSTIterator
//
//  Created by Yang Taozheng on 5/28/18.
//  Copyright © 2018 Yang Taozheng. All rights reserved.
//

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
     int val;
     TreeNode *left;
     TreeNode *right;
     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class BSTIterator {
    vector<int> inorderTraverse;
    int currPos;
    int* ptr;
public:
    BSTIterator(TreeNode *root) {
        bst(root);
//        for(int i=0; i<inorderTraverse.size(); i++){
//            if(inorderTraverse[i] == root->val){
//                currPos = i;
//            }
//        }
        currPos = 0;
        ptr = &inorderTraverse[currPos];
    }
    
    void bst(TreeNode *root){
        if(root == NULL){
            return;
        }
        bst(root->left);
        inorderTraverse.push_back(root->val);
        bst(root->right);
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        
        if(currPos < inorderTraverse.size()){
            ptr = &inorderTraverse[currPos];
            currPos++;
            return true;
        }
        return false;
    }
    
    /** @return the next smallest number */
    int next() {
        return *ptr;
    }
};

class BSTIterator2 {
public:
    BSTIterator2(TreeNode *root){
        while (root) {
            s.push(root);
            root = root->left;
        }
    }
    
    /** @return whether we have a next smallest number */
    bool hasNext() {
        return !s.empty();
    }
    
    /** @return the next smallest number */
    int next() {
        TreeNode * curr = s.top();
        s.pop();
        
        int val = curr->val;
        curr = curr->right; // take the left most of the righ subtree
        while (curr) {
            s.push(curr);
            curr = curr->left;
        }
        return val;
    }
private:
    stack<TreeNode *> s;
};

int main(int argc, const char * argv[]) {
    // insert code here...
    TreeNode root = NULL;
    TreeNode left = NULL;
    TreeNode right = NULL;
    
    root.left = &left;
    root.right = &right;
    BSTIterator2 it(&root);
    cout<< it.hasNext() <<endl;
    cout<< it.next() <<endl;
    std::cout << "Hello, World!\n";
    return 0;
}
