// pretty similar to the LIS problem only but all you have to keep an eye on is that we are dealing with subsets and not subsequences 
// which is that we can pick from anywhere in the given array of strings. In order to make it simpler to deal with you can sort the array with respect to the size of the elements in the same. 
// Now check the string which you are picking has 1 character added to it to what it was prior to it. 
// Write a bool function for the same and keep pointers in order to compare it and return the length of the lonegst chain. 



class Solution {
public:

    bool check(string &s1, string &s2){
        if(s1.size() != s2.size()+1) return 0; 

        int first = 0; int second = 0; 
        while(first < s1.size()){
            if(s1[first] == s2[second]){
                first++; 
                second++; 
            }
            else first++; 
        }
        if(first == s1.size() and second == s2.size()) return 1; 
        return 0; 
    }

    static bool comp(string &s1, string &s2){
        return s1.size() < s2.size(); 
    }


    int longestStrChain(vector<string>& words) {
        int n = words.size(); 
        
        sort(words.begin(), words.end(), comp); 
        vector<int>dp(n, 1);
        int maxi = 1; 
        for(int i = 0; i<n; i++){
            for(int j = 0; j<i; j++){
                if(check(words[i], words[j]) and 1+dp[j] > dp[i]){
                    dp[i] = 1 + dp[j]; 
                }
            }
            maxi = max(maxi, dp[i]); 
        } 
        return maxi; 
    }
};
