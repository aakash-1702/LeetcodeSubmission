class Solution {
public:
    bool stoneGame(vector<int>& piles) {
        int n = piles.size();
        vector<vector<int>> dp(n + 1 , vector<int>(n + 1 , 0));
        for(int i = 0 ; i < n ; i++){
            for(int j = i + 1; j < n ;j++){
                dp[i][j] = max( piles[i] - dp[i+1][j] , piles[j]  - dp[i][j+1]);
            }
        }
        return dp[0][n-1]; 

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