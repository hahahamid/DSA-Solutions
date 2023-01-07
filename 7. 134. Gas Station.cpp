//   The appraoch was pretty basic greedy technique. Clearly, one of THE problems on LC. 
//   The very thing you have to keep an eye on is that you have gas to complete the full cicruit. 
//   This means one has to check the sum of gases we have is at least eqyual to or greater than the sum of costs. 
    
//   If it is so, we'll look out for a starting point wherein the (gas[i] - cost[i] > 0), and iterate from that point only. 
//   If only we have the same condition for all the further stations, we'll return the starting point, else we'll update the starting point. 


class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasS, costS; 

        gasS = accumulate(gas.begin(), gas.end(), 0); 
        costS = accumulate(cost.begin(), cost.end(), 0);

        if(gasS < costS){
            return -1; 
        }
        int start(0);
        int ans(0); 
        for(int i = 0; i<gas.size(); i++){
            ans += gas[i] - cost[i];
            if(ans < 0){
                start = i+1;
                ans = 0; 
            }
        } 
        return start ;
    }
};



//  OR I'D SAY BETTER USE THE TYPICAL FOR LOOPS TO CALCULATE SUM. ACCUMULATE() TAKES MORE TIME I GUESS. 
//  and use FAST I/O lol. this beats 99%

class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        
        int gasS = 0;
        int costS = 0; 

       for(int i = 0; i<gas.size(); i++){
           gasS += gas[i];
           costS += cost[i]; 
       }

        if(gasS < costS){
            return -1; 
        }
        int start(0);
        int ans(0); 
        for(int i = 0; i<gas.size(); i++){
            ans += gas[i] - cost[i];
            if(ans < 0){
                start = i+1;
                ans = 0; 
            }
        } 
        return start ;
    }
};
