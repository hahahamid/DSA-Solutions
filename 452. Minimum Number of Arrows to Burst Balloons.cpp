// The approach was to implement greedy technique 
// An arrow shoots through multiple intervals, all of which are coincident.
// We try to stack the overlapping intervals together and give a jump.


class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end()); 
        int lastPoint = points[0][1]; 
        int ans(1); 
        for(auto point : points){
            if(point[0] > lastPoint){
                ans++; 
                lastPoint = point[1]; 
            }
            lastPoint = min(lastPoint, point[1]); 
        }
        return ans; 
    }
};
