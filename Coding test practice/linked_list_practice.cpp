#include <iostream>
#include <string>
using namespace std;
class node {
public:
    string name;
    node* link;
};
node* add_to_head(node* head,string new_name) {
    node* tmp = new node;
    tmp->name = new_name;
    tmp->link = head;
    return tmp;
}
node* add_to_tail(node* head, string new_name) {
    node* tmp = new node;
    tmp->name = new_name;
    tmp->link = NULL;
    if (head == NULL) return tmp;
    node* p = head;
    while (p->link!=NULL) {
        p = p->link;
    }
    p->link = tmp;
    return head;
}
node* remove_node(node* head,string target_name) {
    node* current = head;
    node* prev = NULL;
    if (head == NULL) return head;
    if (head->name == target_name) {
        head = head->link;
        delete current;
        return head;
    }
    while (current != NULL && current->name != target_name) {
        prev = current;
        current = current->link;
    }
    if (current == NULL) return head;
    prev->link = current->link;
    delete current;
    return head;
}
node* reverse_list(node* head) {
    node* current = head;
    node* prev = NULL;
    node* next_node;
    while (current!=NULL) {
        next_node = current->link;
        current->link = prev;
        prev = current;
        current = next_node;
    }
    return prev;
}
int main(){
    node* head = NULL;
    string input;
    for (int i=0;i<5;i++) {
        cout << "# "<<i+1<<"/5"<<" What is your favorite color: ";
        cin >> input;
        head = add_to_tail(head,input);
    }
    for (node* p=head;p!=NULL;p=p->link) {
        cout << p->name << " ";
    }
    cout << "\nRemove color name: ";
    cin >> input;
    head = remove_node(head,input);
    for (node* p=head;p!=NULL;p=p->link) {
        cout << p->name << " ";
    }
    cout << "\ninverse version:\n";
    head = reverse_list(head);
    for (node* p=head;p!=NULL;p=p->link) {
        cout << p->name << " ";
    }
    return 0;
}