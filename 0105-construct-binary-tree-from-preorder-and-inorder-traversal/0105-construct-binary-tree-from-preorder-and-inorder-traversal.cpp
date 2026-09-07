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
    TreeNode* buildTree(vector<int>preorder, int prestart,int preend,vector<int>inorder, int instart, int inend, map<int, int>& inMap ){
        if(instart>inend||prestart>preend) return NULL;
        TreeNode* root=new TreeNode(preorder[prestart]);
        int inRoot=inMap[root->val];
        int numsLeft=inRoot-instart;
        root->left= buildTree(preorder, prestart+1, preend, inorder, instart, inRoot-1, inMap);
        root->right=buildTree(preorder, prestart+numsLeft+1,preend,inorder, inRoot+1,inend, inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int>inMap;
        for(int i=0;i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root=buildTree(preorder, 0, preorder.size()-1,inorder, 0, inorder.size()-1, inMap);
        return root;
    }
};