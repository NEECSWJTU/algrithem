#include <iostream>
#include <stdio.h>
#include <vector>
#include <stack>

using namespace std;

struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };

TreeNode* reConstructBinaryTree(vector<int> pre,vector<int> vin) {
    int i = 0;
    int pos = 0;
    vector<int> pre_left;
    vector<int> vin_left;
    vector<int> pre_right;
    vector<int> vin_right;
    
    TreeNode *root = NULL;
    if(pre.size() == 0 || vin.size() == 0){
        return NULL;
    }
    root = new TreeNode(pre[0]);
    //root->val = pre[0];
    for(i = 0;i < vin.size();i++){
        if(vin[i] == pre[0]){
            break;
        }
    }
    pos = i;
    for(i = 0;i < pos;i++){
        pre_left.push_back(pre[i+1]);
        vin_left.push_back(vin[i]);
    }
    root->left = reConstructBinaryTree(pre_left,vin_left);
    
    for(i = pos + 1; i < pre.size();i++){
        pre_right.push_back(pre[i]);
        vin_right.push_back(vin[i]);
    }
    root->right = reConstructBinaryTree(pre_right,vin_right);
    
    return root;
}

void pre_traverse(TreeNode *head){
    if(head != NULL){
        printf("%d ",head->val);
        pre_traverse(head->left);
        pre_traverse(head->right);
    }
}

void pre_traverse_while(TreeNode *head){
    stack<TreeNode *> s;
    TreeNode *tmp;
    if(head != NULL)
    s.push(head);
    while(!s.empty()){
        tmp = s.top();
        printf("%d ",tmp->val);
        s.pop();
        if(tmp->right != NULL){
            s.push(tmp->right);
        }
        if(tmp->left != NULL){
            s.push(tmp->left);
        }
    }
}

int main(){
    TreeNode *head;
    vector<int> pre = {1,2,4,7,3,5,6,8};
    vector<int> vin = {4,7,2,1,5,3,8,6};

    head = reConstructBinaryTree(pre,vin);
    pre_traverse(head);

    printf("\n");

    pre_traverse_while(head);
}