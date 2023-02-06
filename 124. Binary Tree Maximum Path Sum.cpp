// GOOD PROBLEM 


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


    int f(TreeNode* root, int & ans){
        if(root == NULL) return 0; 
        int leftSum = max(0, f(root->left, ans)); 
        int rightSum = max(0, f(root->right, ans)) ; 
        int currAns = root->val + leftSum + rightSum; 
        ans = max(ans, currAns); 
        return root->val + max(leftSum, rightSum); 
    }
    int maxPathSum(TreeNode* root) {
        if(root == NULL) return 0; 
        int ans = INT_MIN;
        f(root, ans); 
        return ans ;  

    }
};



                     // OR




class Solution {
public:
    int f(TreeNode* root, int &maxi){
        if(root == nullptr) return 0; 

        int leftSum = max(0, f(root->left, maxi)); 
        int rightSum = max(0, f(root->right, maxi)); 
        maxi =  max(maxi, leftSum + rightSum + root->val); 
        return root->val + max(leftSum, rightSum); 
    }

    int maxPathSum(TreeNode* root) {
        int maxi = -1e9; 
        f(root, maxi); 
        return maxi; 
    }
};
