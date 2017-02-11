#ifndef LIST
#define LIST
#include <string>

// Memory size to allocate
#define SCALE 8

// Linked list
template <class T>
class List {
	private:
		struct elem	{
			elem *next;
			elem *pref;
			T data;
		};

		int _size;
		elem *last;
		elem *first;

		// Cache of most recent elements
		//List *cashe;

		// Local functions
		List &recreate(const T* const arr, size_t size);
		void init(const T* const arr, size_t size);
		
	public:
		// Constuctors
		List(const T* const arr, size_t size);
		List(const List<T> &list);
		List(int size);
		List();

		// Methods
		const T* const to_arr() const;
		void print(std::string det = " ") const;
		const int size() const;
		const int length() const;

		// Operators
		List &operator=(const List &l);
		List &operator=(const T scalar);

		// Destructor
		~List();
};

#include "_libList.h"
#endif // LIST