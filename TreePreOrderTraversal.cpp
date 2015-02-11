//------------------------------------------------------------------------------
//  File            PreOrderTraversal.cpp
//  Date            10th Feb, 2015
//  Description     To traverse a tree in pre order traversal method using
//                  recursive and iterative method
//------------------------------------------------------------------------------

//----------------------------------Heders--------------------------------------
#include "TreePreOrderTraversal.h"
//------------------------------------------------------------------------------

//Class Definition CTreeDataStructure
/*
  Description - To traverse a non-empty binary search tree in pre-order.
                1. Visit the root.
                2. Traverse the left sub-tree.
                3. Traverse the right sub-tree
*/
//------------------------------------------------------------------------------

//Constructor
CTreeDataStructure :: CTreeDataStructure()
{
    m_pobjRootNode = NULL;

}

//Destructor
CTreeDataStructure :: ~CTreeDataStructure()
{
    freeNode(m_pobjRootNode);
}

//Add Node to the tree
void CTreeDataStructure :: addNode(int p_iData, CNode* p_objNodeLeaf)
{
    if ( p_iData <= p_objNodeLeaf->getNodeData()) 
    { 
        if ( p_objNodeLeaf->getLeftNode() != NULL)
        { 
            addNode(p_iData, p_objNodeLeaf->getLeftNode()); 
        }
        else 
        { 
            CNode* l_pobjNode = new CNode(); 
            l_pobjNode->setNodeData(p_iData); 
            p_objNodeLeaf->setLeftNode(l_pobjNode);
        }        
    } 
    else 
    { 
        if ( p_objNodeLeaf->getRightNode() != NULL )
        {
            addNode(p_iData,  p_objNodeLeaf->getRightNode()); 
        }
        else 
        { 
            CNode* l_pobjNode = new CNode(); 
            l_pobjNode->setNodeData(p_iData); 
            p_objNodeLeaf->setRightNode(l_pobjNode); 
        } 
    }
}

//Add Node 
void CTreeDataStructure :: addNode(int p_iData)
{
    //If Root is null add root tree node
    if(m_pobjRootNode == NULL)
    {
        //Create a New Node type Class
        CNode* l_pobjRootNode = new CNode();
        
        //Set the Data in to its member
        l_pobjRootNode->setNodeData(p_iData);

        //Assign the member root node
        m_pobjRootNode = l_pobjRootNode;    
    }
    //If null form the root node
    else
    {
        addNode(p_iData,m_pobjRootNode);
    }   

}

//Recursive Preorder Traversal
void CTreeDataStructure :: preOrderTraversalRecursive(CNode* p_pobjNode)
{
    if (p_pobjNode == NULL) return;
     
    std::cout << p_pobjNode->getNodeData() << " "; 
    preOrderTraversalRecursive(p_pobjNode->getLeftNode()); 
    preOrderTraversalRecursive(p_pobjNode->getRightNode()); 

}

//Iterative PreOrder Traversal
void CTreeDataStructure :: preOrderTraversalIterative(CNode* p_pobjNode)
{
    // Root Node
    if (p_pobjNode == NULL) return;
 
    // Push the root node to stack
    m_stkNode.push(p_pobjNode);
 
    /* Pop all items one by one. Do following for every popped item
       a) print it
       b) push its right child
       c) push its left child
    Note that right child is pushed first so that left is processed first */
    while (m_stkNode.empty() == false)
    {
        // Pop the top item from stack and print it
        CNode *l_pobjNode = m_stkNode.top();
        std::cout<<l_pobjNode->getNodeData()<<" ";
        m_stkNode.pop();
 
        // Push right and left children of the popped node to stack
        if (l_pobjNode->getRightNode())
            m_stkNode.push(l_pobjNode->getRightNode());
        if (l_pobjNode->getLeftNode())
            m_stkNode.push(l_pobjNode->getLeftNode());
    }
    std::cout<<std::endl;
}


//Free Nodes
void CTreeDataStructure :: freeNode(CNode* p_pobjNode)
{

    if ( p_pobjNode != NULL ) 
    { 
        freeNode(p_pobjNode->getLeftNode());
        freeNode(p_pobjNode->getRightNode()); 
        p_pobjNode = NULL; 
    }
}

//------------------------------------------------------------------------------
//                              End of File
//------------------------------------------------------------------------------
