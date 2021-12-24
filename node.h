#ifndef NODE_H
#define NODE_H

class node
{
private:
    int data;
    node *right;
    node *down;

public:
    node();
    void setData(int data);
    int getData();
    node *getRight();
    void setRight(node *rNode);
    node *getDown();
    void setDown(node *dNode);
};
#endif