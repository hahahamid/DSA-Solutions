class Solution {
public:
    int minimumSum(int n, int k) {
        vector<int> v; 
        
        set<int> set; 
        
        v.push_back(1); 
        set.insert(1); 
        
        for(int i = 2; i<=9999; i++){
            if(v.size() < n){
                if(set.find(k - i) != set.end()) continue; 
                else{
                    v.push_back(i); 
                    set.insert(i); 
                }
            }
        }
        
        int sum(0); 
        for(auto it : v){
            sum += it; 
        }
        
        return sum; 
    }
};
