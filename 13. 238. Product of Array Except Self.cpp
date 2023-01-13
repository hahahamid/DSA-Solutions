// I mean the approach is self-explanatory, look at the code once you'd get to know 
// not using long for the product, cuz this was mentioned in the problem itself that it won't overflow the range of int.  

// Brute Force Approach 

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size(); 
       vector<int> L(n, 1);
       vector<int> R(n, 1);
 
       for(int i = 1; i<n; i++){
           L[i] = L[i-1] * nums[i-1]; 
       }

       for(int i = n-2;i>=0; i--){
           R[i] = R[i+1] * nums[i+1]; 
       }
        
        vector<int>ans(n,1); 

        for(int i = 0; i<n; i++){
            ans[i] = L[i]*R[i]; 
        }
       return ans ;
    }
};



// Sapce Optimized (In-place) as they wanted lol 


class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
       int n = nums.size(); 
       vector<int> ans(n, 1); 
       for(int i = 1; i<n; i++){
           ans[i] = ans[i-1] * nums[i-1]; 
       }

       int prod = nums[n-1]; 
       for(int i = n-2;i>=0; i--){
           ans[i] *= prod; 
           prod*= nums[i]; 
       }
       return ans ;
    }
};
