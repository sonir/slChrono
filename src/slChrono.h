#pragma once

#include <iostream>
#include <sys/time.h>

typedef struct timeval timeval;
typedef double chrono_t; //Converted timeval to double for calc


class slChrono {
    
public:
    slChrono();
    void setup();
    
    void updateNow();
    chrono_t getTime();
    void getTime(timeval *t);
    void getTime(chrono_t *ct);
    void setStartTime();
    void setStartTime(timeval *t);
    chrono_t elapsed();
    chrono_t elapsed(chrono_t t1,chrono_t t2);
    chrono_t elapsed_ms();
    
    chrono_t st_time, now;
    
private:
    chrono_t convertToChrono(timeval *t);
    timeval tv;
    double sec ,usec, total;
    
    
};
