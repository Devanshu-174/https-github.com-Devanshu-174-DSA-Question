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

    bool solver(TreeNode* root,const int value){
        if(root==NULL){
            return true;
        }
        if(value!=root->val){
            return false;
        }

        return solver(root->left,value) && solver(root->right,value);
    }

    bool isUnivalTree(TreeNode* root) {
        const int value=root->val;
        return solver(root,value);
    }
};