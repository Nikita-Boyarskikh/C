#include <iostream>

class A;

class B{
  private:
    friend A;
    int num;

  public:
    B(int n);
    B();
    int get_num();
};

class A{
  private:
    int arr[100];

  public:
    int operator[] (B &index);
    A();
};

int main() {
A x;
B y;
std::cout<<x[y]<<std::endl;
return 0;
}

// A methods, operators & constructors

int A::operator[] (B &index) {
  return this->arr[index.num];
}

A::A() {
  for(int i = 0; i < 100; i++) arr[i] = i;
}

// B methods, operators & constructors
#if __cplusplus >= 199711
B::B() : B(0) {}
#else // __cplusplus >= 199711
B::B() {
  this->num = 0;
}
#endif // __cplusplus >= 199711
B::B(int n = 0) {
  this->num = n;
}

int B::get_num() {
  return this->num;
}
