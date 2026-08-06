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
    int leftHt(TreeNode* root){
        if(root==NULL) return 0;
        return 1+leftHt(root->left);
    }

    int rightHt(TreeNode* root){
        if(root==NULL) return 0;
        return 1+rightHt(root->right);
    }
    int countNodes(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int lh=leftHt(root);
        int rh=rightHt(root);
        if(lh==rh){
            return (1<<lh)-1;
        }

        return countNodes(root->left)+countNodes(root->right)+1;
    }
};