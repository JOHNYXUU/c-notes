#include<iostream>
class Node 
{
    public:
        int val;
        vector<Node*> children;

        Node() {}

        Node(int _val) {
            val = _val;
        }

        Node(int _val, vector<Node*> _children) {
            val = _val;
            children = _children;
        }
};
void preOrder(Node* root)
{
    stack<Node*> stk;
    auto node = root;
    if(node)
        stk.push(node);
    while(stk.size())
    {
        node = stk.top();
        stk.pop();
        std::cout << node->val << " \n";
        for(int i=node->children.size() - 1;~i;i--)
        {
            stk.push(node->children[i]);
        }
    }
}
void postOrder(Node* root)
{
    stack<Node*> stk;
    auto node = root;
    Node* pre = nullptr;
    if(node)
        stk.push(node);
    while(stk.size())
    {
        node = stk.top();
        stk.pop();

        if(node->children.size() == 0 || *node->children.rbegin() == pre)
        {
            std::cout << node->val << " \n";
            pre = node;
            node = nullptr;
        }
        else
        {
            stk.push(node);
            for(int i=node->children.size()-1;~i;i--)
            {
                stk.push(node->children[i]);
            }
        }
    }
}
int main()
{
    return 0;
}