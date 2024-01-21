#include "Traffic.h"
#include <iostream>

Traffic::Traffic() : root(nullptr) {}

void Traffic::addReceipt(int number, const std::string& offense) {
    addReceipt(root, number, offense);
}

void Traffic::addReceipt(Node*& node, int number, const std::string& offense) {
    if (node == nullptr) {
        node = new Node(number, offense);
    }
    else if (number < node->number) {
        addReceipt(node->left, number, offense);
    }
    else if (number > node->number) {
        addReceipt(node->right, number, offense);
    }
    else {
        node->offense += "; " + offense;
    }
}

void Traffic::deleteReceipt(int number) {
    deleteReceipt(root, number);
}

void Traffic::deletePenalty(int number, const std::string& penaltyToDelete) {
    deletePenalty(root, number, penaltyToDelete);
}

void Traffic::deletePenalty(Node*& node, int number, const std::string& penaltyToDelete) {
    if (node != nullptr) {
        if (number < node->number) {
            deletePenalty(node->left, number, penaltyToDelete);
        }
        else if (number > node->number) {
            deletePenalty(node->right, number, penaltyToDelete);
        }
        else {
            size_t found = node->offense.find(penaltyToDelete);
            if (found != std::string::npos) {
                node->offense.erase(found, penaltyToDelete.length());

                if (!node->penaltiesDeleted.empty()) {
                    node->penaltiesDeleted += "; ";
                }

                node->penaltiesDeleted += penaltyToDelete;

                std::cout << "Penalty deleted successfully." << std::endl;
            }
            else {
                std::cout << "Penalty not found in the receipt." << std::endl;
            }
        }
    }
    else {
        std::cout << "Receipt not found." << std::endl;
    }
}

void Traffic::deleteReceipt(Node*& node, int number) {
    if (node == nullptr) {
        std::cout << "Receipt not found." << std::endl;
    }
    else if (number < node->number) {
        deleteReceipt(node->left, number);
    }
    else if (number > node->number) {
        deleteReceipt(node->right, number);
    }
    else {
        deleteNode(node);
    }
}

void Traffic::deleteNode(Node*& node) {
    if (node->left == nullptr) {
        Node* temp = node->right;
        delete node;
        node = temp;
    }
    else if (node->right == nullptr) {
        Node* temp = node->left;
        delete node;
        node = temp;
    }
    else {
        Node* successor = node->right;
        while (successor->left != nullptr) {
            successor = successor->left;
        }
        node->number = successor->number;
        node->offense = successor->offense;
        deleteReceipt(node->right, successor->number);
    }
}

void Traffic::addPenalty(Node*& node, int number, const std::string& newOffense) {
    if (node != nullptr) {
        if (number < node->number) {
            addPenalty(node->left, number, newOffense);
        }
        else if (number > node->number) {
            addPenalty(node->right, number, newOffense);
        }
        else {
            node->offense += "; " + newOffense;
        }
    }
    else {
        std::cout << "Receipt not found. Creating a new receipt with the penalty." << std::endl;
        createReceipt(root, number, newOffense);
    }
}

void Traffic::createReceipt(Node*& node, int number, const std::string& offense) {
    if (node == nullptr) {
        node = new Node(number, offense);
    }
    else if (number < node->number) {
        createReceipt(node->left, number, offense);
    }
    else if (number > node->number) {
        createReceipt(node->right, number, offense);
    }
    else {
        std::cout << "Receipt number already exists. Cannot create a new receipt." << std::endl;
    }
}

void Traffic::addPenalty(int number, const std::string& newOffense) {
    addPenalty(root, number, newOffense);
}

void Traffic::printFullDatabase() {
    printFullDatabase(root);
    std::cout << std::endl;
}

void Traffic::printFullDatabase(Node* node) {
    if (node != nullptr) {
        printFullDatabase(node->left);
        std::cout << "Number: " << node->number << ", Offenses: " << node->offense;
        if (!node->penaltiesDeleted.empty()) {
            std::cout << ", Deleted Penalties: " << node->penaltiesDeleted;
        }
        std::cout << std::endl;
        printFullDatabase(node->right);
    }
}

void Traffic::printDataForNumber(int searchNumber) {
    printDataForNumber(root, searchNumber);
}

void Traffic::printDataForNumber(Node* node, int searchNumber) {
    if (node != nullptr) {
        if (searchNumber < node->number) {
            printDataForNumber(node->left, searchNumber);
        }
        else if (searchNumber > node->number) {
            printDataForNumber(node->right, searchNumber);
        }
        else {
            std::cout << "Number: " << node->number << ", Offenses: " << node->offense;
            if (!node->penaltiesDeleted.empty()) {
                std::cout << ", Deleted Penalties: " << node->penaltiesDeleted;
            }
            std::cout << std::endl;
        }
    }
    else {
        std::cout << "Number not found." << std::endl;
    }
}

void Traffic::printDataInRange(int startRange, int endRange) {
    printDataInRange(root, startRange, endRange);
}

void Traffic::printDataInRange(Node* node, int startRange, int endRange) {
    if (node != nullptr) {
        if (startRange < node->number) {
            printDataInRange(node->left, startRange, endRange);
        }
        if (startRange <= node->number && endRange >= node->number) {
            std::cout << "Number: " << node->number << ", Offenses: " << node->offense;
            if (!node->penaltiesDeleted.empty()) {
                std::cout << ", Deleted Penalties: " << node->penaltiesDeleted;
            }
            std::cout << std::endl;
        }
        if (endRange > node->number) {
            printDataInRange(node->right, startRange, endRange);
        }
    }
}

void Traffic::deleteTree(Node*& node) {
    if (node != nullptr) {
        deleteTree(node->left);
        deleteTree(node->right);
        delete node;
    }
}

Traffic::~Traffic() {
    deleteTree(root);
}
