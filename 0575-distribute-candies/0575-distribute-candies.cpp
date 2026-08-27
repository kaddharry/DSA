class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        unordered_set <int> st(candyType.begin(),candyType.end());
        int n = candyType.size()/2;
        int s = st.size();
        if(s < n) return s;
        return n;
    }
};