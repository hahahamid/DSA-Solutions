// RECURSIVE APPROACH (MEMOIZATION)

class Solution {
public:
    int f(int idx, int buy, int cap, vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(idx == prices.size()) return 0; 
        if(cap == 0) return 0; 

        if(dp[idx][buy][cap] != -1) return dp[idx][buy][cap]; 

        int profit(0); 
        if(buy){
            profit = max(-prices[idx] + f(idx+1, 0, cap, prices, dp), f(idx+1, 1, cap, prices, dp)); 
        }
        else{
            profit = max(prices[idx] + f(idx+1, 1, cap-1, prices, dp), f(idx+1, 0, cap, prices, dp)); 
        }
        return dp[idx][buy][cap] = profit; 
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<vector<int>>>dp(n, vector<vector<int>>(2, vector<int>(3, -1))); 
        return f(0, 1, 2, prices, dp); 
    }
};



// TABULATION APPROACH 



class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0))); 
        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                for(int cap = 1; cap <=2; cap++){
                    int profit(0);
                    if(buy == 1) {
                        profit = max(-prices[i] + dp[i+1][0][cap], dp[i+1][1][cap]); 
                    }
                    else{
                        profit = max(prices[i] + dp[i+1][1][cap-1], dp[i+1][0][cap]); 
                    }
                        
                        dp[i][buy][cap] = profit; 
                }
            }
        }
        return dp[0][1][2]; 

    }
};
