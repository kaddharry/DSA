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
    int pairSum(ListNode* head) {
        if(!head) return 0;
        ListNode* f = head->next, *s = head;
        int size = 1;
        while(f->next){
            s = s->next;
            f = f->next->next;
            size++;
        }
        size *= 2;
        if(size == 2) return (head->val + head->next->val);
        ListNode* mid = s->next;
        s->next = reverse(mid);
        mid = s->next; //update new mid
        int max = INT_MIN;
        f = head; //our pointer
        while(mid){
            int sum = f->val + mid->val;
            max = sum>max ? sum:max;
            f = f->next;
            mid = mid->next;
        }

        return max;
        
    }
};