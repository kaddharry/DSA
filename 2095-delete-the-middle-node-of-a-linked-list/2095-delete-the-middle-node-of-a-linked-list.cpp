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
    ListNode* deleteMiddle(ListNode* head) {
        ListNode dummy(0);
        ListNode* prev = &dummy;
        prev->next = head;

        ListNode *slow = head, *fast = head;
        while (fast && fast->next) {
            prev = prev->next;
            slow = slow->next;
            fast = fast->next->next;
        }
        if(slow == head) return NULL;
        prev->next = slow->next;
        return head;
    }
};