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
class Solution
{
public:
    int len(ListNode *head)
    {
        ListNode *temp = head;
        int count = 0;
        while (temp != NULL)
        {
            count++;
            temp = temp->next;
        }
        return count;
    }
    ListNode *removeNthFromEnd(ListNode *head, int n)
    {
        if (head->next == NULL && n == 1)
        {
            delete head;
            return NULL;
        }
        ListNode *temp = head;
        if (len(head) == n)
        {
            head = head->next;
            temp->next = NULL;
            delete temp;
            return head;
        }
        int n1 = len(head) - n;
        while (n1 > 1)
        {
            temp = temp->next;
            n1--;
        }
        ListNode *prev = temp;
        temp = temp->next;
        prev->next = temp->next;
        temp->next = NULL;
        delete temp;
        return head;
    }
};