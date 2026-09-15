/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class bstiterator{
    stack<TreeNode* >myStack;
    bool reverse;
private:
    void pushall(TreeNode* node){
        while(node){
            myStack.push(node);
            if(reverse){
                node=node->right;
            }
            else{
                node=node->left;
            }
        }
    }
public:
    bstiterator(TreeNode* root, bool isReverse){
        reverse=isReverse; //we do not create a variable cause we need the class member reverse to be set
        pushall(root);
    }
    bool hasnext(){
        return !myStack.empty();
    }
    int next(){
        TreeNode* tempnode=myStack.top();
        myStack.pop();
        if(!reverse) pushall(tempnode->right);
        else pushall(tempnode->left);
        return tempnode->val;
    }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        bstiterator l(root,false);
        bstiterator r(root,true);
        int i=l.next();
        int j=r.next();
        while(i<j){
            if((i+j)>k)j=r.next();
            else if((i+j)<k) i=l.next();
            else return true;
        }
        return false;  //if they cross each other then the while loop won't run and we return false
    }
};