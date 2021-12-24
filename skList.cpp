#include <iostream>
#include <cstdlib>
#include "skList.h"
#include "node.cpp"

skList::skList(int lvl)
{
    //Initialize vector of nodes to
    //nodes all pointing to NULL

    //setting the tower (head tower)
    node *temp;
    node *saver;
    int currLvl = 0;
    for (int i = 0; i < lvl; i++)
    {
        if (i == 0)
        {
            temp = new node();
            vecNodes.push_back(temp);
        }
        else
        {
            temp = new node();
            saver = vecNodes[currLvl];
            currLvl++;
            vecNodes.push_back(temp);
            saver->setDown(temp);
        }
    }
    this->maxLevel = lvl;
}
bool skList::insertNode(int key)
{
    //nodeSaver saves references to previous
    //nodes;for insertion
    //reset each time
    nodeSaver.clear();
    if (searchList(key))
    {
        std::cout << "Cannot insert duplicate node" << std::endl;
        return false;
    }
    //temp is used to move throughout the list
    //and will start at the top left
    node *temp = vecNodes[0];
    //Search for correct node placement
    //correct node placement will be when:
    //you cant go to the right anymore
    //  -either because its null or greater
    //AND
    //you cant go down either

    //We want to save references to the nodes that
    //we go down from
    //if at lvl 0 then save current node before going
    //to the right

    while (true)
    {
        //Search current level
        //check to see if there is something to the right
        if (temp->getRight() != NULL)
        {
            int nextData = temp->getRight()->getData();
            //check to see if next key > our key
            if (nextData > key)
            {
                //if true then try to go down a level
                if (temp->getDown() != NULL)
                {
                    //save temp
                    nodeSaver.push_back(temp);
                    //go down a level
                    temp = temp->getDown();
                }
                //if you cant go down a level and the next thing
                //over is greater then insert there
                else
                {
                    //insert data
                    //make the new node (random height up to max)
                    //above 50, add a height else dont
                    int prob = rand() % 100 + 1;
                    //height must be at least 1
                    int height = 1;
                    //changerHeight starts at maxLevel and goes down,
                    //it ends up being where you start in the vector
                    //nodeSaver (since nodeSaver 0 is top)
                    int changerHeight = maxLevel - 1;
                    //newNode used to allocate memory for new nodes
                    node *newNode;
                    //oldSaver used to save the previous node inorder
                    //to save connections down (like iterator)
                    node *oldSaver;
                    //topSaver is the top of the new node (like head)
                    node *topSaver;
                    while (prob > 50 && height < maxLevel)
                    {
                        height++;
                        changerHeight--;
                        prob = rand() % 100 + 1;
                    }
                    //random height has been generated
                    //now build up the node to the height

                    //changerHeight explained:
                    //changerHeight will be starting point for nodeSaver,
                    //changerHeight starts at max-1, since max-1 is the bottom
                    //for nodeSaver and as changerHeight decrements it represents
                    //an increase in nodeSaver height, since nodeSaver height's
                    //tallest point is zero and lowest point is max-1
                    for (int i = 0; i < height; i++)
                    {
                        if (i == 0)
                        {
                            newNode = new node();
                            oldSaver = newNode;
                            topSaver = oldSaver;
                        }
                        else
                        {
                            newNode = new node();
                            oldSaver->setDown(newNode);
                            oldSaver = oldSaver->getDown();
                        }
                    }
                    //individual node with random height is finished
                    //now integrate into the skiplist
                    for (int i = changerHeight; changerHeight != maxLevel - 1; i++)
                    {
                        //saves current node at height of changerHeight
                        node *cSaver = nodeSaver[changerHeight];
                        //saves nodes old right
                        node *rSaver = nodeSaver[changerHeight]->getRight();
                        //makes currents new right equal to topSaver, which is
                        //the new node with new height
                        cSaver->setRight(topSaver);
                        //set new node with new height right equal to the old right
                        topSaver->setRight(rSaver);
                        //go down a level
                        topSaver = topSaver->getDown();
                    }
                    //Now connect the bottom level
                    //temp represents where we are currently at and its right
                    //will be the new node
                    node *oldRight = temp->getRight();
                    temp->setRight(topSaver);
                    topSaver->setRight(oldRight);

                    return true; /*  */
                }
            }
        }
        //else there is nothing to the right
        else
        {
            //try to go down a level
            if (temp->getDown() != NULL)
            {
                //Save a reference to the node inside
                //of nodeSaver vector
                //nodeSaver vector will have its top be
                //zero and bottom be maxLevel
                nodeSaver.push_back(temp);
                temp = temp->getDown();
            }
            //if you cant go down nor right, then
            //insert here
            else
            {
                //insert node

                //make the new node (random height up to max)
                //above 50, add a height else dont
                int prob = rand() % 100 + 1;
                //height must be at least 1
                int height = 1;
                //changerHeight starts at maxLevel and goes down,
                //it ends up being where you start in the vector
                //nodeSaver (since nodeSaver 0 is top)
                int changerHeight = maxLevel - 1;
                //newNode used to allocate memory for new nodes
                node *newNode;
                //oldSaver used to save the previous node inorder
                //to save connections down (like iterator)
                node *oldSaver;
                //topSaver is the top of the new node (like head)
                node *topSaver;
                while (prob > 50 && height < maxLevel)
                {
                    height++;
                    changerHeight--;
                    prob = rand() % 100 + 1;
                }
                //random height has been generated
                //now build up the node to the height

                //changerHeight explained:
                //changerHeight will be starting point for nodeSaver,
                //changerHeight starts at max-1, since max-1 is the bottom
                //for nodeSaver and as changerHeight decrements it represents
                //an increase in nodeSaver height, since nodeSaver height's
                //tallest point is zero and lowest point is max-1
                for (int i = 0; i < height; i++)
                {
                    if (i == 0)
                    {
                        newNode = new node();
                        oldSaver = newNode;
                        topSaver = oldSaver;
                    }
                    else
                    {
                        newNode = new node();
                        oldSaver->setDown(newNode);
                        oldSaver = oldSaver->getDown();
                    }
                }
                //individual node with random height is finished
                //now integrate into the skiplist
                for (int i = changerHeight; changerHeight != maxLevel - 1; i++)
                {
                    //saves current node at height of changerHeight
                    node *cSaver = nodeSaver[changerHeight];
                    //saves nodes old right
                    node *rSaver = nodeSaver[changerHeight]->getRight();
                    //makes currents new right equal to topSaver, which is
                    //the new node with new height
                    cSaver->setRight(topSaver);
                    //set new node with new height right equal to the old right
                    topSaver->setRight(rSaver);
                    //go down a level
                    topSaver = topSaver->getDown();
                }
                //Now connect the bottom level
                //temp represents where we are currently at and its right
                //will be the new node
                node *oldRight = temp->getRight();
                temp->setRight(topSaver);
                topSaver->setRight(oldRight);

                return true;
            }
        }
    }
}
bool skList::searchList(int key)
{
    //start at top level of vector of node*'s
    node *temp = vecNodes[0];
    //stay in the loop until we have found,
    //not found, or found a duplicate
    while (true)
    {
        //Search current level
        //check to see if there is something to the right
        if (temp->getRight() != NULL)
        {
            int nData = temp->getRight()->getData();
            //if key we are looking for is < current right key
            if (key < nData)
            {
                //then go down a level
                //check to see that you can go down
                if (temp->getDown() != NULL)
                {
                    temp = temp->getDown();
                }
                else
                {
                    //if you cant go down, then you're at
                    //lvl 0 and so key DNE
                    std::cout << "Not found (Key)" << std::endl;
                    return false;
                }
            }
            //else if key is we are looking for is >
            //current right key then go right
            else if (key > nData)
            {
                //already checked that we can go right
                temp = temp->getRight();
            }
            //else if equal then return true
            else
            {
                return true;
            }
        }
        //else there is nothing to the right
        else
        {
            //try to go down a level
            if (temp->getDown() != NULL)
            {
                temp = temp->getDown();
            }
            //if you cant go down nor right, then
            //key DNE
            else
            {
                std::cout << "Not found (Key)" << std::endl;
                return false;
            }
        }
    }
}
bool skList::deleteNode(int key)
{
    if (!searchList(key))
    {
        std::cout << "Cannot delete key; DNE" << std::endl;
        return false;
    }
    //mostly same as insert except dont create new node delete it
}
void skList::displayList()
{
    std::cout << "Empty list" << std::endl;
}