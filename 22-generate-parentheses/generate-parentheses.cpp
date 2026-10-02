class Solution {
vector<string> ans;
 
public:
    vector<string> generateParenthesis(int n) {
        string  a = "";
        f(n , 0 , 0 , a);
        return ans;
    }
    private:
    void f(int n , int op , int cl, string &a){
        if(op == n && cl == n){
            ans.push_back(a);
            return;
        }

        if(op > n || cl > n || cl > op){
            return;
        }

        a.push_back('(');
        f(n , op + 1 , cl , a);
        a.pop_back();
        a.push_back(')');
        f(n , op  , cl + 1 , a);
        a.pop_back();
        return;
    }
};