#ifndef BSTREE_H
#define BSTREE_H

#include <ostream>
#include <stdexcept>
#include "BSNode.h"

template <typename T> 
class BSTree {
    private:

        int nelements;
        BSNode<T> *root;
        BSNode<T>* search(BSNode<T>* n, T e) const{
            if(n == nullptr){
                throw std::runtime_error("Elemento no encontrado");
            }else if(e == n->element){
                return n;
            }else if(e < n->element){
                return search(n->left, e);
            }else{
                return search(n->right, e);
            }
        }

        BSNode<T>* insert(BSNode<T>* n, T e){
            if(n == nullptr){
                n = new BSNode<T>(e);
                nelements++;
            }else if(e < n->element){
                n->left = insert(n->left, e);
            }else if(e > n->element){
                n->right = insert(n->right, e);
            }else{
                throw std::runtime_error("Elemento ya existe");
            }
            return n;
        }

        void print_inorder(std::ostream &out, BSNode<T>* n) const{
            if(n != nullptr){
                print_inorder(out, n->left);
                out << n->element << " ";
                print_inorder(out, n->right);
            }
        }

        BSNode<T>* remove(BSNode<T>* n, T e){
            if(n == nullptr){
                throw std::runtime_error("Elemento no encontrado");
            }else if(e < n->element){
                n->left = remove(n->left, e);
            }else if(e > n->element){
                n->right = remove(n->right, e);
            }else{
                if(n->left == nullptr){
                    BSNode<T>* temp = n->right;
                    n->right = nullptr;
                    delete n;
                    nelements--;
                    return temp;
                }else if(n->right == nullptr){
                    BSNode<T>* temp = n->left;
                    n->left = nullptr;
                    delete n;
                    nelements--;
                    return temp;
                }else{
                    T temp = max(n->left);
                    n->element = temp;
                    n->left = remove_max(n->left);
                }
            }
            return n;
        }

        T max(BSNode<T>* n) const{
            if(n->right == nullptr){
                return n->element;
            }else{
                return max(n->right);
            }
        }

        BSNode<T>* remove_max(BSNode<T>* n){
            if(n->right == nullptr){
                BSNode<T>* temp = n->left;
                n->left = nullptr;
                delete n;
                nelements--;
                return temp;
            }else{
                n->right = remove_max(n->right);
                return n;
            }
        }

        void delete_cascade(BSNode<T>* n){
            if(n != nullptr){
                delete_cascade(n->left);
                delete_cascade(n->right);
                delete n;
            }
        }

    public:
        BSTree(){
            nelements = 0;
            root = nullptr;
        }

        int size() const{
            return nelements;
        }

        T search(T element) const{
            BSNode<T>* temp = search(root, element);
            return temp->element;
        }   

        T operator[](T e) const{
            return search(e);
        }

        void insert(T e){
            root = insert(root, e);
        }
    
        friend std::ostream& operator<<(std::ostream &out, const BSTree<T> &bst){
            bst.print_inorder(out, bst.root);
            return out;
        }

        void remove(T e){
            root = remove(root, e);
        }

        ~BSTree(){
            delete_cascade(root);
        }
};

#endif