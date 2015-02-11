//------------------------------------------------------------------------------
//  File            PreOrderTraversal.h
//  Date            10th Feb, 2015
//  Description     To traverse a tree in pre order traversal method using
//                  recursive and iterative method
//------------------------------------------------------------------------------

//----------------------------------Heders--------------------------------------
#include <iostream>
#include <stack>
//------------------------------------------------------------------------------

//Class Declaration Data Structure for the Tree Nodes
//------------------------------------------------------------------------------
class CNode
{
    private:
        //Data to be stored in the node
        int m_iData;
    
        //Pointer to the left Child
        CNode * m_pobjNodeLeft;

        //Pointer to the Right Child
        CNode * m_pobjNodeRight;
            
    public:
    
        //Contructor
        CNode(){m_pobjNodeLeft = NULL;m_pobjNodeRight = NULL;}
        
        //Destructor
        ~CNode();
        
        //Utility Inline Functions

        //Data Set Function
        void setNodeData(int p_iData){ m_iData = p_iData;}

        //Data Get Function
        int getNodeData(){ return m_iData;}

        //Data Set Left Node
        void setLeftNode(CNode* p_pobjNode){ m_pobjNodeLeft = p_pobjNode;}

        //Data Get Left Node
        CNode* getLeftNode(){ return m_pobjNodeLeft;}

        //Data Set Right Node
        void setRightNode(CNode* p_pobjNode){ m_pobjNodeRight = p_pobjNode;}

        //Data Get Right Node
        CNode* getRightNode(){ return m_pobjNodeRight;}       
};
//------------------------------------------------------------------------------

//Class Definition CTreeDataStructure
//------------------------------------------------------------------------------
class CTreeDataStructure
{
    private:

        //Save the Root Node in the member variable
        CNode* m_pobjRootNode;

        //Add Node to the 
        void addNode(int p_iData, CNode* leaf);

    public:

        //Constructor
        CTreeDataStructure();

        //Destructor
        ~CTreeDataStructure();

        //Get the root node
        CNode* getRootNode(){return m_pobjRootNode;}
    
        //Add Node 
        void addNode(int p_iData);

        //Recursive Preorder Traversal
        void preOrderTraversalRecursive(CNode* p_pobjNode);

        //Iterative PreOrder Traversal
        void preOrderTraversalIterative(CNode* p_pobjRootNode);

        //Free Nodes
        void freeNode(CNode* p_pobjNode);

        //Stack of Node
        std::stack<CNode*> m_stkNode;
};
//------------------------------------------------------------------------------


//------------------------------------------------------------------------------
//                              End of File
//------------------------------------------------------------------------------
