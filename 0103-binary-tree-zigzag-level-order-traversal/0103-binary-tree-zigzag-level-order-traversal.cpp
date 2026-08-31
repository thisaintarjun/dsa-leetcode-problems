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
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> result;
        if(!root) return result;

        queue<TreeNode*> nodeQueue;
        bool lefttoright=true;

        nodeQueue.push(root);

        while(!nodeQueue.empty()){
            int size=nodeQueue.size();
            vector<int> level(size);
            for(int i=0;i<size;i++){
                TreeNode* node = nodeQueue.front();
                nodeQueue.pop();
                int index = (lefttoright)? i: (size-1-i);

                level[index]=node->val;

                if(node->left){
                    nodeQueue.push(node->left);
                }
                
                if(node->right){
                    nodeQueue.push(node->right);
                }
            }
            lefttoright=!lefttoright;
            result.push_back(level);
        }
        return result;
    }
};