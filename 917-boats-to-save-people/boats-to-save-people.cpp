class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {

        multiset<int>st;
        for(auto &x : people) st.insert(x);

        int cnt = 0;
        for(auto &x : people){
            // check if this no exists or not
            auto it = st.find(x);
            if(it == st.end()) continue;

            int counterPart =  limit - *it;

            st.erase(it); // deleting number

            it = st.upper_bound(counterPart);
            if(it == st.begin()){
                cnt += 1;
                continue;
            }
            else  if(it == st.end()){
                auto last = prev(st.end());
                st.erase(last);
            }else {
                auto last = prev(it);
                st.erase(last);
            }

            cnt += 1;          
            
        }

        return cnt;
        
    }
};