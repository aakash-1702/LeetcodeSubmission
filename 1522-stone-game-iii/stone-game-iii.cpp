class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<int> dp(n , -1);
        int ans =  fun(0 , stoneValue , dp);
        
        if(ans  == 0) return "Tie";
        return ans > 0 ? "Alice" : "Bob";
    }
    private:
    int fun(int index , vector<int>  &stoneValue , vector<int> &dp){
        int n = stoneValue.size();
        if(index >= n) return 0;
        int ans = INT_MIN;
        int cur = 0;

        if(dp[index] != -1) return dp[index];

        for(int i = index ; i <= index + 2 && i < n ; i++){
            cur += stoneValue[i];
            ans = max(ans , cur - fun(i + 1 , stoneValue , dp));            
        }


        return  dp[index] = ans;



    }
};