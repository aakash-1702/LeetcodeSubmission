class Solution {
    unordered_set<int> st;
public:
    int totalNumbers(vector<int>& digits) {

        fun(0 , 0 , digits);
        return st.size();
    }
    private:
    void fun(int index , int curNum , vector<int> &digits){
        if(index == 3){
            if(curNum % 2) return;
            st.insert(curNum);
            return;
        }

        // for index 2 i will take only the positive posible number
        // for index 1 , i can take any possible number
        // for 0th one i can take any except 0
        if(index == 0){
            for(auto &x : digits){
                if(x > 0 && x <= 9){
                    int curDigit = x;
                    x = 10;
                    fun(index + 1 , curNum * 10 + curDigit , digits);
                    x = curDigit;
                }
            }
        }else if(index == 1){
            for(auto &x : digits){
                if(x <= 9){
                    int curDigit = x;
                    x = 10;
                    fun(index + 1 , curNum * 10 + curDigit , digits);
                    x = curDigit;
                }
            }
        }else {
            for(auto &x : digits){
                if(x <= 9 && !(x % 2)){
                    int curDigit = x;
                    x = 10;
                    fun(index + 1 , curNum * 10 + curDigit , digits);
                    x = curDigit;
                }
            }
        }

        return;


    }
};