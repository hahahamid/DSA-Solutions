/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        if(!root) return ""; 

        string str = ""; 

        queue<TreeNode*> Q; 
        Q.push(root); 

        while(!Q.empty()){
            TreeNode* curr = Q.front(); Q.pop(); 

            if(!curr) str.append("#,"); 
            else str.append(to_string(curr->val) + ','); 

            if(curr){
                Q.push(curr->left); 
                Q.push(curr->right); 
            }
        }
        return str; 
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(data.size() == 0) return NULL; 

        stringstream s(data); 
        string str; 
        getline(s, str, ','); 

        TreeNode* root = new TreeNode(stoi(str)); 

        queue<TreeNode*> Q; 
        Q.push(root); 
        while(!Q.empty()){
            TreeNode* node = Q.front(); Q.pop(); 

            getline(s, str, ','); 
            if(str == "#"){
                node->left = NULL; 
            }
            else{
                TreeNode* leftNode = new TreeNode(stoi(str)); 
                node->left = leftNode; 
                Q.push(leftNode); 
            }

            getline(s, str, ','); 
            if(str == "#"){
                node->right = NULL; 
            }
            else{
                TreeNode* rightNode = new TreeNode(stoi(str)); 
                node->right = rightNode; 
                Q.push(rightNode); 
            }
        }    

        return root; 
    }
};

// Your Codec object will be instantiated and called as such:
// Codec ser, deser;
// TreeNode* ans = deser.deserialize(ser.serialize(root));
