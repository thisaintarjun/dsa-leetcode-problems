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
    int leftheight(TreeNode* node){
        int h=0;
        while(node){
            node=node->left;
            h++;
        }
        return h;
    }
    int rightheight(TreeNode* node){
        int h=0;
        while(node){
            node=node->right;
            h++;
        }
        return h;
    }
public:
    int countNodes(TreeNode* root) {
        if(root==NULL) return 0;
        int lh=leftheight(root);
        int rh=rightheight(root);
        if(lh==rh) return (1<<lh)-1;
        return 1+countNodes(root->left)+countNodes(root->right);
    }
};