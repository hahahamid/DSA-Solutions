// As the problem was to get the sum of two integers without using any arithmetic operators, 
// we will just run a loop and increment integer A till integer B becomes 0 (in case of positive intgers); 
// and in case of negative intgers, we will decrement it till the other number becomes 0 


class Solution {
public:
    int getSum(int a, int b) {
        if(b>0){
            while(b--){
                a++; 
            }
        }
        else {
            while(b++){
                a--; 
            }
        }
        return a; 
    }
};
