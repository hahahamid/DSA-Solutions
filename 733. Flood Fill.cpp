class Solution {
private: 
    void dfs(int row, int col, vector<vector<int>>& ans, vector<vector<int>>& image, int color, int iniColor){
        ans[row][col] = color; 
        int n = image.size(); 
        int m = image[0].size();

        int dr[] = {-1, 0, 1, 0}; 
        int dc[] = {0, 1, 0, -1};

        for(int i = 0; i<4; i++){
            int nrow = row + dr[i]; 
            int ncol = col + dc[i]; 

            if(nrow >= 0 and nrow < n and ncol >=0 and ncol < m and image[nrow][ncol] == iniColor and ans[nrow][ncol] != color){
                dfs(nrow, ncol, ans, image, color, iniColor); 
            }
        } 
    }    
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int n = image.size(); 
        int m = image[0].size();

        int iniColor = image[sr][sc]; 
        vector<vector<int>>& ans = image; 


        dfs(sr, sc, ans, image, color, iniColor); 

        return ans; 
    }
};
