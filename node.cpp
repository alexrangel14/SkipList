#include <iostream>
#include "node.h"

node::node()
{
    setRight(NULL);
    setDown(NULL);
    setData(-1);
}

void node::setData(int nData)
{
    this->data = nData;
}
void node::setDown(node *dNode)
{
    this->down = dNode;
}
void node::setRight(node *rNode)
{
    this->right = rNode;
}
int node::getData()
{
    return data;
}
node *node::getDown()
{
    return down;
}
node *node::getRight()
{
    return right;
}