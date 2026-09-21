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
    void inorder(TreeNode* root,vector<int> &nums){
        if(root==NULL){
            return;
        }

        inorder(root->left,nums);
        nums.push_back(root->val);
        inorder(root->right,nums);
    }
    vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
        vector<int> ans;
        vector<int> nums1;
        inorder(root1,nums1);

        vector<int> nums2;
        inorder(root2,nums2);

        int n1=nums1.size();
        int n2=nums2.size();
        int i=0,j=0;

        while(i<n1 && j<n2){
            if(nums1[i]<nums2[j]){
                ans.push_back(nums1[i]);
                i++;
            }
            else{
                ans.push_back(nums2[j]);
                j++;
            }
        }

        while(i<n1){
            ans.push_back(nums1[i]);
            i++;
        }

        while(j<n2){
            ans.push_back(nums2[j]);
            j++;
        }

        return ans;
    }
};