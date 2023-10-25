#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

	private:
	
		Node<T>* first;
		int n;
		
	public:
	
		ListLinked(){
		
			first = nullptr;
			n = 0;
			
		}
		
		~ListLinked(){
			
			while(first != nullptr){
			
				Node<T>* temp = first->next;
				delete[] first;
				first = temp;
			
			}
		}
		
		T operator[](int pos){
		
			if (pos < 0 || pos > n){ throw  std::out_of_range("Fuera de Rango"); }
			Node<T>* temp = first->next;
			for (int i = 1; i < pos; i++){ temp = temp->next; }
			
			return temp->data;
			
		}
		
		friend std::ostream&operator<<(std::ostream &out, const ListLinked<T> &list){
		
			out << "[ ";
			Node<T>* temp = list.first;
			while (temp != nullptr){ 

				out << temp->data;
				if (temp->next != nullptr){ out << ", "; }
				
				temp = temp->next;
				
			}

			out << " ]";
			return out;

		}
		
		
		virtual int size() override {
			
			return n;

		}	
		
		virtual void append(T e) override { 
		
			if (first == nullptr) { prepend(e); }
			else {
			
				Node<T>* pos = first;
				for (int i = 1; i < size(); i++){
				
					pos = pos->next;
					
				}
				Node<T> *temp = new Node<T>(e, pos->next);
				pos->next = temp;
				
			}
			n++;
		
		}

		virtual void prepend(T e) override { 
		
			Node<T>* temp = new Node<T>(e, first);
			first = temp;
			n++;
			
		}

		virtual void insert(int pos, T e) override {

			if (pos < 0 || pos > n){ throw  std::out_of_range("Fuera de Rango"); }			
			if (pos == 0) { prepend(e); }		
			else if (pos == n) { append(e); }
			else {
							
				Node<T>* pos = first;
				for (int i = 1; i < size(); i++){ pos = pos->next; }
				Node<T> *temp = new Node<T>(e, pos->next);
				pos->next = temp;
				n++;
					
			}
					
		}
				
		virtual T remove(int pos) override {
			
			Node<T>* temp = first;
			Node<T>* rem;
			int supr; 
			if (pos < 0 || pos > size()-1){ throw  std::out_of_range("Fuera de Rango"); }				
			if (pos == 0){
			
				rem = temp;
				first = temp->next;
				supr = rem->data;
				
			} else {
				
				for (int i = 0; i < pos; i++){ temp = temp->next; }
					
				rem = temp->next;
				supr = rem->data;
				temp->next = rem->next;
					
			}
			n--;
			delete[] rem;
			return supr;
		}

		virtual T get(int pos) override {

			if (pos < 0 || pos > size()-1){ throw  std::out_of_range("Fuera de Rango"); }

			Node<T>* temp = first;
			for (int i = 0; i < pos; i++){ temp = temp->next; }
			return temp->data;

		}

		virtual int search(T e) override {
			
			Node<T>* temp = first;
			for (int i = 0; i < n; i++){

				if ( temp->data == e){ return i; }
				temp = temp->next;
				
			}

			return -1;

		}
		
		virtual bool empty() override {

		if (n == 0){ return true; }
		else { return false; }

		}	

};
