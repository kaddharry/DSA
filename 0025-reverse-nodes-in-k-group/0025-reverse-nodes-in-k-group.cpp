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
    ListNode* reversek(ListNode* head, int k) {
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front = NULL;

        while (k--) {
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }

        return prev;
    }

    ListNode* reverseKGroup(ListNode* head, int k) {
        if (!head || k == 1) return head;

        ListNode *p1 = head;
        ListNode *prevTail = NULL;
        ListNode *newhead = head;

        while (p1) {

            // Check if k nodes exist
            ListNode* p2 = p1;
            int temp = k;

            while (temp > 1 && p2) {
                p2 = p2->next;
                temp--;
            }

            if (!p2) break;

            ListNode* nextGroup = p2->next;

            // isolate current group
            p2->next = NULL;

            ListNode* start = reversek(p1, k);

            if (prevTail)
                prevTail->next = start;
            else
                newhead = start;

            // p1 was old head, now tail
            p1->next = nextGroup;

            prevTail = p1;
            p1 = nextGroup;
        }

        return newhead;
    }
};