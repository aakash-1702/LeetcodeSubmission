class Solution {
public:
    int smallestNumber(int n, int t) {
        while(1){
            int m = prod(n);
            if(m % t == 0) return n;
            n += 1;
        }
        return -1;
    }
    private:
    int prod(int n){
        int p = 1;
        while(n){
            p = p * (n % 10);
            n /= 10;
        }

        return p;
    }
};