// Similar appraoch to Coin Change I 
// We need to find the total number of coins, thus we'll return sum of take cases and notTake cases 
// As there is an unlimited supply of coins, we'll use the same index multiple times. 


// RECURSION (MEMOIZATION)


class Solution {
public:

    int f(int idx, int tar, vector<int> &coins, vector<vector<int>>&dp){
        if(idx == 0){
            if(tar % coins[0] == 0) return 1; 
            return 0;
        }

        if(dp[idx][tar] != -1) return dp[idx][tar]; 

        int notTake = f(idx-1, tar, coins,dp); 
        int take = 0; 
        if(coins[idx] <= tar) take = f(idx, tar-coins[idx], coins, dp); 

        return dp[idx][tar] = take + notTake; 
    }

    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>>dp(n, vector<int>(amount+1, -1)); 
        return f(n-1, amount, coins, dp);
    }
};



//TABULATION



class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        vector<vector<int>>dp(n, vector<int>(amount+1, 0)); 

        for(int i = 0; i<=amount; i++){
            if(i % coins[0] == 0) 
                dp[0][i] = 1;
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                int notTake = dp[i-1][j]; 
                int take = 0;
                if(coins[i] <= j) take = dp[i][j-coins[i]]; 

                dp[i][j] = take + notTake; 
            }
        }
        return dp[n-1][amount]; 
    }
};


// TWO 1D ARRAYS SPACE OPTIMIZATION 


class Solution {
public:

    int change(int amount, vector<int>& coins) {
        int n = coins.size(); 
        //vector<vector<int>>dp(n, vector<int>(amount+1, 0)); 
        vector<int>prev(amount+1, 0), curr(amount+1, 0) ; 

        for(int i = 0; i<=amount; i++){
            if(i % coins[0] == 0) 
                prev[i] = 1;
        }
        for(int i = 1; i<n; i++){
            for(int j = 0; j<=amount; j++){
                int notTake = prev[j]; 
                int take = 0;
                if(coins[i] <= j) take = curr[j-coins[i]]; 

                curr[j] = take + notTake; 
            }
            prev = curr; 
        }
        return prev[amount]; 
    }
};
