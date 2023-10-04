#include <ostream>
#include "List.h"

template <typename T> 
class ListArray : public List<T> {

    private:
        T* arr;
	int max;
	int n;
	static const int MINSIZE = 2;

    public:
        ListArray();
	~ListArray();
	T operator[](int pos){
		if (pos > max){
			throw  std::out_of_range;
		}
	return arr[pos];	
    
};
