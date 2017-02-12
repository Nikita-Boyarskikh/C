#include <iostream>

using namespace std;

int main(int argc, char **argv) {

    char str[255];
    cout<<"Введите строку для проверки баланса скобок: "<<endl;
    cin>>str;

    bool find = false, done = false;
    char *open_p = NULL, *close_p = NULL;
    int checker = 0;
    int counter = 0;
    for(int i=0; str[i] != '\0'; i++) {
        switch(str[i]) {
          case '(':
            counter++;
            checker++;
            if(!find && counter == 2) {
                open_p = str + i;
                find = true;
                counter = 0;
            }
            break;
          case ')':
            if(!done && find && counter == 0) {
                close_p = str + i;
                done = true;
            }
            if(find) counter--;
            checker--;
        }
        if(checker < 0) break;
    }

    if(checker != 0)
        cout<<"ОШИБКА: Скобки НЕ сбалансированы!"<<endl;
    else {
        cout<<"Скобки сбалансированы."<<endl;
        if(open_p && close_p && open_p < close_p) {
            cout<<"Между 2-ой парой скобок находится следующее: \"";
            for(char *i = open_p + 1; i < close_p; i++) cout<<*i;
            cout<<'\"'<<endl;
        }
    }

    return 0;
}
