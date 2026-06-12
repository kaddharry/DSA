/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* Intersection(ListNode* headlonger, int sl, ListNode* head,
                           int ss) {
        // sl is size of longer and ss is size of shorter
        int diff = sl - ss;
        ListNode* p1 = headlonger;
        ListNode* p2 = head;
        while (diff) {
            diff--;
            p1 = p1->next;
        }
        // p1 and p2 are now equally distant from intersection
        while (p1 != p2) {
            p1 = p1->next;
            p2 = p2->next;
        }
        return p1;
    }
    ListNode* getIntersectionNode(ListNode* headA, ListNode* headB) {
        ListNode* p1 = headA;
        ListNode* p2 = headB;
        int s1 = 0, s2 = 0;
        while (p1) {
            p1 = p1->next;
            s1++;
        }
        while (p2) {
            p2 = p2->next;
            s2++;
        }
        ListNode* Inter;
        if (s1 > s2)
            Inter = Intersection(headA, s1, headB, s2);
        else
            Inter = Intersection(headB, s2, headA, s1);
        return Inter;
    }
};