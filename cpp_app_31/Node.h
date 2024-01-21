#ifndef Node_h
#define Node_h

#include <iostream>
#include <string>

class Node {
public:
    int number;
    std::string offense;
    std::string penaltiesDeleted;
    Node* left;
    Node* right;

    Node(int num, const std::string& off) : number(num), offense(off), left(nullptr), right(nullptr) {}
};

#endif

