/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        if(!head || !head -> next || !head -> next -> next) return {-1 , -1};
        int prev = head -> val;
        vector<int> ans;
        int cur = 1;
        
        while(head -> next){
            int nextVal = head -> next -> val;
            if((head -> val > prev && head -> val > nextVal) ||  (head -> val < prev && head -> val < nextVal)){
                ans.push_back(cur);
            }
            cur = cur + 1;
            prev = head -> val;
            head = head -> next;
        }

        if(ans.size() == 0 || ans.size() == 1) return {-1  , -1};

        int n = ans.size();


        // largest distance and smallest distance 
        int smallest = INT_MAX;
        for(int i = 0 ; i < n-1 ; i++){
            smallest = min(smallest , ans[i+1] - ans[i]);
        }

        return {smallest , ans[n-1]-ans[0]};
    }
};