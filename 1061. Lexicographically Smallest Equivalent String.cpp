// The approach wasnt that much of rocket science but it is honest work 
// Make a character array of 26 characters.
// Initialize all the columns with the same character. i.e. index 0 representing a, 1 representing b and so on...
// Since same index characters of s1 and s2 are equal so we'll find smaller and bigger characters between two same indexed characters of s1 & s2 named as replace and put respectively.
// So wherever we'll find replace(bigger) character in map array we'll replace it with the value of put(smaller) character in map array.
// Now our map consist of lexicographically smallest equivalent character of each index.
// Traverse the baseStr and replace all the characters with it's smallest equivalent.
// can be done using map data structure as well but ehh this is easy 



              // Array Implementation Approach (Basically without using union find, and using replace and put instead) 



class Solution {
public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        char arr[26]; 
        for(int i = 0; i<26; i++){
            arr[i] = 'a' + i; 
        }

        for(int i = 0; i<s1.size(); i++){
            char toReplace = max(arr[s1[i] - 'a'], arr[s2[i] - 'a']); 
            char replaceWith = min(arr[s1[i] - 'a'], arr[s2[i] - 'a']); 

            for(int i = 0; i<26; i++){
                if(arr[i] == toReplace){
                    arr[i] = replaceWith; 
                }
            }
        }

        for(int i = 0; i<baseStr.size(); i++){
            baseStr[i] = arr[baseStr[i] - 'a']; 
        }
        return baseStr; 
    }
};




                        // Union Find Approach 



class Solution {
public:
    char parent[26]; 

    char find(char ch){
        if(parent[ch-'a'] == ch){
            return ch; 
        }
        return parent[ch-'a'] = find(parent[ch-'a']); 
    }

    void unionFind(char first, char second){
        char parentOfFirst = find(first); 
        char parentOfSecond = find(second); 

        if(parentOfFirst < parentOfSecond){
            parent[parentOfSecond - 'a'] = parentOfFirst; 
        }
        else parent[parentOfFirst - 'a'] = parentOfSecond; 
    }

    string smallestEquivalentString(string s1, string s2, string baseStr) {
        int n = s1.size(); 
        for(char c = 'a'; c <='z'; c++){
            parent[c-'a'] = c; 
        }

        for(int i = 0; i<n; i++){
            unionFind(s1[i], s2[i]); 
        }

        for(int i = 0; i<baseStr.size(); i++){
            baseStr[i] = find(baseStr[i]); 
        }
        return baseStr; 
    }
};
