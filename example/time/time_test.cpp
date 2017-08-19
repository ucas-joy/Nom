#include<Nom/Timer.h>
#include<stdio.h>
#include<sys/timerfd.h>
#include<boost/bind.hpp>

int timerfd;

void timeout()
{
    printf("timeout!\n");
    int howmany;
    ::read(timerfd , &howmany , sizeof howmany);
}

int main()
{
    Timer T;
    T.setTimer(1,1);
    T.setTimerCallback(timeout);
    T.runTimer();
    T.cancelTimer();
    return 0;
}