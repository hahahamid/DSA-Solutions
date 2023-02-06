              // recursive lol 

class Solution {
public:
    int f(int n , vector<int>&dp){
        if(n == 0) return 0; 
        if(n==1 or n==2) return 1; 
        if(dp[n] != -1) return dp[n]; 

        return dp[n] = f(n-1, dp) + f(n-2, dp) + f(n-3, dp) ; 
    }

    int tribonacci(int n) {
        vector<int>dp(n+1, -1); 
        return f(n, dp);     
    }
};



            // DP lol



class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;
            
        vector<int>dp(n+1, 0);
        dp[1] = dp[2] = 1; 
        
        for(int i = 3; i<n+1; i++){
            dp[i] = dp[i-1] + dp[i-2] + dp[i-3]; 
        }    
        return dp[n]; 
    }
};





// Space Optimized lol 

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0)
            return 0;
        if(n == 1 || n == 2)
            return 1;

       int t1=1,t2=1,t0=0,t3;
        for(int i=3;i<=n;i++){
            t3=(t0+t2+t1);
            t0=t1;
            t1=t2;
            t2=t3;
        }
        return t3;
    }
};
