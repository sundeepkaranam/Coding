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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL){
		return head;
    }
	ListNode* curNode = head;
    ListNode* prevNode =NULL;
    ListNode* nextNode = NULL;
        
	while(curNode != NULL){
        nextNode = curNode->next;
		curNode->next = prevNode;
		prevNode = curNode;
		curNode = nextNode;
	}
    return prevNode;
    }
};
