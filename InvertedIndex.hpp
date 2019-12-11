#ifndef INVERTEDINDEX_HPP
#define INVERTEDINDEX_HPP

#include "BST.hpp"
#include "IIData.hpp"

class InvertedIndex {
public: // DO NOT CHANGE THIS PART.
    InvertedIndex();
    InvertedIndex(const InvertedIndex &obj);

    ~InvertedIndex();

    BST<IIData> &getInvertedIndex();

    InvertedIndex &addDocument(const std::string &documentName);
    InvertedIndex &removeDocument(const std::string &documentName);
    InvertedIndex &searchWord(const std::string &word);
    InvertedIndex &printInvertedIndex();

    InvertedIndex &operator=(const InvertedIndex &rhs);

private: // YOU MAY ADD YOUR OWN UTILITY MEMBER FUNCTIONS HERE.
void removedoc(BSTNode<IIData> *node, const std::string &documentName) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    removedoc(node->left, documentName); 
  
    // then recur on right subtree 
    removedoc(node->right, documentName); 
  
    node->data.removeOccurrences(documentName);
} 
void removedoc(BSTNode<IIData> *node) 
{ 
    if (node == NULL) 
        return; 
  
    // first recur on left subtree 
    removedoc(node->left); 
  
    // then recur on right subtree 
    removedoc(node->right); 
  
    if(node->data.getOccurrences().empty()){
        invertedIndex.remove(node->data);
    }
} 

private: // DO NOT CHANGE THIS PART.
    BST<IIData> invertedIndex;
};

#endif //INVERTEDINDEX_HPP
