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

    void helper(TreeNode* root,int curr,int &ans){
        if(root==NULL){
            return;
        }
        curr=curr*10+root->val;
        if(root->left==NULL &&root->right==NULL){
            ans+=curr;
        }
        helper(root->left,curr,ans);
        helper(root->right,curr,ans);
    }
    int sumNumbers(TreeNode* root) {
        int curr=0;
        int ans=0;
        helper(root,curr,ans);
        return ans;
    }
};