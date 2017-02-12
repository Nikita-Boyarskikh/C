#include <iostream>
#include <signal.h>


using namespace std;

#define MAX_CONNECTIONS 10
#define HOST "localhost"
#define PORT 80
#define MAX_SESSIONS_PER_CLIENT 8
// #define MAX_FORKS 2
#define MAX_QUEUE_SIZE 128
// #define ...

int main(int argc, char **argv) {
    Server server = new Server(HOST, PORT, MAX_CONNECTIONS);
    while(server.listen()) {
        server.client.connection.accept();
         
