#include <iostream>

struct ListNode {
      int val;
      ListNode *next;
      ListNode(int x) : val(x), next(NULL) {}
};
// µü´ú 
ListNode* reverseList(ListNode* head) {
        if(head == NULL)

            return head;
        struct ListNode* temp = head->next;
        head->next = NULL;
        
        while(temp != NULL)
        {
            struct ListNode* temp2 = temp->next;
            temp->next = head;
            head = temp;
            temp = temp2;
        }
        return head;
}
//µİ¹é 
ListNode* reverseList(ListNode* head) {
        if(head == NULL)
            return head;
        if(head->next != NULL)
        {
            ListNode* tmp = reverseList(head->next);
            ListNode* it = tmp;
            while(it->next != NULL)
            {
                it = it->next;
            }
            head->next = NULL;
            it->next = head;
            
            return tmp;
        }
        else
            return head;
    }
int main()
{
	return 0;
}
