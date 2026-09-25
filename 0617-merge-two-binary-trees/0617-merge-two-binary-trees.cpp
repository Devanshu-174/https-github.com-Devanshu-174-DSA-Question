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

    TreeNode* mergeTrees(TreeNode* root1, TreeNode* root2) {
        if(root1==NULL && root2==NULL){
            return NULL;
        }

        TreeNode* root;
        if(root1!=NULL && root2!=NULL){
            root=new TreeNode(root1->val+root2->val);
        }
        else{
            root=new TreeNode(root1==NULL? root2->val:root1->val); 
        }

        root->left=mergeTrees(root1 == NULL ? NULL : root1->left,
            root2 == NULL ? NULL : root2->left);
        root->right=mergeTrees(root1 == NULL ? NULL : root1->right,
            root2 == NULL ? NULL : root2->right);

        return root;
    }
};