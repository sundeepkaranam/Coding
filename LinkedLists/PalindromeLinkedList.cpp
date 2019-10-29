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
    ListNode* reverseList(ListNode* head)
    {
        if (head == NULL || head->next == NULL) {
            return head;
        }
        ListNode* curNode = head;
        ListNode* prevNode = NULL;
        ListNode* nextNode = NULL;

        while (curNode != NULL) {
            nextNode = curNode->next;
            curNode->next = prevNode;
            prevNode = curNode;
            curNode = nextNode;
        }
        return prevNode;
    }

    ListNode* getMiddleNodeOfList(ListNode* head)
    {
        ListNode* slowNode = head;
        ListNode* fastNode = head;
        while (fastNode != NULL && fastNode->next != NULL) {
            slowNode = slowNode->next;
            fastNode = fastNode->next->next;
        }
        return slowNode;
    }
    bool isPalindrome(ListNode* head)
    {
        ListNode* midNode = getMiddleNodeOfList(head);
        ListNode* firstHalf = head;
        ListNode* secondHalf = reverseList(midNode);
        while (firstHalf != midNode) {
            if (firstHalf->val != secondHalf->val) {
                return false;
            }
            firstHalf = firstHalf->next;
            secondHalf = secondHalf->next;
        }
        return true;
    }
};