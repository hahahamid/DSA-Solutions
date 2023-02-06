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

    void f(TreeNode* root, int sum, int targetSum, bool &ans){
        if(root == nullptr) return ; 
        sum += root->val; 
        if(root->left == nullptr and root->right == nullptr){
            if(sum == targetSum) ans = 1; 
        }
        f(root->left, sum, targetSum, ans); 
        f(root->right, sum, targetSum, ans); 
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        bool ans = 0; 
        f(root, 0, targetSum, ans); 
        return ans ;    
    }
};
