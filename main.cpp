//complining command
//c++ .\main.cpp -o boop -lpthread -fpermissive

#include <windows.h>
#include <iostream>
#include <pthread.h>
//#include <unistd.h>

struct beep_arg {
    int hertz;
    int time;
};

void *beep(void *args) {
    struct beep_arg *a = args;
    Beep(a->hertz,a->time);
    pthread_exit(NULL);
    return 0;
}

int main() {

    struct beep_arg args = {600,800};

    pthread_t t0;
    pthread_create(&t0, NULL, beep, (void *)&args);
    
    Beep(400,400);
    
    pthread_join(t0, NULL);
    return 0;
}