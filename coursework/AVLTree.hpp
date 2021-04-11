#ifndef AVLTree_HPP
#define AVLTree_HPP

#include "List.hpp"
#include "Exceptions.hpp"
#include <iostream>
#include <string>
#include <stdexcept>

class AVLTree
{
public:
    AVLTree(): head_(nullptr) {}
    ~AVLTree();
    void add(std::string);
    void remove(const std::string&);
    void print(std::ostream&);
    bool search(const std::string&) const;
private:
    struct Node
    {
        Node* right_;
        Node* left_;
        Node* parent_;
        std::string key_;
        List data_;
        unsigned char height_;
        Node(std::string word, List& data)
        {
            if (!isEnglish(word))
            {
                throw SyntaxError(word);
            }
            right_ = left_ = parent_ = nullptr;
            key_ = word;
            data_ = data;
            height_ = 0;
        }
    };
    Node* head_;
    Node* balance(Node*);
    Node* rotateLeft(Node*);
    Node* rotateRight(Node*);
    Node* searchNode(const std::string&) const;
    Node* getSuccessor(Node*, Node* node = nullptr);
    void removeNode(Node*);
    static int bFactor(Node*) ;
    static int getHeight(Node*) ;
    static bool isEnglish(const std::string&);
    static bool isRussian(const char);
    Node* addNode(const std::string&, List &, Node *&, Node *);
    void printNode(std::ostream &, Node *);
    void removeRecursive(Node *);
};
#endif