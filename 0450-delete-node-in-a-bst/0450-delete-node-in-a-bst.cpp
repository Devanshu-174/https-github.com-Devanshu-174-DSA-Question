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

    TreeNode* InorderSuccessor(TreeNode* root){
        while(root->left!=NULL){
            root=root->left;
        }

        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
        if(root==NULL){
        return NULL;
        }

        if(key<root->val){
            root->left=deleteNode(root->left,key);
            return root;
        }
        else if(key>root->val){
            root->right=deleteNode(root->right,key);
            return root;
        }
        else{
            //root==val;
            //case1:No child
            if(root->left==NULL && root->right==NULL){
                delete root;
                return NULL;
            }

            //case2:1 child
            if(root->left==NULL || root->right==NULL){
                return root->left==NULL ? root->right:root->left;
            }

            //case3:2 child
            else{
                TreeNode* IS=InorderSuccessor(root->right);
                root->val=IS->val;
                root->right=deleteNode(root->right,IS->val);

                return root;
            }
        }
    }
};