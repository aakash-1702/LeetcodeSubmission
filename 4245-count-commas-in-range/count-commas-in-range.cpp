class Solution {
public:
    int countCommas(int n) {
        int ans = 0;
        int noOfDigits = countDigit(n);
        if(noOfDigits <= 3) return 0;
        if(noOfDigits == 4){
            int m = n   - 999;
            ans += m;        
        }else if(noOfDigits == 5){
            int m = 9999-999;
            ans += m;
            m = n - 9999;
            ans += m;
        }else {
            int m = 9999-999;
            ans += m;
            cout << ans << endl;
            m = n - 9999;
            ans += m;
                      
        }

        return ans;
    }
    private:
    int countDigit(int n){
        int cnt = 0;
        while(n){
            cnt += 1;
            n /= 10;
        }


        return cnt;
    }
};