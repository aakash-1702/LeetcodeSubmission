class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n , vector<int>(n , -1));
        return fun(0 , n-1  , piles , dp);        
    }
    private:
    int fun(int left , int right , vector<int> &piles , vector<vector<int>> &dp){
        // basecase would be when left and right have crossed each other
        if(left > right) return 0;
        if(dp[left][right] != -1) return dp[left][right];

        int l = piles[left] - fun(left + 1 , right , piles ,dp);
        int r = piles[right] - fun(left , right - 1 , piles , dp);

        return dp[left][right] = max(l , r);
    }
};