#ifndef CHATBOT_H_
#define CHATBOT_H_

#include <wx/bitmap.h>
#include <string>
#include <iostream>

#include "chatlogic.h"

class GraphNode; // forward declaration
class ChatLogic; // forward declaration

class ChatBot
{
private:
    // data handles (owned)
    wxBitmap *_image; // avatar image

    // data handles (not owned)
    GraphNode *_currentNode;
    GraphNode *_rootNode;
    ChatLogic *_chatLogic;

    // proprietary functions
    int ComputeLevenshteinDistance(std::string s1, std::string s2);

public:
    // constructors / destructors
    ChatBot();                     // constructor WITHOUT memory allocation
    ChatBot(std::string filename); // constructor WITH memory allocation
    ~ChatBot();

    //// STUDENT CODE
    ////
	ChatBot(const ChatBot &other);
    ChatBot(ChatBot &&other);
    ChatBot &operator=(const ChatBot &other) {
    	std::cout << "ChatBot Copy Assignment Operator" << std::endl;
    	if (this == &other)
            return *this;
        delete _image;
        _image = new wxBitmap();
        *_image = *other._image;
        _currentNode = other._currentNode;
        _chatLogic = other._chatLogic;
        _chatLogic->SetChatbotHandle(this);
        return *this;
    }
    ChatBot &operator=(ChatBot &&other) {
    	std::cout << "ChatBot Move Assignment Operator" << std::endl;
    	if (this == &other)
            return *this;
        delete _image;
        _image = other._image;
        _currentNode = other._currentNode;
        _chatLogic = other._chatLogic;
        _chatLogic->SetChatbotHandle(this);
        other._image = nullptr;
        other._currentNode = nullptr;
        other._chatLogic = nullptr;
        return *this;
    }
    ////
    //// EOF STUDENT CODE

    // getters / setters
    void SetCurrentNode(GraphNode *node);
    void SetRootNode(GraphNode *rootNode) { _rootNode = rootNode; }
    void SetChatLogicHandle(ChatLogic *chatLogic) { _chatLogic = chatLogic; }
    wxBitmap *GetImageHandle() { return _image; }

    // communication
    void ReceiveMessageFromUser(std::string message);
};

#endif /* CHATBOT_H_ */