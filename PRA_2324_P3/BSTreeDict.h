#ifndef BSTREEDICT_H
#define BSTREEDICT_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "BSTree.h"
#include "TableEntry.h"

template <typename V>
class BSTreeDict: public Dict<V> {

    private:
        BSTreeDict<TableEntry<V>>* tree; 

    public:
        BSTreeDict(){
            tree = new BSTreeDict<TableEntry<V>>();
        }

        ~BSTreeDict(){
            delete tree;
        }

        V search(std::string key) override{
            return tree->search(key);
        }

        V remove(std::string key) override{
            return tree->remove(key);
        }

        void insert(std::string key, V value) override{
            return tree->insert(key, value);
        }

        int entries() override{
            return tree->size();
        }

        friend std::ostream& operator<<(std::ostream &out, const BSTreeDict<V> &bs){
            out << *bs.tree;
            return out;
        }

        V operator[](std::string key){
            return tree->search(key);
        }

        
};

#endif