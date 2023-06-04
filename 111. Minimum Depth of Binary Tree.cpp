// Good Soup but all you were supposed to do was to keep an eye on the edge cases and it'll be all it !! 


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
        if(!root) return 0; 

        int lh = height(root->left); 
        int rh = height(root->right); 

        if(lh == 0 or rh == 0) return lh + rh + 1;
        if(lh >= rh) return rh + 1; 
        else return lh + 1;
  
    }

    int minDepth(TreeNode* root) {
        return height(root); 
    }
};
