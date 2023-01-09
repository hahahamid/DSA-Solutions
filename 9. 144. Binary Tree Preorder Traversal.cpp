// what can I say? Preorder traversal only. 
// In the recursion approach make sure to declare answer array globallly, or just create a function sending root and the array doing the same operation. 
// LEARN MORRIS TRAVERSAL APPROACH AND ADD THE CODE ASAP! 


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

                    
                  // RECURSIVE APPROACH


class Solution {
public:
    vector<int> ans; 
    vector<int> preorderTraversal(TreeNode* root) {
        if(root){
            ans.push_back(root->val); 
            preorderTraversal(root->left);
            preorderTraversal(root->right);  
        }
        return ans; 
    }
};




              // ITERATIVE APPROACH (USING STACK)



class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ans;
        stack<TreeNode*> S; 
        while(root or !S.empty()) {
            if(root){
                ans.push_back(root->val); 
                if(root->right){
                    S.push(root->right);
                }
                root = root->left; 
            }
            else{
                root = S.top(); 
                S.pop(); 
            }
        }
        return ans;
    }
};



                  // MORRIS TRAVERSAL APPROACH


