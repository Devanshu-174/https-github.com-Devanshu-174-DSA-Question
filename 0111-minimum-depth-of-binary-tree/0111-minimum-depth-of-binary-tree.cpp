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
    int minDepth(TreeNode* root) {
        if(root==NULL){return 0;}

        int leftHt=minDepth(root->left);
        int rightHt=minDepth(root->right);

        if(leftHt==0){
            return leftHt=rightHt+1;
        }

        if(rightHt==0){
            return rightHt=leftHt+1;
        }

        return min(leftHt,rightHt)+1;
    }
};