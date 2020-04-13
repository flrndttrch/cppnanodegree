#include "graphedge.h"
#include "graphnode.h"
#include <iostream>

GraphNode::GraphNode(int id)
{
    _id = id;
}

GraphNode::~GraphNode()
{
    //// STUDENT CODE
    ////
    std::cout << "Deleting Chatbot from GraphNode: " << std::to_string(_id) << "\n"; 
    

    ////
    //// EOF STUDENT CODE
}

void GraphNode::AddToken(std::string token)
{
    _answers.push_back(token);
}

void GraphNode::AddEdgeToParentNode(GraphEdge *edge)
{
    _parentEdges.push_back(edge);
}

void GraphNode::AddEdgeToChildNode(std::unique_ptr<GraphEdge> edge)
{
    _childEdges.push_back(std::move(edge));
}

//// STUDENT CODE
////
void GraphNode::MoveChatbotHere(ChatBot chatbot)
{
  	std::cout << "Move chatbot to new node\n";
    _chatBot = std::move(chatbot);
    _chatBot.SetCurrentNode(this);
    _chatBot.GetChatLogicHandle()->SetChatbotHandle(&_chatBot);
  	std::cout << "Move chatbot to new node done\n";
}

void GraphNode::MoveChatbotToNewNode(GraphNode *newNode)
{
  	std::cout << "Move initiated\n";
    newNode->MoveChatbotHere(std::move(_chatBot));
    //_chatBot = nullptr; // invalidate pointer at source
}
////
//// EOF STUDENT CODE

GraphEdge *GraphNode::GetChildEdgeAtIndex(int index)
{
    //// STUDENT CODE
    ////

    return _childEdges[index].get();

    ////
    //// EOF STUDENT CODE
}