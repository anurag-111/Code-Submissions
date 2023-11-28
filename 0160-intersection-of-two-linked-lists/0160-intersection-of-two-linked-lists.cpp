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
        ListNode *currentNode = headA;
        while(currentNode != NULL) {
            ListNode *compareNode = headB;
            while(compareNode != NULL) {
                if(currentNode == compareNode) {
                    return currentNode;
                }
                compareNode = compareNode -> next;
            }
            currentNode = currentNode -> next;            
        }
        return NULL;
    }
};