/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution
{
public:
    ListNode *reverseListForK(ListNode *head, int k)
    {
        if (head == NULL || head->next == NULL || k == 0 || k == 1)
        {
            return head;
        }
        int traverseK;
        ListNode *curNode = head, *newHead = NULL, *prevNode = NULL,
                 *nextNode = NULL, *joinNode = NULL, *tailNode = NULL;

        while (curNode != NULL)
        {
            joinNode = curNode;
            traverseK = k;
            while (curNode != NULL && traverseK--)
            {

                nextNode = curNode->next;
                curNode->next = prevNode;
                prevNode = curNode;
                curNode = nextNode;
            }

            if (newHead == NULL)
            {
                newHead = prevNode;
            }
            if (tailNode)
            {
                tailNode->next = prevNode;
            }

            tailNode = joinNode;
            prevNode = NULL;
        }
        return newHead;
    }
    ListNode *reverseList(ListNode *head)
    {
        return reverseListForK(head, -1);
    }
};