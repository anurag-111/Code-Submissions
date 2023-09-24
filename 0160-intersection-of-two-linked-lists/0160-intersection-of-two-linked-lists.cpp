class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        while(headA != NULL) {
            ListNode *compareNode = headB;
            while(compareNode != NULL) {
                if(headA == compareNode) {
                    return headA;
                }
                compareNode = compareNode -> next;
            }
            headA = headA -> next;
        }
        return NULL;
    }
};