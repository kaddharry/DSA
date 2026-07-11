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
    ListNode* rotateRight(ListNode* head, int k) {
        // code here
        if(!head || k == 0) return head;
		int size = 0;
		ListNode* p = head;
		while (p) {
			size++;
			p = p->next;
		}
        if(k%size == 0) return head;
		int rotate = size - k%size;
		if(rotate == 0) return head;
		p = head;
		ListNode* Newhead;
		rotate--;
		while (rotate) {
			p = p->next;
			rotate--;
		}
		// Now the next ListNode will be Newhead
		Newhead = p->next;
		p->next = NULL;
		p = Newhead;
		while (p->next) {
			p = p->next;
		}
		p->next = head;
		// 		 head = Newhead;
		return Newhead;
    }
};