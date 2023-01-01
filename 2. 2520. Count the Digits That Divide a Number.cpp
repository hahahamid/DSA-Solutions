class Solution {
public:
    int countDigits(int num) {
        vector<int> v; 
        int n = num; 
        while(n > 0)
            {v.push_back(n%10); 
            n = n/10; }

        
        int cnt(0); 
        for(int i = 0; i<v.size(); i++){
            if(num%v[i] == 0) cnt++; 
        }
        return cnt; 
    }
};


            // OR



class Solution {
public:
    int countDigits(int num) {
       int cnt(0); 
       int n = num; 
       while(n){
           if(num % (n%10) == 0) cnt++; 
           n = n/10; 
       }
       return cnt; 
    }
};




