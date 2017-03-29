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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
       if (l1 == NULL) return l2; 
        if (l2 == NULL) return l1;
        ListNode* res = new ListNode(0);
        ListNode*p = res;
        res->val +=  l1->val + l2->val;
        l1 = l1->next;
        l2 = l2->next;
        while (l1!=NULL || l2!=NULL || res->val>9){ 
            res->next = new ListNode(res->val / 10);
            res->val %= 10;
            res = res->next;
            if (l1 != NULL){
                res->val += l1->val;
                l1 = l1->next;
            }
            if (l2 != NULL){
                res->val += l2->val;
                l2=l2->next;
            }
        } 
        return p;
    }
};





