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
    int solve(TreeNode* root,int value){
        if(!root->left && !root->right) return value+root->val;

        int left=0,right=0;
        if(root->left)left=solve(root->left,(value+root->val)*10);
        if(root->right)right=solve(root->right,(value+root->val)*10);
        return left+right;
    }
    int sumNumbers(TreeNode* root) {
        return solve(root,0);
    }
};