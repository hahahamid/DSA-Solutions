class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        set<int> set1; 
        for(auto x : nums1){
            set1.insert(x); 
        }
        set<int> set2;
        for(auto x : nums2){
            set2.insert(x); 
        }

        map<int, int> mp; 
        for(auto x : set1){
            mp[x]++; 
        }
        for(auto x : set2){
            mp[x]++; 
        }
        
        for(auto it : mp){
            if(it.second > 1) return it.first; 
        }
        return -1; 
    }
};



  
                  //OR




class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {

        map<int, int> mp; 
        for(auto x : nums1){
            mp[x]++; 
        }        
        
        for(auto it : nums2){
            if(mp.find(it) != mp.end()) return it; 
        }

        return -1; 
    }
};


  
                  // OR




class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size(); 
        int i = 0, j = 0;

        while(i!= n and j != m){
            if(nums1[i] == nums2[j]){
                return nums1[i]; 
            }
            else if(nums2[j] > nums1[i]){
                i++; 
            }
            else j++; 
        }
        return -1; 
    }
};
