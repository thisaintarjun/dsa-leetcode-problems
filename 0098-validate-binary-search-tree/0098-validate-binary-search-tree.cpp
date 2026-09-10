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
    bool isvalid(TreeNode* root, long long int minval, long long int maxval){
        if(root==NULL) return true;
        if(root->val >= maxval || root->val <= minval) return false;
        return (isvalid(root->left,minval,root->val)&&isvalid(root->right,root->val,maxval));
    }
public:
    bool isValidBST(TreeNode* root) {
        return isvalid(root,LLONG_MIN,LLONG_MAX);
    }
};