// Approach 1 
// TC : O(m * n)
// SC : O(1)
// class Solution {
// public:
//     ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
//         ListNode *compareNode;
//         while(headA != nullptr) {
//             compareNode = headB;
//             while(compareNode != nullptr) {
//                 if(headA == compareNode) {
//                     return headA;
//                 }
//                 compareNode = compareNode -> next;
//             }
//             headA = headA -> next;
//         }
//         return NULL;
//     }
// };

// Approach 2
// TC : O(m + n)
// SC : O(1)
class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        ListNode *currentA = headA;
        ListNode *currentB = headB;

        while(currentA != currentB) {
            if(currentA == NULL) {
                // List A ends, move to List B
                currentA = headB;
            } else {
                // List A continues
                currentA = currentA -> next;
            }

            if(currentB == NULL) {
                // List B ends, move to List A
                currentB = headA;
            } else {
                // List B continues
                currentB = currentB -> next;
            }
        }

        return currentA;
    }
};













