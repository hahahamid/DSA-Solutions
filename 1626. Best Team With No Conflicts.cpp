// recursive / memoized lol


class Solution {
public:

    int solve(int curr_idx,int prev_idx,vector<pair<int,int>> &ageScore,vector<vector<int>> &dp)
    {
        if(curr_idx >= ageScore.size()) return 0;
        
        if(dp[curr_idx][prev_idx+1]!=-1) return dp[curr_idx][prev_idx+1];

        int pick = 0;
        int not_pick = 0;
        if(prev_idx == -1 || ageScore[curr_idx].second >= ageScore[prev_idx].second)
        {
            pick = ageScore[curr_idx].second + solve(curr_idx+1,curr_idx,ageScore,dp);
        }

        not_pick = 0 + solve(curr_idx+1,prev_idx,ageScore,dp);

        return dp[curr_idx][prev_idx+1] = max(pick,not_pick);                 
    }
    int bestTeamScore(vector<int>& scores, vector<int>& ages) 
    {
        int n = scores.size();
        vector<pair<int,int>> ageScore;
        for(int i=0;i<n;i++)
        {
            ageScore.push_back({ages[i],scores[i]});
        }

        sort(ageScore.begin(),ageScore.end());
        vector<vector<int>> dp(n,vector<int> (n,-1));
        return solve(0,-1,ageScore,dp);
    }
};


          // DP lol 



class Solution {
public:
    int bestTeamScore(vector<int>& scores, vector<int>& ages) {
        int n = scores.size();
        int dp[n], ans = 0;
        vector<pair<int, int>> players;
        for(int i = 0; i < n; i++) 
            players.push_back({ages[i], scores[i]});
        sort(players.begin(), players.end());
        for(int i = 0; i < n; i++) {
            dp[i] = players[i].second;
            for(int j = 0; j < i; j++) {
                if(players[j].second <= players[i].second)
                    dp[i] = max(dp[i], dp[j] + players[i].second);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
