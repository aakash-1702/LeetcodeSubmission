class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {

        vector<vector<int>> ans;
        sort(begin(intervals),end(intervals));
        int n = intervals.size();
        ans.push_back(intervals[0]);

        for(int i = 1 ; i < n ;i++){
            int preEnd = ans.back()[1];
            int curStart = intervals[i][0];
            int curEnd = intervals[i][1];

            if(curStart < preEnd){
                if(preEnd <= curEnd) continue;
                ans.pop_back();
                ans.push_back(intervals[i]);
            }else {
                ans.push_back(intervals[i]);
            }
        }


        for(auto &x : ans){
            for(auto &y : x){
                cout << y << " ";
            }

            cout << endl;
        }

        return n - ans.size();
        
    }
};