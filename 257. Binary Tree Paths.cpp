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

    void f(TreeNode* root, vector<string>&ans, string curr){
        if(root == nullptr) return ; 

        if(root->left == nullptr and root->right == nullptr){
            curr += to_string(root->val); 
            ans.push_back(curr); 
        }
        else{
            curr += to_string(root->val) + "->" ;
        }
        f(root->left, ans, curr); 
        f(root->right, ans, curr); 
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans; 
        f(root, ans, {}); 
        return ans; 
    }
};
