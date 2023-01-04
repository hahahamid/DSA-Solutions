// I mean its quite visible. what am I suppose to write about the approach lol
// If you are struggling with this one, its time you should brush up you hashmap lessons. 

class Solution {
public:
    int minimumRounds(vector<int>& tasks) {
        map<int, int> mp; 
        for(auto x : tasks){
            mp[x]++; 
        }
        int cnt = 0; 
        for(auto it : mp){
            if(it.second < 2){
                return -1;
            }
            if(it.second%3 == 0){
                cnt += it.second/3;
            }
            else cnt += it.second/3 + 1;
        }
        return cnt; 
    }
};
