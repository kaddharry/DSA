class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0) return false;
        stack<int> st;
        int temp = x;
        int n = 0;
        while(temp){
            st.push(temp%10);
            temp /= 10;
            n++;
        }
        temp = x;
        n /= 2;
        while(n){
            int y = st.top();
            if(y != temp%10) return false;
            st.pop();
            temp /= 10;
            n--;
        }
        return true;
    }
};