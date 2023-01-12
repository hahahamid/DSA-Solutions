          // RECURSION APPROCH (MEMO)


class Solution {
public:

    int f(int idx, int buy, vector<int>& prices, vector<vector<int>>&dp){
        if(idx == prices.size()) return 0; 

        if(dp[idx][buy] != -1) return dp[idx][buy];  

        int profit = 0; 
        if(buy == 1){
            profit = max(-prices[idx] + f(idx+1, 0, prices, dp), 
                        0 + f(idx+1, 1, prices, dp)); 
        }
        else{
            profit = max(prices[idx] + f(idx+1, 1, prices, dp), 0 + f(idx+1, 0, prices, dp)); 
        }
        return dp[idx][buy] = profit; 
    }

    int maxProfit(vector<int>& prices) {
        int n = prices.size();  
        vector<vector<int>> dp(n, vector<int>(2, -1)); 
        return f(0, 1, prices, dp); 
    }
};



          // TABULATION APPROACH 



class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();  
        vector<vector<int>> dp(n+1, vector<int>(2, 0)); 

        dp[n][0] = dp[n][1] = 0; 
        
        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0; 
                if(buy == 1){
                    profit = max(-prices[i] + dp[i+1][0], dp[i+1][1]); 
                }
                else{
                    profit = max(prices[i] + dp[i+1][1], dp[i+1][0]);
                }
                dp[i][buy] = profit; 
            }
        }
        return dp[0][1]; 
    }
};



          // TWO 1D ARRAYS SPACE OPTIMIZED APPROACH 




class Solution {
public:

    int maxProfit(vector<int>& prices) {
        int n = prices.size();  
        vector<int>ahead(2, 0), curr(2,0);  

        ahead[0] = ahead[1] = 0; 
        
        for(int i = n-1; i>=0; i--){
            for(int buy = 0; buy<=1; buy++){
                int profit = 0; 
                if(buy == 1){
                    profit = max(-prices[i] + ahead[0], ahead[1]); 
                }
                else{
                    profit = max(prices[i] + ahead[1], ahead[0]);
                }
                curr[buy] = profit; 
            }
            ahead = curr; 
        }
        return ahead[1]; 
    }
};



          // FOUR VARIABLES SPACE OPTIMIZATION 




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(); 
        int aheadNotBuy, aheadBuy, currNotBuy, currBuy; 
        aheadNotBuy = aheadBuy = 0; 

        for(int i = n-1; i>= 0; i--){
            currBuy = max(-prices[i] + aheadNotBuy, aheadBuy); 
            currNotBuy = max(prices[i] + aheadBuy, aheadNotBuy); 
            aheadBuy = currBuy; 
            aheadNotBuy = currNotBuy;
        }
        return aheadBuy; 
    }
};




          // GOD APPROACH LMAO 




class Solution {
public:
    int maxProfit(vector<int>& prices) {
        if(prices.size() <= 1) return 0; 
        int profit(0);
        for(int i = 1; i<prices.size(); i++){
            profit += max(0, prices[i] - prices[i-1]); 
        } 
        return profit; 
    }
};


