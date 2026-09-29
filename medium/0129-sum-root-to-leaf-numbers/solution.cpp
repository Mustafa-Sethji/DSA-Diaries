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
    int Total_sum;
    void path_leaf(TreeNode*root,int curr){
        if(root->left==NULL && root->right==NULL){
            Total_sum+=10*curr+root->val;
            return;
        }
        if(root->left)path_leaf(root->left,10*curr+root->val);
        if(root->right)path_leaf(root->right,10*curr+root->val);
        return;
    }
    int sumNumbers(TreeNode* root) {
        Total_sum=0;
        path_leaf(root,0);
        return Total_sum;
    }
};