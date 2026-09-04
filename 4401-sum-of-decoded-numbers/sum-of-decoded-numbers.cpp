class Solution {
public:
int  M = (int) 1e9+7;
    int sumDecoded(vector<long long>& nums) {

        int sum = 0;

        for(auto &x : nums){
            sum = (sum % M + fun(x) % M ) % M;
        }

        return sum;
    }
    private:
    long long fun(long long n){
        long long w = n % 10;
        long long d = n / 10;
        vector<long long> digits;
        while(d){
            digits.push_back(d % 10);
            d /= 10;
        }

        reverse(digits.begin(),digits.end());

        long long x = 0;
        for(long long i = 0 ; i < w ; i++){
            x = x * 10 + digits[i];
        }

        long long y = 0;
        for(long long i = w ; i < digits.size() ; i++){
            y = y * 10 + digits[i];
        }

        return (long long) power(x , y);

    }
    long long power(long long x, long long y) {
    long long ans = 1;

    x %= M;

    while (y > 0) {
        if (y & 1) {
            ans = (ans * x) % M;
        }

        x = (x * x) % M;
        y /= 2;
    }

    return ans;
}

};