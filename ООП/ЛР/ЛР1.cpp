#include <iostream>

using namespace std;

#define MAX 5000000

bool isPalindrome(int a) {
    int temp = 0, copy = a;
    while(copy != 0) {
        temp = temp*10 + copy%10;
        copy /= 10;
    }
    return temp == a;
}

int main(int argc, char **argv) {

    cout<<"Первые "<<MAX<<" палиндромов:"<<endl;
    for(int i=0; i<MAX; i++)
        if(isPalindrome(i))
            cout<<i<<endl;

    return 0;
}

