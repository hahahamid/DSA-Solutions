//  WHY DO I EVEN DO CONTEST PROBLEMS TF

class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int neg(0), pos(0); 
        for(auto x : nums){
            if(x<0) neg++; 
            if(x>0) pos++; 
        }

        return max(pos,neg); 
    }
};
