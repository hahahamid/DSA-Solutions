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
    bool f(TreeNode* Node1, TreeNode* Node2){
        if(Node1 == nullptr or Node2 == nullptr){
            return Node1 == Node2;
        }
        if(Node1->val != Node2->val) return 0; 

        return f(Node1->left, Node2->right) and f(Node1->right, Node2->left); 
    }

    bool isSymmetric(TreeNode* root) {
        return root == nullptr or f(root->left, root->right); 
    }
};









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
    bool f(TreeNode* Node1, TreeNode* Node2){
        if(Node1 == nullptr || Node2 == nullptr){
            return (Node1 == Node2);
        }
        if(Node1->val != Node2->val) return 0; 

        return f(Node1->left, Node2->right) && f(Node1->right, Node2->left); 
    }

    bool isSymmetric(TreeNode* root) {
        return root == nullptr || f(root->left, root->right); 
    }
};
