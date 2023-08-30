class Solution {
public:
    int longestEqualSubarray(vector<int>& nums, int k) {
        unordered_map<int, int> mp; 
        int ans = 0; 
        int l = 0, maxi= 0; 
        
        for(int r= 0;  r<nums.size();r++){
            mp[nums[r]]++; 
            
            maxi = max(maxi, mp[nums[r]]); 
            
            while((r - l + 1) - maxi > k){
                mp[nums[l]]--; 
                l++; 
            }
        }
        return maxi; 
    }
};
