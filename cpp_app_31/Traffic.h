#ifndef Traffic_h
#define Traffic_h

#include <iostream>
#include <string>
#include "Node.h"

class Traffic {
private:
    Node* root;

    void addReceipt(Node*& node, int number, const std::string& offense);
    void deleteReceipt(Node*& node, int number);
    void deleteNode(Node*& node);
    void addPenalty(Node*& node, int number, const std::string& newOffense);
    void createReceipt(Node*& node, int number, const std::string& offense);
    void deletePenalty(Node*& node, int number, const std::string& penaltyToDelete);
    void printFullDatabase(Node* node);
    void printDataForNumber(Node* node, int searchNumber);
    void printDataInRange(Node* node, int startRange, int endRange);
    void deleteTree(Node*& node);

public:
    Traffic();
    void addReceipt(int number, const std::string& offense);
    void deleteReceipt(int number);
    void addPenalty(int number, const std::string& newOffense);
    void deletePenalty(int number, const std::string& penaltyToDelete);
    void printFullDatabase();
    void printDataForNumber(int searchNumber);
    void printDataInRange(int startRange, int endRange);
    ~Traffic();
};

#endif
