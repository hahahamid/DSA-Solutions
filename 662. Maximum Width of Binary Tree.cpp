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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == nullptr) return 0; 
        long long int ans = 0; 
        queue<pair<TreeNode*, int>>Q; 
        Q.push({root, 0});
        while(!Q.empty()){
            long long int size = Q.size(); 
            long long int mini = Q.front().second;
            long long int first, last; 
            for(int i = 0; i<size; i++){
                long long int currIdx = Q.front().second - mini; 
                TreeNode* node = Q.front().first; 
                Q.pop(); 
                if(i == 0) first = currIdx; 
                if(i == size-1) last = currIdx; 
                if(node->left){
                    Q.push({node->left, currIdx*2 + 1}); 
                }
                if(node->right){
                    Q.push({node->right, currIdx*2 + 2}); 
                } 
            } 
            ans = max(ans, last - first + 1);
        }
        return ans; 
    }
};
