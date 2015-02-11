#include "TreePreOrderTraversal.h"

int main()
{
    CTreeDataStructure l_objTreeDataStructure;
    l_objTreeDataStructure.addNode(10);
    l_objTreeDataStructure.addNode(11);
    l_objTreeDataStructure.addNode(1);
    l_objTreeDataStructure.addNode(2);
    l_objTreeDataStructure.addNode(23);
    l_objTreeDataStructure.addNode(100);
    l_objTreeDataStructure.addNode(50);
    l_objTreeDataStructure.addNode(0);
    l_objTreeDataStructure.addNode(5);
    l_objTreeDataStructure.addNode(80);
    l_objTreeDataStructure.addNode(9);

    std::cout<<"Recursive Pre Order Traversal"<<std::endl;
    l_objTreeDataStructure.preOrderTraversalRecursive(l_objTreeDataStructure.getRootNode());
    std::cout<<std::endl<<"Iterative Pre Order Traversal"<<std::endl;
    l_objTreeDataStructure.preOrderTraversalIterative(l_objTreeDataStructure.getRootNode());    
    std::cout<<std::endl;

    return 0;
}
