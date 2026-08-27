class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        sort(begin(nums),end(nums));

        vector<int> ans;
        int n = nums.size();
        for(int i = 0 ;i < n-1 ; i++){
            for(int j = nums[i]+1 ; j < nums[i+1] ; j++){
                ans.push_back(j);
            }
        }

        return ans;
    }
};