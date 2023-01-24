// The approach is pretty simple. All you have to do is check if there exists a subset with the sum equal to half of the sum of all elements in the array
// As the problem asks us to find it is possible to divide the array into two subsets with equal sum, this means that if one of the subsets have the sum S/2, 
// the other clearly have the sum S/2 only. 

// Thus we'll check if there exists a subset with the sum equal to totalSum/2, and return the same. 
  
// One thing to keep an eye on is that if the sum of all the elements in the array is odd, it is impossible to divide the array into two subsets with equal sum.
// In such cases, return 0. 

// This problem is basically an extension to subset sum equal to target problem. If you solve that problem, this is nothing but a cakewalk. 


class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(); 
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        
        if(sum%2) return 0; 
        else {
            int k = sum/2; 
            vector<vector<bool>> dp(n,vector<bool>(k+1, 0)); 
            
            for(int i = 0; i<n; i++){
            dp[i][0] = 1; 
            }
            if(nums[0]<=k)
            dp[0][nums[0]] = 1;     

            for(int i = 1; i<n; i++){
                for(int j = 1; j<=k; j++){
                    bool notTake = dp[i-1][j]; 
                    bool take = false; 
                    if(nums[i] <= j)  take = dp[i-1][j - nums[i]]; 

                    dp[i][j] = take or notTake; 
                }
            }
            return dp[n-1][k]; 
        }
    }
};
