// easy problem but make sure to keep an eye on volume overflowing the integer range. 
// could have used boolean as well but this slaps. 


class Solution {
public:
    string categorizeBox(int l, int w, int h, int m) {
        long long v = (long long)(l)*(long long)(w)*(long long)(h);
        int ans1 = 0; 
        int ans2 = 0; 
        if(l >= 10000 or w >= 10000 or h >=10000 or m>= 10000){
            ans1 = 1; 
        }
        
        if(v >= 1000000000) ans1 = 1;
        
        if(m >= 100) ans2 = 1; 
        
        
        if(ans1 == 1 and ans2 == 1) {return "Both" ; } 
        if(ans1 != 1 and ans2 != 1) {return "Neither" ;} 
        if(ans1 == 1 and ans2 != 1){return "Bulky" ; }
        if(ans1 != 1 and ans2 == 1){return "Heavy" ; }
        
        return "bulky"; 
    }
};
