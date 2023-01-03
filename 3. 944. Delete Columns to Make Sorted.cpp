// The intuition was to compare column elements whether they are sorted or not 
// The idea was to run two loops and traverse through the columns and compare strs[i][j] with strs[i+1][j]   
// If strs[i][j] > strs[i+1][j] increment the count and break the loop and check next column 


class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        int n = strs.size();
        int m = strs[0].size(); 

        int cnt(0); 
        
        for(int j = 0; j<m; j++){
            for(int i = 0; i<n-1; i++){
                if(strs[i][j] > strs[i+1][j])
                {
                cnt++; 
                break; 
                }
            }
        }
        return cnt ; 
    }
};
