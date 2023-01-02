// The approach is basically just count the number of Uppercase letter and check for the 3 simple cases
// If the count of uppercase letters is equal to the length, return 1; (USA) 
// If there is only one uppercase letter, check if the very first letter is uppercase and return 1;  (Leetcode) 
// If there are no capital letters, return 1; (hamid) 
// In every other case return false; 



class Solution {
public:
    bool detectCapitalUse(string word) {
        int cnt(0); 
        for(int i = 0; i<word.length(); i++){
            if(word[i] >= 65 and word[i] <=90)
            cnt++; 
        }

        if(cnt == word.length()){
            return 1; 
        }
        else if(cnt == 1 and word[0] >= 65 and word[0]<=90){
            return 1; 
        }
        else if(cnt == 0){
            return 1; 
        }
        else return 0; 
    }
};
