// Clearly the very basic greedy approach, sort the prices and buy them ice creams till the point you have no coins left
// I mean if you speak of the approach one might say instead of using the greedy technique you can go with DP 
// but clearly both the approach will take NlogN time, and DP approach will take up O(n) space, while the greedy one will have the SC of O(1). 

// One can use priority queues in order to optimize this solution even further. 


class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end()); 
        
        int cnt(0);         
        for(int i = 0; i<costs.size(); i++){
            if(costs[i] > coins)
                break;
            else{
                coins = coins - costs[i]; 
                cnt++; 
            }
        }
        return cnt; 
    }
};
