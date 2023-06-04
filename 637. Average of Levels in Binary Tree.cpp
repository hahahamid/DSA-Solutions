// A person who thinks all the time doesn't think at all !!! 
// Kabhi kabhi easy problem ko easy problem ki tarah treat krte hai !!
// basic approach bhi lagaya jaa skta hai instead of thinking of the implementing all the DS you know about lol 


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
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double>ans; 
        if(!root) return ans; 

        queue<TreeNode*> Q; 
        Q.push(root); 

        double levelSum = 0;  

        while(!Q.empty()){
            levelSum = 0; 

            int size = Q.size(); 

            for(int i = 0; i<size; i++){
                TreeNode* node = Q.front(); 
                Q.pop(); 

                levelSum += node->val; 

                if(node->left) Q.push(node->left); 
                if(node->right) Q.push(node->right); 
            }

            double average = levelSum / size; 
            ans.push_back(average); 

        }
        return ans; 
    }
};
