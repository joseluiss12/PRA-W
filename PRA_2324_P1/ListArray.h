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
		
		delete[] arr;
		arr = new int[new_size];
		max = new_size;
		for(int j = 0; j < max; j++){
		
			arr[j] = temp[j];
		
		}
		delete[] temp;	
	}

    public:

	ListArray(){ 
		
		arr = new T[MINSIZE];
		max = 2;
	 	n = 0;	
	}

	~ListArray(){ delete[] arr; }

	T operator[](int pos){
	
		if (pos < 0 || pos > n){ throw  std::out_of_range("Fuera de Rango"); }
	
		return arr[pos];	
	
	}

	friend std::ostream&operator<<(std::ostream &out, const ListArray<T> &list){

		out << "[ ";
		for (int i = 0; i < list.max; i++){

			out << list.arr[i];
			if (i < list.max-1){

				out << ", ";

			}

		}

		out << " ]";
		return out;

	}
	
	virtual int size() override {
		
		return n;

	}	
	
	virtual void append(T e) override { 
	
		if (size() == max) { resize(size()*2); }
		arr[n] = e;
		n++;
	
	}

        virtual void prepend(T e) override { 
        
        	if (size() == max) { resize(size()*2); }
		else { 
		
			for (int i = n; i > 0; i--){
			
				arr[i] = arr[i-1];
				
			}
		
			arr[0] = e;
			n++;
			
		}
        	
        }

	virtual void insert(int pos, T e) override {

		if (pos < 0 || pos > n){ throw  std::out_of_range("Fuera de Rango"); }
		if (size() == max) { resize(size()*2); }			
		if (pos == 0) { prepend(e); }		
		else if (pos == n) { append(e); }
		else {
						
			for (int i = n; i > pos; i--){
						
				arr[i] = arr[i-1];
						
			}
			arr[pos] = e;
			n++;
				
		}
				
	}
			
	virtual T remove(int pos) override {
		
		if (pos < 0 || pos > size()-1){ throw  std::out_of_range("Fuera de Rango"); }
		else {
		
			T temp = arr[pos];
			for (int i = pos; i < n; i++){
			
				arr[i] = arr[i+1];
				
			} 
			n--;
			return temp;
			
		}

	}

	virtual T get(int pos) override {

		if (pos < 0 || pos > size()-1){ throw  std::out_of_range("Fuera de Rango"); }

		return arr[pos];

	}

	virtual int search(T e) override {

		for (int i = 0; i < n; i ++){

			if ( arr[i] == e){

				return i;

			}
		}

		return -1;

	}

	virtual bool empty() override {

		if (n == 0){ return true; }
		else { return false; }

	}
	
	

};
