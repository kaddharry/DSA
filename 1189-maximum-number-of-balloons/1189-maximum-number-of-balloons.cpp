class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int freq[26] = {0};

        for(char c : text)
            freq[c - 'a']++;

        return min({
            freq['b' - 'a'],
            freq['a' - 'a'],
            freq['l' - 'a'] / 2,
            freq['o' - 'a'] / 2,
            freq['n' - 'a']
        });
    }
};
// class Solution {
// public:
//     int maxNumberOfBalloons(string text) {
//         unordered_map <char, int> mp;
//         for(char c: text){
//             mp[c]++;
//         }
//         mp['l'] /= 2;
//         mp['o'] /= 2;
//         int count = INT_MAX;
//         for(char k: string("balon")){
//             if(mp[k] == 0) return 0;
//             int val = mp[k];
//             count = min(val, count);
//         }
//         return count;
//     }
// };