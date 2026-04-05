//Infix expression을 Postfix expression으로 변환하는 프로그램
#include <iostream>
#include <string>
#define SIZE 100
#define EOS '$'
using namespace std;
class stack {
    char s[SIZE];
    int top;
public:
    stack() { top = 0; }
    void push(char c);
    char pop();
    bool empty();
    char r_top(){return s[top-1];}
};
bool is_operand(char c);
int get_precedence(char op);

int main() {
    string input,output;
    int i;
    stack s;
    cout<<"Input an infix expression to convert: ";
    cin>>input;
    s.push(EOS);
    for (i=0;i<input.length();i++) {
        char current=input[i];
        if (current=='(') {
            s.push('(');
        }
        else if (current==')') {
            while (!s.empty()&&s.r_top()!='('){
                output += s.pop();
            };
            s.pop();
        }
        else if (is_operand(current)) {
            output+=current;
        } else {
            while (!s.empty() && s.r_top() != EOS && get_precedence(s.r_top())>=get_precedence(current)) {
                output+=s.pop();
            }
            s.push(current);
        }
    }
    while (!s.empty() && s.r_top() != EOS) {
        output += s.pop();
    }
    cout<<"Output is: "<<output<<endl;
    return 0;
}
bool is_operand(char c) {
    if (c=='('||c ==')'||c=='+'||c=='-'||c=='/'||c=='*'||c=='%'||c==EOS) return false;
    else return true;
}
int get_precedence(char op) {
    if (op==EOS||op=='(') return 0;
    if (op=='+'||op=='-') return 1;
    if (op=='*'||op=='/'||op=='%') return 2;
    return -1;
}
void stack::push(char c) {
    s[top] = c;
    top++;
}
char stack::pop() {
    top--;
    return s[top];
}
bool stack::empty() {
    if (top == 0) return true;
    else return false;
}
