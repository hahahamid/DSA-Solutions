// I FEAR NO BINARY TREE TRAVERSALS BUT LEVEL ORDER! TO THIS DAY!! TO THIS DAYYYY !!!!


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
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>ans; 
        if(root == nullptr) return ans; 

        queue<TreeNode*> Q;
        Q.push(root); 
        while(!Q.empty()){
            int size = Q.size(); 
            vector<int> level;
            for(int i = 0; i<size; i++){
                TreeNode* node = Q.front(); 
                Q.pop(); 
                if(node->left != nullptr) Q.push(node->left); 
                if(node->right != nullptr) Q.push(node->right);
                level.push_back(node->val);  
            }
            ans.push_back(level); 
        } 
        return ans; 
    }
};
