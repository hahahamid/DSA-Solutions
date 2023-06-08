// Imstead of altering the index while pushing back the elements of the Queue, 
// just maintain a boolean which will tell whether we are going from left to right, or right to left. 

// In this code, 0 (false) means we are going L to R , and 1 means we are going R to L. 
// we are gonna invert it after every iteration and if we are going R to L, we will first reverse the elements stored in the storing vector, 
// and then push it back to the answer DS. 


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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>ans; 

        if(!root) return ans; 

        queue<TreeNode*> Q; 
        Q.push(root); 
        bool flag = 0; 
        while(!Q.empty()){
            int size = Q.size(); 
            vector<int>thisLevel; 
            for(int i = 0; i<size; i++){
                TreeNode* node = Q.front(); Q.pop(); 

                if(node->left) Q.push(node->left); 
                if(node->right) Q.push(node->right); 
                thisLevel.push_back(node->val); 
            }

            if(flag){
                reverse(thisLevel.begin(), thisLevel.end()); 
            } 
            flag = !flag; 

            ans.push_back(thisLevel); 

        }
        return ans; 
    }
};
