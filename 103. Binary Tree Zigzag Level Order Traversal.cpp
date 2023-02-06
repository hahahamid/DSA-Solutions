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
        if(root == nullptr){
            return ans; 
        }
        queue<TreeNode*> Q;
        Q.push(root); 
        bool LtoR = 1; 

        while(!Q.empty()){
            int size = Q.size(); 
            vector<int> rows(size); 
            for(int i = 0; i<size; i++){
                TreeNode* node = Q.front(); 
                Q.pop(); 
                int index = (LtoR) ? i : (size-1-i); 
                rows[index] = node->val; 
                if(node->left){
                    Q.push(node->left); 
                }
                if(node->right){
                    Q.push(node->right);
                }
            }
            LtoR = !LtoR; 
            ans.push_back(rows); 
        }
        return ans; 
    }
};






class Solution {
public:

    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
       vector<vector<int>> res;
        if (root == nullptr) { return res; }
        
        queue<TreeNode*> treeQueue;
        treeQueue.push(root);
        
        int flipFlag = false;
        while(!treeQueue.empty()) {
            int currLevelNodes = treeQueue.size();
            
            vector<int> levelNodes;
            for (int i = 0; i < currLevelNodes; i++) {
                TreeNode* node = treeQueue.front();
                treeQueue.pop();
                
                if (flipFlag) {
                    levelNodes.insert(levelNodes.begin()+0, node->val);
                } else {
                    levelNodes.push_back(node->val);
                }
                
                if (node->left) { treeQueue.push(node->left); }
                if (node->right) { treeQueue.push(node->right); }
            }
            
            res.push_back(levelNodes);
            flipFlag = !flipFlag;
        }
        
        return res;
    }
};
