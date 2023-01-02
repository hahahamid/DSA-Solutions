class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = size(nums); 
        
        unordered_set<int> set; 
        for(int i = 0; i<n; i++){
            for(int j = 2; j*j <= nums[i]; j++){
                if(nums[i]%j == 0){
                    set.insert(j); 
                    while(nums[i] % j == 0) {
                        nums[i] /= j; 
                    }
                }
            }
            if(nums[i] > 1){
                set.insert(nums[i]); 
            }
        }
        return set.size(); 
    }
};


  
              // OR




class Solution {
public:
    int distinctPrimeFactors(vector<int>& nums) {
        int n = size(nums); 
        
        unordered_set<int> set; 
        for(auto num : nums){
           int divisor = 2; 
           long long ans(0); 
           while(num > 1){
               if(num%divisor == 0){
                   set.insert(divisor); 
                   num = num/divisor; 
               }
               else divisor++; 
           }
       }
        return set.size(); 
    }
};
