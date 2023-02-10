// THIS ONE TAKES O(n) TIME SO DON'T USE IT IF THAT IS MENTIONED IN THE PROBLEM (which is mentioned in this particular problem but not GFG) 

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
    int cnt = 0; 
    void f(TreeNode* root){
        if(root == nullptr) return ; 
        cnt++; 
        f(root->left); 
        f(root->right); 
    }
    int countNodes(TreeNode* root) {
        f(root); 
        return cnt; 
    }
};


// O(logn ^ 2) solution 


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

    int leftHeight(TreeNode* node){
        int cnt = 0; 
        while(node){
            cnt++; 
            node = node->left; 
        }
        return cnt; 
    }
    
    int rightHeight(TreeNode* node){
        int cnt(0); 
        while(node){
            cnt++; 
            node = node->right; 
        }
        return cnt; 
    } 

    int countNodes(TreeNode* root) {
        if(root == nullptr) return 0;

        int lh = leftHeight(root); 
        int rh = rightHeight(root); 

        if(lh == rh) return (1 << rh)  - 1;       // one can use pow(2, lh) as well but I do CP hehe 

        return 1 + countNodes(root->left) + countNodes(root->right); 
    }
};


