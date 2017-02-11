#include <iostream>
#include <string>

using namespace std;

#include "libList.h"

int main(int argc, char const *argv[])
{
	char arr[] = {'f', 'a', 'a', '0', 'd', 'w', '$', '"', '\\'};
	List<char> list1(arr, sizeof(arr) / sizeof(*arr));
	list1.print();
	cout<<"--------------------\n";
	List<char> list2(list1);
	list2.print("|");
	cout<<"--------------------\n";
	List<int> list3 = 1;
	list3.print();
	// list3 = 0;
	cout<<"--------------------\n";
	List<int> list4;
	list4.print();
	cout<<"--------------------\n";
	// List<char> list(list1.to_arr());
	// list.print();
	cout<<"--------------------\n";
	// list = list3;
	// list.print();
	return 0;
}
