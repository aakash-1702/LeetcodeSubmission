class Solution {
public:
    bool repeatedSubstringPattern(string s) {
        string a = "";
        for(auto &x : s){
            a += x;
            if(a.size() == s.size()) return false;
            if((s.size() % a.size()) == 0  && isPossible(a , s)) return true;
        }        

        return false;
    }
    private:
    bool isPossible(string &a , string &b){
        int t = b.size() / a.size();
        string c = "";
        for(int i = 0 ;i < t ; i++){
            c += a;
        }

        return b == c;
    }
};