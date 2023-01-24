// Basic LIS approach only but all you have to take care of is that whichever element are you picking in 
// your subset it has to be divisible by the one picked prior to it.

// This makes the intuition quite easy that if the i+3th element is divisble by i+2th element, 
// it is quite evident that it is divisble by ith element and all the prior elements as well 

// And in order to do so, we'll make sure to sort the array first and the rest is basics of printing the LIS. 


class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size(); 
        vector<int>dp(n,1); 
        vector<int>hash(n); 
        int maxi = 1; 
        int lastIdx = 0; 
        sort(nums.begin(), nums.end()); 
        for(int i = 0; i<n; i++){
            hash[i] = i; 
            for(int j = 0; j<i; j++){
                if(nums[i] % nums[j] == 0 and 1+dp[j] > dp[i]){
                    dp[i] = 1 + dp[j]; 
                    hash[i] = j; 
                }
            }

            if(dp[i] > maxi){
                maxi = dp[i]; 
                lastIdx = i; 
            }
        }
        vector<int>temp; 
        temp.push_back(nums[lastIdx]); 
        while(hash[lastIdx] != lastIdx){
            lastIdx = hash[lastIdx]; 
            temp.push_back(nums[lastIdx]); 
        }
        reverse(temp.begin(), temp.end()); 
        return temp; 
    }
};
