class Solution {
public:
    set<string> s;
    bool checkConcatenate(string word) {
        for(int i = 1; i < word.length(); i++) {
            string prefixWord = word.substr(0, i);
            string suffixWord = word.substr(i, word.length()-i);
            if(s.find(prefixWord) != s.end() && (s.find(suffixWord) != s.end() || checkConcatenate(suffixWord)))
                return true;
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        vector<string> concatenateWords;
        for(string word : words)
            s.insert(word);
        for(string word : words) {
            if(checkConcatenate(word) == true)
                concatenateWords.push_back(word);
        }
        return concatenateWords;
    }
};



                      // OR




class Solution {
public:
    map<string,int> m;
    bool cal(string &str,int idx,int cnt)
    {
        if(idx==str.size())
            return cnt>1;  
        string tmp="";
        for(int i=idx;i<str.size();i++)
        {
            tmp+=str[i];
            if(m.find(tmp)!=m.end())
            {
                bool flag=cal(str,i+1,cnt+1);
                if(flag)
                    return true;
            }
        }
        return false;
    }
    vector<string> findAllConcatenatedWordsInADict(vector<string>& words) {
        for(auto x:words)
            m[x]++;
        vector<string> ans;
        for(auto x:words)
        {
            bool flag=cal(x,0,0);
            if(flag)
                ans.push_back(x);
        }
        return ans;
    }
};
