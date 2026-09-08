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
    TreeNode* buildTree(vector<int>& inorder, int instart, int inend, vector<int>& postorder, int prostart, int proend, map<int, int>& inMap){
        if(instart>inend||prostart>proend) return NULL;
        TreeNode* root=new TreeNode(postorder[proend]);
        int inroot= inMap[root->val];
        int numsleft=inroot-instart;
        root->left=buildTree(inorder, instart,inroot-1,postorder,prostart,prostart+numsleft-1,inMap);
        root->right=buildTree(inorder,inroot+1,inend,postorder,prostart+numsleft,proend-1,inMap);
        return root;
    }
public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        map<int, int> inMap;
        for(int i=0; i<inorder.size();i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root=buildTree(inorder, 0, inorder.size()-1,postorder, 0, postorder.size()-1,inMap);
        return root;
    }
};