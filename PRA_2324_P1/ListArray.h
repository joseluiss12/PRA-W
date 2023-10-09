#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:

        T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;
	void resize(int new_size){ 
		
		T* temp = new T[new_size];
		for (int i = 0; i < new_size; i++){

			temp[i] = arr[i];

		}
		
		*arr = *temp;
		max = new_size;
		delete[] temp;	
	}

    public:

	void insert(int pos, T e){

		if (pos > max || pos < 0){

			throw  std::out_of_range("Fuera de Rango");

		} else {
			
			arr[pos] = e;

		}
	}
	
	void append(T e){ arr[max-1] = e; }

        void prepend(T e){ arr[0] = e; }

	T remove(int pos){
		
		if (pos > max || pos < 0){

                        throw  std::out_of_range("Fuera de Rango");

                }

		T temp = arr[pos];
		arr[pos] = 0;
		return temp;

	}

	T get(int pos){

		if (pos > max || pos < 0){

                        throw  std::out_of_range("Fuera de Rango");

                }

		return arr[pos];

	}

	int search(T e){

		for (int pos = 0; pos < max; pos ++){

			if ( arr[pos] == e){

				return pos;

			}
		}

		return -1;

	}

	bool empty(){

		for (int i = 0; i < max; i++){

			if (arr[i] != 0){

				return false;

			}

		}

		return true;

	}

	int size(){
		
		int num;
		for (int i = 0; i < max; i++){

			if (arr[i] != 0){

				num++;

			}

		}

		return num;

	}	
	
	ListArray(){ 
		
		arr = new T[MINSIZE];
		max = 0;
	 	n = 0;	
	}

	~ListArray(){ delete[] arr; }

	T operator[](int pos){
	
		if (pos > max || pos < 0){
	
			throw  std::out_of_range("Fuera de Rango");
	
		}
	
		return arr[pos];	
	
	}

	friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list){

		out << "[ ";
		for (int i = 0; i < max; i++){

			out << list[i];
			if (i < max-1){

				out << ", ";

			}

		}

		out << " ]";
		return out;

	}

};
