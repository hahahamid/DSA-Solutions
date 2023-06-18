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


    TreeNode* f(vector<int>&post, int postStart, int postEnd, vector<int>&in, int inStart, int inEnd, map<int, int>&mp){

        if(postStart > postEnd or inStart > inEnd) return NULL; 

        TreeNode* root = new TreeNode(post[postEnd]); 

        int inRoot = mp[root->val]; 
        int numsOnLeft = inRoot - inStart; 

        root->left = f(post, postStart, postStart + numsOnLeft - 1, in, inStart, inRoot-1, mp); 

        root->right = f(post, postStart + numsOnLeft, postEnd - 1, in, inRoot + 1, inEnd, mp); 

        return root; 

    }

    TreeNode* buildTree(vector<int>& in, vector<int>& post) {
        int n = post.size(); 
        
        map<int, int>mp; 
        for(int i= 0; i<n; i++){
            mp[in[i]] = i; 
        }

        TreeNode* root = f(post, 0, n-1, in, 0, n-1, mp); 
        return root; 
    }
};
