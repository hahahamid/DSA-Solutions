// Good shit. 
// random_shuffle and shuffle are C++ STL functions. read about them. 


class Solution {
public:
vector<int> ans; 
int n; 
    Solution(vector<int>& nums) {
       ans = nums; 
       n = ans.size();  
    }
    
    vector<int> reset() {
        return ans; 
    }
    
    vector<int> shuffle() {
        vector<int> shuffled = ans; 
        int leftSize = n;
        for(int i = n-1; i>=0; i--){
            int j = rand() % leftSize; 
            swap(shuffled[i], shuffled[j]); 
            leftSize--; 
        }
        return shuffled; 
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(nums);
 * vector<int> param_1 = obj->reset();
 * vector<int> param_2 = obj->shuffle();
 */
