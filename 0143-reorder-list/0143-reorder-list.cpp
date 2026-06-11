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
    
    void reorderList(ListNode* head) {
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast != NULL && fast->next != NULL){
            slow = slow->next;
            fast = fast->next->next;
        }
        //we got the middle
        ListNode* h1 = head;
        ListNode* h2 = slow->next;
        h2 = reverse(h2);
        slow->next = NULL;
        ListNode* t1;
        ListNode* t2;
        while(h1 && h2){
            t1 = h1->next;
            t2 = h2->next;

            h1->next = h2;
            h2->next = t1;

            h1 = t1;
            h2 = t2;
        }
    }

private:
    ListNode* reverse(ListNode* head){
        ListNode* prev = NULL;
        ListNode* curr = head;
        ListNode* front;
        while(curr){
            front = curr->next;
            curr->next = prev;
            prev = curr;
            curr = front;
        }
        return prev;
    }
};