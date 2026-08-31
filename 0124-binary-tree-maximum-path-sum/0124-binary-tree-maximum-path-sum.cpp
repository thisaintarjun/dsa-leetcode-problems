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
    int maxPathDown(TreeNode* root, int& max_sum){
        if(!root) return 0;

        int left=max(0,maxPathDown(root->left,max_sum));
        int right=max(0,maxPathDown(root->right,max_sum));
        max_sum=max(max_sum,(root->val + left + right));

        return max(left,right)+root->val;
    }
public:
    int maxPathSum(TreeNode* root) {
        int max_sum=INT_MIN;
        maxPathDown(root, max_sum);
        return max_sum;
    }
};