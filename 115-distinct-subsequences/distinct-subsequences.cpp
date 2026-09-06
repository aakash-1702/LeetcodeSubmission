class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<vector<int>> dp(n , vector<int>(m , -1));


        return fun(0 , 0 , s , t , dp);
        
    }
    private:
    int fun(int i , int j , string &s , string &t , vector<vector<int>> &dp){
        int n = s.size();
        int m = t.size();
        if(j >= m ) return 1;
        if(i >= n) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int ans = 0;
        if(s[i] == t[j]){
            int take = fun(i + 1 , j + 1, s , t , dp);
            int nottake = fun(i + 1 , j , s , t , dp);
            ans = take + nottake;
        }else {
            int nottake = fun(i + 1 , j , s , t , dp);
            ans = nottake;
        }

        return dp[i][j] = ans;
    }
};