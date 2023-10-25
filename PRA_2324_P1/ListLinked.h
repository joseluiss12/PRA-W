#include <ostream>
#include "List.h"
#include "Node.h"

template <typename T>
class ListLinked : public List<T> {

	private:
	
		Node<T>* first;
		int n;
		
	public:
	
		void insert(int pos, T e){

			if (pos > size()-1 || pos < 0){

				throw  std::out_of_range("Fuera de Rango");

			} else {
				
				arr[pos] = e;

			}
		}
		
		void append(T e){ arr[max-1] = e; }

		void prepend(T e){ arr[0] = e; }

		T remove(int pos){
			
			if (pos > size()-1 || pos < 0){

		                throw  std::out_of_range("Fuera de Rango");

		        }

			T temp = arr[pos];
			arr[pos] = 0;
			return temp;

		}

		T get(int pos){

			if (pos > size()-1 || pos < 0){

		                throw  std::out_of_range("Fuera de Rango");

		        }

			return arr[pos];

		}

		int search(T e){

			for (int pos = 0; pos < size()-1; pos ++){

				if ( arr[pos] == e){

					return pos;

				}
			}

			return -1;

		}

		bool empty(){

			for (int i = 0; i < size()-1; i++){

				if (arr[i] != 0){

					return false;

				}

			}

			return true;

		}

		int size(){
			
			int num;
			for (int i = 0; i < size()-1; i++){

				if (arr[i] != 0){

					num++;

				}

			}

			return num;

		}	
		
		ListLinked(){
		
			first = nullptr;
			n = 0;
			
		}
		
		~ListLinked(){
			
			while( aux != nullptr){
			
				Node<T> aux = first->next;
				delete[] first;
				first = aux;
			
			}
		}
		
		T operator[](int pos){
		
			if (pos > size()-1 || pos < 0){
	
				throw  std::out_of_range("Fuera de Rango");
	
			}
			
			for (int i = 0; i < pos; i++){
			
				Node<T> aux = first->next;
				first = aux;
				
			}
			
			return n;
			
		}
		
		friend std::ostream&operator<<(std::oestream &out, const ListLinked<T> &list){
		
			out << "[ ";
				
				while (list.first != nullptr){ 

					out << list.n;
					if (list.first->next != nullptr){

						out << ", ";

					}

				}

			out << " ]";
			return out;

		}
