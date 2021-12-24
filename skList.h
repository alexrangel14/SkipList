#ifndef SKLIST_H
#define SKLIST_H
#include <vector>
#include "node.h"


class skList{
    private:
    //vecNodes will be the sentinel tower
    //of node*'s
    std::vector<node*> vecNodes;
    //nodeSaver will save the references to
    //nodes; to help insertion in list
    std::vector<node*> nodeSaver;
    int maxLevel;
    public:
    skList(int lvl);
    bool insertNode(int key);
    bool deleteNode(int key);
    bool searchList(int key);
    void displayList();
};
#endif