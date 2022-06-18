#include "iostream"
#include "linkedList_dataType.h"
using namespace std;

int main()
{
    Node *head = take_input();
    print(head);

    int i,val;
    cin>>i>>val;
    head = insert_at_key(head,i,val);
    print(head);

    int j;
    cin>>j;
    head = delete_at_key(head,j);
    print(head);
}
