class Solution {
set<int> even; 
set<int> odd;
public:
    bool uniformArray(vector<int>& nums1) {
        for(auto &x : nums1){
            if(x & 1) odd.insert(x);
            else even.insert(x);
        }

        if(odd.size() == 0 || even.size() == 0) return true;

        return evenPossible(nums1) || oddPossible(nums1);

    }
    private:
    bool evenPossible(vector<int> &a){
        int n = a.size();
        vector<int> b(n , -1);
        for(int i = 0 ; i < n ;i++){
            if(!(a[i] & 1)) b[i] = 1;
            else {
                // finding the possible matching of odd number for this number
                int smallestOdd = *odd.begin();
                if((a[i] - smallestOdd) >= 1) b[i] = 1;
            }
        }

        for(auto &x : b){
            if(x == -1) return false;
        }
        return true;
    }

    bool oddPossible(vector<int> &a){
        int n = a.size();
        vector<int> b(n , -1);
        for(int i = 0 ; i < n ;i++){
            if(a[i] & 1) b[i] = 1;
            else {
                // finding the possible matching of odd number for this number
                int smallestOdd = *odd.begin();
                if((a[i] - smallestOdd) >= 1) b[i] = 1;
            }
        }

        for(auto &x : b){
            if(x == -1) return false;
        }
        return true;

    }
}; 