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
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currentA = headA;
        ListNode *currentB = headB;
        
        while(currentA != currentB) {
            if(currentA == NULL) {
                currentA = headB;
            } else {
                currentA = currentA -> next;
            }
            
            if(currentB == NULL) {
                currentB = headA;
            } else {
                currentB = currentB -> next;
            }
        }
        
        return currentA;
    }
};