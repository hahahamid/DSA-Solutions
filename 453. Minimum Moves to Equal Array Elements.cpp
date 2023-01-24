//  WHY THE FUCK AM I EVEN DOING THIS PROBLEM ;-;


class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum = accumulate(nums.begin(), nums.end(), 0); 
        int mini = *min_element(nums.begin(), nums.end()); 

        return sum - mini*nums.size(); 
    }
};
