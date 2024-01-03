#ifndef BSNODE_H
#define BSNODE_H

#include <ostream>

template <typename T> 
class BSNode {
    public:
        T element;
        BSNode<T> *left;
        BSNode<T> *right;

        BSNode(T element, BSNode<T>* left=nullptr, BSNode<T>* right=nullptr){            
            this->element = element;
            this->left = left;
            this->right = right;
        }

        ~BSNode() {
            delete left;
            delete right;
        }

        friend std::ostream& operator<<(std::ostream &out, const BSNode<T> &node) {
            out << node.element;
            return out;
        }       
};

#endif