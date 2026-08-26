class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {

        string ans = "";
        int len = INT_MAX;
        int n = s.size();
        for(int i = 0 ;i < n ; i++){
            string t = "";
            int cnt = 0;
            for(int j = i ; j < n ; j++){
                t += s[j];
                if(s[j] == '1') cnt += 1;
                if(cnt == k){
                    validate(ans , len , t);
                    break; 
                }
                                               
            }
        }


        return ans;
        
    }
    private:
    void validate(string &ans , int &len , string t){
        
        if(len == INT_MAX || t.size() < len){
            ans = t;
            len = t.size();
            return;
        }

        if(t.size() > len) return;

        ans  = min(ans , t);
        len = ans.size();

        return;
    }
};

