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
    ListNode *mergeTwoLists(ListNode *list1, ListNode *list2)
    {
        if (list1 == NULL && list2 == NULL)
            return NULL;
        if (list1 == NULL)
            return list2;
        if (list2 == NULL)
            return list1;
        ListNode *head = NULL;
        if (list1->val < list2->val)
        {
            ListNode *node = new ListNode(list1->val);
            head = node;
            list1 = list1->next;
        }
        else if (list1->val > list2->val)
        {
            ListNode *node = new ListNode(list2->val);
            head = node;
            list2 = list2->next;
        }
        else
        {
            ListNode *node = new ListNode(list1->val);
            head = node;
            list1 = list1->next;
            // list2=list2->next;
        }
        ListNode *temp = head;
        while (list1 != NULL && list2 != NULL)
        {
            if (list1->val < list2->val)
            {
                ListNode *node = new ListNode(list1->val);
                temp->next = node;
                temp = node;
                list1 = list1->next;
            }
            else if (list2->val < list1->val)
            {
                ListNode *node = new ListNode(list2->val);
                temp->next = node;
                temp = node;
                list2 = list2->next;
            }
            else
            {
                ListNode *node1 = new ListNode(list1->val);
                ListNode *node2 = new ListNode(list2->val);
                temp->next = node1;
                temp = node1;
                temp->next = node2;
                temp = node2;
                list1 = list1->next;
                list2 = list2->next;
            }
        }
        while (list1 != NULL)
        {
            ListNode *node = new ListNode(list1->val);
            temp->next = node;
            temp = node;
            list1 = list1->next;
        }
        while (list2 != NULL)
        {
            ListNode *node = new ListNode(list2->val);
            temp->next = node;
            temp = node;
            list2 = list2->next;
        }
        return head;
    }
};