

class Solution {
public:
    bool wordPattern(string pattern, string s) {
        vector<string> words;
        string temp = "";  
        for(auto x : s){
            if(x == ' '){
                words.push_back(temp); 
                temp = ""; 
            }
            else{
                temp+= x; 
            }
        }
        words.push_back(temp); 

        if(words.size() != pattern.size()) return 0; 

        unordered_map<char, string> mp; 
        set<string> set; 
        for(int i = 0; i<pattern.size(); i++){
            if(mp.find(pattern[i]) != mp.end()){
                if(mp[pattern[i]] != words[i]){
                    return 0; 
                }
            }
            else {
                if(set.count(words[i]) > 0 ){
                    return 0; 
                }
                mp[pattern[i]] = words[i]; 
                set.insert(words[i]); 
            }
        }
        return 1; 
    }
};
