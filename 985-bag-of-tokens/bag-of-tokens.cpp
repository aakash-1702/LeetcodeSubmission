class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int power) {
        sort(begin(tokens),end(tokens));

        int maxi = 0;
        int cur = 0;
        int n = tokens.size();
        int i = 0 , j = n-1;
        while(i <= j){
            if(tokens[i] > power){
                if(cur >= 1){
                    power += tokens[j];
                    j -= 1;
                    cur -=1;
                    
                }
                else {
                    break;                  

                }
            }else {
                power -= tokens[i];
                i += 1;
                cur += 1;
            }

            maxi = max(maxi , cur);
        }

        return maxi;

        



    }
};