class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        queue<pair<string, int>> Q; 
        Q.push({beginWord, 1}); 
        unordered_set<string>st(wordList.begin(), wordList.end()); 

        st.erase(beginWord); 

        while(!Q.empty()){
            string word = Q.front().first; 
            int steps = Q.front().second; 
            Q.pop(); 

            if(word == endWord) return steps; 

            for(int i = 0; i<word.size(); i++){
                char originalChar = word[i]; 

                for(char ch = 'a'; ch <= 'z'; ch++){
                    word[i] = ch; 
                    if(st.find(word) != st.end()){
                        st.erase(word); 
                        Q.push({word, steps+1}); 
                    }
                }

                word[i] = originalChar; 
            }
        }

        return 0; 
    }
};
