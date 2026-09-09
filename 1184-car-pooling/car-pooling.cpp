class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        map<int,int> mp;
        for(auto &x : trips) {
            int p = x[0];
            int f = x[1];
            int t = x[2];
            mp[f] += p;
            mp[t] -= p;
        }     

        int cur = 0;
        for(auto &x : mp){
            cur += x.second;
            if(cur > capacity) return false;
        }

        return true;
    }
};