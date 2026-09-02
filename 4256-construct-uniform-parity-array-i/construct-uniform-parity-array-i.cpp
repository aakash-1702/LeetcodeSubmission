class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int n = nums1.size();

        return oddPossible(nums1) || evenPossible(nums1);
            
    }
    private:
    bool oddPossible(vector<int> &nums){
        int n = nums.size();
        vector<int> a(n , -1);
        for(int i = 0 ;i < n ; i++){
            if(nums[i] & 1){
                a[i] = nums[i];
            }else {
                for(int j = 0 ; j < n ; j++){
                    if(i != j && (nums[j] & 1)) a[i] = true;
                }
            }
        }

        for(auto &x : a){
            if(x == -1) return false;
        }

        return true;
    }
    bool evenPossible(vector<int> &nums){
        int n = nums.size();
        vector<int> a(n , -1);
        for(int i = 0 ;i < n ; i++){
            if(!(nums[i] & 1)){
                a[i] = nums[i];
            }else {
                for(int j = 0 ; j < n ; j++){
                    if(i != j && !(nums[j] & 1)) a[i] = true;
                }
            }
        }

        for(auto &x : a){
            if(x == -1) return false;
        }

        return true;

    }
};