// GOOD SOUP 
// HARD PROBLEM FOR A REASON 

// In case the target node is given instead of the target value, skip that one step and vice versa
// This could either be from leaf node, or any node in the tree, the intuition will be the same only 




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

    int BFS(map<TreeNode*, TreeNode*> &mp, TreeNode* target){
        queue<TreeNode*> Q;
        Q.push(target); 
        map<TreeNode*, int> vis; 
        vis[target] = 1; 
        int maxi = 0; 
        while(!Q.empty()){
            int sz = Q.size(); 
            int fl = 0;       // Just a flag to keep check on whether we are burning anything in the iteration or not 
            for(int i = 0; i<sz; i++){
                TreeNode* node = Q.front(); Q.pop(); 
                if(node->left and !vis[node->left]){
                    fl = 1; 
                    vis[node->left]  = 1; 
                    Q.push(node->left);
                }
                if(node->right and !vis[node->right]){
                    fl = 1; 
                    vis[node->right]  = 1; 
                    Q.push(node->right); 
                }
                if(mp[node] and !vis[mp[node]]){
                    fl = 1; 
                    vis[mp[node]] = 1; 
                    Q.push(mp[node]); 
                }
            }
            if(fl) maxi++;  
        }
        return maxi; 
    }


    TreeNode* BFStoMapParents(TreeNode* root, map<TreeNode*, TreeNode*> &mp, int start){
        queue<TreeNode*> Q; 
        Q.push(root); 
        TreeNode* ans; 
        while(!Q.empty()){
            TreeNode* node = Q.front(); 
            if(node->val == start) ans = node;        // Skip this step if target node is given instead of target value 
            Q.pop(); 
            if(node->left){
                mp[node->left] = node; 
                Q.push(node->left); 
            }
            if(node->right){
                mp[node->right] = node; 
                Q.push(node->right); 
            }
        }
        return ans; 
    }

    int amountOfTime(TreeNode* root, int start) {
        map<TreeNode*, TreeNode*> mp;         // You can declare the map globally as well it will work just fine. 
        TreeNode* target = BFStoMapParents(root, mp, start); 
        int ans = BFS(mp, target); 
        return ans ; 
    }
};
