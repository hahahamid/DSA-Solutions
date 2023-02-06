
              // RECURSIVE APPROACH


class Solution {
public:
    bool isPalindrome(int i, int j, string &s){
        while(i<j){
            if(s[i++] != s[j--]) return 0; 
        } 
        return 1; 
    }

    int f(int i, string &s, vector<int>&dp){
        
        if(i== s.size()) return 0; 

        if(dp[i] != -1) return dp[i]; 

        int minCost = 1e9; 
        for(int j = i; j<s.size(); j++){
            if(isPalindrome(i, j, s)){
                int cost = 1 + f(j+1, s, dp); 
                minCost = min(minCost, cost); 
            }
        }
        return dp[i] = minCost; 
    }


    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return f(0, s, dp) - 1;  
    }
};




// MINOR CHANGE IN RECURSIVE / MEMOIZED 


class Solution {
public:
    bool isPalindrome(string &s){
        int i = 0; int j = s.size() - 1;  
        while(i<j){
            if(s[i++] != s[j--]) return 0; 
        } 
        return 1; 
    }

    int f(int i, string &s, vector<int>&dp){
        
        if(i== s.size()) return 0; 

        if(dp[i] != -1) return dp[i]; 

        int minCost = 1e9; 
        string temp = ""; 
        for(int j = i; j<s.size(); j++){
            temp += s[j]; 
            if(isPalindrome(temp)){
                int cost = 1 + f(j+1, s, dp); 
                minCost = min(minCost, cost); 
            }
        }
        return dp[i] = minCost; 
    }


    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n, -1);
        return f(0, s, dp) - 1;  
    }
};



        // TABULATION APPROACH



class Solution {
public:
    bool isPalindrome(string &s){
        int i = 0; int j = s.size() - 1;  
        while(i<j){
            if(s[i++] != s[j--]) return 0; 
        } 
        return 1; 
    }

    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        for(int i = n-1; i>=0; i--){
            int minCost = 1e9; 
            string temp = ""; 
            for(int j = i; j<n; j++){
                temp += s[j]; 
                if(isPalindrome(temp)){
                    int cost = 1 + dp[j+1]; 
                    minCost = min(minCost, cost); 
                }
            }
            dp[i] = minCost; 
        }
        return dp[0] - 1; 
    }
};



          // MINOR CHANGE IN TABULATION APPROACH 



class Solution {
public:
    bool isPalindrome(int i, int j, string &s){  
        while(i<j){
            if(s[i++] != s[j--]) return 0; 
        } 
        return 1; 
    }

    int minCut(string s) {
        int n = s.size();
        vector<int>dp(n+1, 0);
        for(int i = n-1; i>=0; i--){
            int minCost = 1e9; 
            for(int j = i; j<n; j++){
                if(isPalindrome(i, j, s)){
                    int cost = 1 + dp[j+1]; 
                    minCost = min(minCost, cost); 
                }
            }
            dp[i] = minCost; 
        }
        return dp[0] - 1; 
    }
};
