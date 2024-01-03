#ifndef HASHTABLE_H
#define HASHTABLE_H

#include <ostream>
#include <stdexcept>
#include "Dict.h"
#include "TableEntry.h"

#include "../PRA_2324_P1/ListLinked.h" 

template <typename V>
class HashTable: public Dict<V> {

	private:
    		
		int n;
		int max;
		ListLinked<TableEntry<V>> *table;

		int h(std::string key){

			int val = 0;
			int index;
			for(int i = 0; i < sizeof(key); i++)
				val += key[i];
			index = val % max;
			return index; 
		}
	
	public:
        
		HashTable(int size){

			table = new ListLinked<TableEntry<V>>[size];
			n = 0;
			max = size;
		}

		~HashTable(){

			delete[] table;

		}

		int capacity(){

			return max;

		}

		friend std::ostream&operator<<(std::ostream &out, const HashTable<V> &th){

			out << "***Hash Table***\n";
			for(int i = 0; i < th.max; i++){

				out << i << ": ";
				int tam = th.table[i].size();
				for(int j = 0; j < tam; j++)
					out << th.table[i].get(j);

				out << std::endl;

			}
			return out;
		}

		V operator[](std::string key){

			int index = h(key);
			int pos = table[index].search(key);
			if(pos == -1)
				throw std::runtime_error("Key not found");
			return table[index].get(pos).value;
		}

		void insert(std::string key, V value) override{
    
			int index = h(key);
    		int pos = table[index].search(key);
			if(pos != -1)
				throw std::runtime_error("Key already exists");
			TableEntry<V> temp = TableEntry<V>(key, value);
			table[index].prepend(temp);
			n++;
		}		

		V search(std::string key) override{
			
			int index = h(key);
			int pos = table[index].search(key);
			if(pos == -1)
				throw std::runtime_error("Key not found");
			return table[index].get(pos).value;

		}

		V remove(std::string key) override{

			int index = h(key);
			int pos = table[index].search(key);
			if(pos < 0 || pos > max)
				throw std::runtime_error("Key not found");
			n--;
			return table[index].remove(pos).value;
		}

		int entries() override{

			return n;
		}

        
};

#endif
