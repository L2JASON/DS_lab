#include <iostream>
#include <string>

using namespace std;

#define SUCCESS 1
#define FAIL    0

class node {
public:
    string name;
    double score;
    node *link;
    void set_data(string s, double n);
};

void node::set_data(string s, double n) {
    name = s;
    score = n;
}

class my_list {
    node *head;
public:
    my_list();
    void add_to_head(node t);
    int remove_a_node(string tname);
    void insert_a_node(string tname, node t);
    void show_all_data();
};

my_list::my_list(){
    head = NULL;
}


void my_list::add_to_head(node t) {
    node *p;
    p = new node;
    (*p) = t;
    p->link = head;
    head = p;
}

int my_list::remove_a_node(string tname){
    node *target = head;
    node *prev = NULL;
    while (target!=NULL && target->name != tname) {
        prev = target;
        target = target->link;
    }
    if (target==NULL) return 0;
    if (prev!=NULL) prev->link = target->link;
    else head = target->link;
    delete target;
    return 1;
}

void my_list::insert_a_node(string tname, node t){
    node *target = head;
    while (target!=NULL && target->name != tname) {
        target = target->link;
    }
    if (target==NULL) {
        node *p;
        p = new node;
        (*p) = t;
        p->link = head;
        head = p;
    }
    else {
        node *tmp = target->link;
        node *p;
        p = new node;
        (*p) = t;
        p->link = tmp;
        target->link = p;

    }
}

void my_list::show_all_data(){
    node *p;
    for ( p = head; p != NULL; p = p->link)
        cout << p->name << " : " << p->score << endl;

}

int main(){
    my_list a;
    node tmp;
    tmp.set_data("Kim", 83.5);
    a.add_to_head(tmp);
    tmp.set_data("Lee", 58.2);
    a.add_to_head(tmp);
    tmp.set_data("Park", 91.3);
    a.add_to_head(tmp);
    tmp.set_data("Choi", 55.1);
    a.add_to_head(tmp);
    tmp.set_data("Ryu", 77.1);
    a.add_to_head(tmp);
    tmp.set_data("Yang", 41.3);
    a.add_to_head(tmp);
    tmp.set_data("Hong", 78.2);
    a.add_to_head(tmp);

    cout << "\nThe list before the test \n";
    a.show_all_data();
    a.remove_a_node("Ryu");
    cout << "\nThe list after the removal\n";
    a.show_all_data();
    tmp.set_data("Jeong", 97.5);
    a.insert_a_node("Choi", tmp);
    tmp.set_data("Cho", 85.5);
    a.insert_a_node("Kang", tmp);
    cout << "\nThe list after the insertions\n";
    a.show_all_data();
    return 0;
}

