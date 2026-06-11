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
    bool isPalindrome(ListNode* head) {
        stack<int> st;
        ListNode* slow = head;
        ListNode* fast = head;
        while (fast != NULL && fast->next != NULL) {
            int x = slow->val;
            st.push(x);
            slow = slow->next;
            fast = fast->next->next;
        }
        if (fast != NULL && fast->next == NULL)
            slow = slow->next; // updates slow for ODD length case
        while (slow != NULL) {
            int y = slow->val;
            if (st.top() == y) {
                st.pop();
                slow = slow->next;
            } else
                return false;
        }
        return true;
    }
};