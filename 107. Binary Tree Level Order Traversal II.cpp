// very clear and crisp observation ka game hai sirf!! mazeyyy me traverse kro end me reverse krdo 
// kabhi kabhi you are supposed to figure out your shit by looking at the sample test cases only!! 
// CP kri hoti to andaaza hota lekin tune ko kari nhi hogi 



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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans; 

        if(!root) return ans; 

        queue<TreeNode*> Q; 
        Q.push(root); 

        while(!Q.empty()){
            int size = Q.size(); 
            vector<int> thisLevel; 

            for(int i = 0; i<size; i++){
                TreeNode* node = Q.front(); 
                Q.pop(); 

                if(node->left) Q.push(node->left); 
                if(node->right) Q.push(node->right);
                thisLevel.push_back(node->val);  
            }
            ans.push_back(thisLevel); 
        }
        reverse(ans.begin(), ans.end()); 
        return ans; 
    }
};
