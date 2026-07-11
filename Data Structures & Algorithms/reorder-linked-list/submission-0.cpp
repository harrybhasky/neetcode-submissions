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
    void reorderList(ListNode* head) {
        // use slow and fast pointer method to find middle of linked list.
        // fast moves two steps and when reaches end, slow is mid.
        ListNode* slow = head;
        ListNode* fast = head->next;

        while(fast!=nullptr && fast->next != nullptr){
            slow = slow->next;
            fast = fast->next->next;
        }
        
        ListNode* second = slow->next;  // second half starts here (e.g., node 4)
        slow->next = nullptr;           // cut first half so it terminates at node 3
        ListNode* prev = nullptr;       // prev starts as null (for reversal)

        // reversing second half
        while (second != nullptr) {
    ListNode* tmp = second->next;
    second->next = prev;
    prev = second;
    second = tmp;
}
ListNode* first = head;      // 1→2→3
second = prev;                // 6→5→4 (reused variable, now head of reversed half)
while (second != nullptr) {
    ListNode* tmp1 = first->next;   // save next node in first half
    ListNode* tmp2 = second->next;  // save next node in second half
    first->next = second;           // 1 -> 6
    second->next = tmp1;            // 6 -> 2
    first = tmp1;                   // move first forward (to old "2")
    second = tmp2;                  // move second forward (to old "5")
}
    }
};
