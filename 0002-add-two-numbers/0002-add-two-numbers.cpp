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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        int carry = 0;

        // 1. Add both lists while both exist
        while (l1 && l2) {
            int x = l1->val + l2->val + carry;

            curr->next = new ListNode(x % 10);
            curr = curr->next;

            carry = x / 10;

            l1 = l1->next;
            l2 = l2->next;
        }

        // 2. Attach remaining list (but DO NOT trust it blindly)
        ListNode* rem = (l1 ? l1 : l2);

        while (rem) {
            int x = rem->val + carry;

            curr->next = new ListNode(x % 10);
            curr = curr->next;

            carry = x / 10;

            rem = rem->next;
        }

        // 3. If carry remains, add new node
        if (carry) {
            curr->next = new ListNode(carry);
        }

        return dummy->next;
    }
};
// int x = 0; int y = 0;
// int i = 0;
// if(carry && l1 && l2) return dummy->next;
// else if(carry){
//     curr->next = l1 ? l1:l2;
//     return dummy->next;
// }
// else if(!carry){
//     if(!l1){}
// }
// while(l1){
//     x += l1->val * pow(10,i);
//     i++;
//     l1 = l1->next;
// }
// i=0;
// while(l2){
//     y += l2->val * pow(10,i);
//     i++;
//     l2 = l2->next;
// }
// int result = x+y;
// ListNode* dummy = new ListNode(0);
// if(result == 0) return dummy;
// ListNode* curr = dummy;
// while(result){
//     int z = result%10;
//     result /= 10;
//     curr->next = new ListNode(z);
//     curr = curr->next;
// }
// curr->next = NULL;
// return dummy->next;

// ListNode* head = l1;
// int carry = 0;
// while(l1 && l2){
//     int x = 0;
//     x = l1->val  + l2->val + carry;
//     l1->val = x%10;

//     if(carry > 0) carry = 0;
//     if(x>9) carry++;

//     l1 = l1->next;
//     l2 = l2->next;
// }
// return head;