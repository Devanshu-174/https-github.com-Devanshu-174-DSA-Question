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
    int height(TreeNode* root){
        if(root==0){
            return 0;
        }
        int leftHt=height(root->left);
        int rightHt=height(root->right);
        int currHt=max(leftHt,rightHt)+1;
        return currHt;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        if(root==NULL){
            return 0;
        }
        int currdia=height(root->left)+height(root->right);
        int leftdia=diameterOfBinaryTree(root->left);
        int rightdia=diameterOfBinaryTree(root->right);

        int ans=max(currdia,max(leftdia,rightdia));

        return ans;
    }
};