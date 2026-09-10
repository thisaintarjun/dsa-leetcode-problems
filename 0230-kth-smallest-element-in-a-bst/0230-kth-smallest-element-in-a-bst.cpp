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
class Solution {
private:
    void inorder(TreeNode* root, int&k,int& count,int& node){
        if(root==NULL) return;
        inorder(root->left,k,count,node);
        count++;
        if(count==k){
            node=root->val;
        }
            
        inorder(root->right,k,count,node);
    }
public:
    int kthSmallest(TreeNode* root, int k) {
        int node;
        int count=0;
        inorder(root,k,count,node);
        return node;
    }
};