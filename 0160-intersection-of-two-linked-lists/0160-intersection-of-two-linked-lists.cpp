// Approach 1 
// TC : O(m * n)
// SC : O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *compareNode;
        while(headA != nullptr) {
            compareNode = headB;
            while(compareNode != nullptr) {
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