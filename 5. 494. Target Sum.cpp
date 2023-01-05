// Instead of finding out all possibilities and putting in '+' or '-'  in every cases, 
// you are suppose to boil this problem into partition an array into susbets for required difference


// Use the same appraoch to divide the subsets 



class Solution {
public:

    int f(vector<int> &arr, int target){
    int n = arr.size(); 
    vector<vector<int>>dp(n, vector<int>(target+1, 0));
    if(arr[0] == 0) dp[0][0] = 2; 
    else dp[0][0] = 1; 
    
    
    if(arr[0] != 0 && arr[0] <= target){
        dp[0][arr[0]] = 1; 
    }
    
    for(int i = 1; i<n; i++){
        for(int k = 0; k<=target; k++){
            int nottake = dp[i-1][k]; 
            int take = 0; 
            if(arr[i] <= k) take = dp[i-1][k-arr[i]]; 
            
            dp[i][k] = (take+nottake) ; 
        }
    }
    return dp[n-1][target]; 
}

    int countPartitions(int n, int d, vector<int> &arr) {
    int sum = accumulate(arr.begin(), arr.end(), 0); 
    
    if(sum-d<0 or (sum-d)%2) return 0; 
    return f(arr, (sum-d)/2); 
}


    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size(); 
        return countPartitions(n, target, nums); 
        
    }
};
