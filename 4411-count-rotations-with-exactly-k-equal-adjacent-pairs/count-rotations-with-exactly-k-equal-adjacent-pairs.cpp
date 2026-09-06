class Solution {
public:
    int countRotations(string s, int k) {

        int n = s.size();
        int ans = 0;
        for(int i = 0 ; i  < n ; i++){
            string temp = fun(s , i );

            int cnt = balanceCnt(temp);

            if(cnt == k) ans += 1;
        }

        return ans;
        
    }
    private:
    string fun(string s , int i){
        string temp = "";
        for(int j = i + 1 ; j < s.size() ; j++) temp += s[j];

        for(int j = 0 ; j <= i ; j++){
            temp += s[j];
        }

        return temp;
    }
    int balanceCnt(string &temp){
        int n = temp.size();
        int cnt = 0;
        for(int i = 0 ; i < n-1 ; i++){
            if(temp[i] == temp[i+1]) cnt += 1;
        }

        return cnt;
    }

};