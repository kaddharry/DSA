class Solution {
public:
    char processStr(string s, long long k) {
        // Track the length of the string at each step
        vector<long long> lengths;
        long long current_len = 0;

        for (char c : s) {
            if (c >= 'a' && c <= 'z') {
                current_len++;
            } else if (c == '*') {
                if (current_len > 0) {
                    current_len--;
                }
            } else if (c == '#') {
                current_len *= 2;
            } else if (c == '%') {
                // Reversal doesn't change total length
            }
            lengths.push_back(current_len);
        }

        // Out of bounds check using your safe condition
        if (k >= current_len) return '.';

        // Trace backwards to find the exact character
        for (int i = s.length() - 1; i >= 0; i--) {
            char c = s[i];
            long long prev_len = (i == 0) ? 0 : lengths[i - 1];

            if (c >= 'a' && c <= 'z') {
                // If k is tracking the newly added character, this is it!
                if (k == prev_len) {
                    return c;
                }
            } else if (c == '#') {
                // If k is in the duplicated half, map it back to the original half
                if (k >= prev_len) {
                    k %= prev_len;
                }
            } else if (c == '%') {
                // Mirror the index for the reversed block
                long long len = lengths[i];
                k = len - 1 - k;
            }
            // For '*', the deleted character wasn't part of the final k path, 
            // so we simply step backwards over it.
        }

        return '.';
    }
};