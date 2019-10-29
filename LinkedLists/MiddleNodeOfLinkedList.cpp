class Solution {
public:
    ListNode* getMiddleNodeOfList(ListNode* head) {
        ListNode* slowNode = head;
        ListNode* fastNode = head;
        while (fastNode != NULL && fastNode->next != NULL) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        return slowNode;
    }
};
