class Solution {
public:
    string mostCommonWord(string paragraph, vector<string>& banned) {
        unordered_set<string> st(banned.begin(), banned.end());
        unordered_map<string, int> freq;

        string word;
        string res;
        int maxFreq = 0;

        for (char& c : paragraph) {
            if (isalpha(c)) {
                word += tolower(c);
            } else {
                if (!word.empty()) {
                    if (!st.count(word)) {
                        freq[word]++;

                        if (freq[word] > maxFreq) {
                            maxFreq = freq[word];
                            res = word;
                        }
                    }
                    word.clear();
                }
            }
        }

        // Process the last word if paragraph doesn't end with punctuation
        if (!word.empty() && !st.count(word)) {
            freq[word]++;

            if (freq[word] > maxFreq) {
                res = word;
            }
        }

        return res;
    }
};
