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


// idea
// initialize two pointers, second one n ahead of first
        // when second reaches end, first pointer elem shud be removed


class Solution {
public:
   ListNode* removeNthFromEnd(ListNode* head, int n) {
    ListNode dummy(0);
    dummy.next = head;

    ListNode* first = &dummy;
    ListNode* second = &dummy;

    // move first n+1 steps ahead, so gap between first and second is n+1
    for (int i = 0; i < n + 1; i++) {
        first = first->next;
    }

    // move both until first hits the end
    while (first != nullptr) {
        first = first->next;
        second = second->next;
    }

    // second is now right before the node to remove
    second->next = second->next->next;

    return dummy.next;
}
};
