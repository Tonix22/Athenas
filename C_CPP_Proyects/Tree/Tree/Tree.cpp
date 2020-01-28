/**@file Tree.cpp 
* @Brief Prints the absolute probability of falling on a leaf node 
* given a root/HEAD node as input.
*/

#include <iostream>
#include <vector>
using namespace std;

/**
* @Brief Creates a simple node, which has:
* - An array of pointer to children nodes
* - A parent
* - A probability value of falling into the node
* given a root/HEAD node as input.
*/
struct Node {
    vector<Node*> nodePointer;
    Node* parent = nullptr;
    int probability;
};

/**
* @Brief Creates a node and assigns it a parent.
*/
Node* addNode(Node* parent) {
    Node* newNode = new Node();
    newNode->parent = parent;
    parent->nodePointer.push_back(newNode);
    return newNode;
}

/**
* @Brief Recursively searches for childrens starting from a root node;
* This means that for any children a search for childrens must be made.
* For any leaf node(!headsize), the absolute probability of falling into that node must be set.
* @param head: root or children node
* @param probability: probability of falling into a given node = 1/n. 
* Where n is the number of branches/childrens of a given node
*/
void probabilitySon(Node* head, int probability) {
    int headSize = head->nodePointer.size();
    for (int i = 0; i < headSize; i++) {

        probabilitySon(head->nodePointer[i], probability / headSize);
    }
    if (!headSize) head->probability = probability;         /**Leaf node */
    
}

int main()
{
    Node* head = new Node();
    Node* first = addNode(head);
    Node* second = addNode(first);
    Node* third = addNode(first);
    Node* cuarto = addNode(head);
    Node* quinto = addNode(cuarto);
    Node* sesto = addNode(head);

    probabilitySon(head, 100);
    printf("%d\n", first->probability);
    printf("%d\n", second->probability);
    printf("%d\n", third->probability);
    printf("%d\n", cuarto->probability);
    printf("%d\n", quinto->probability);
    printf("%d\n", sesto->probability);
    std::cout << "Hello World!\n";

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu
