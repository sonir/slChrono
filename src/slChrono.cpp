#include "slChrono.h"

slChrono::slChrono(){
    
    st_time = -1;
    
}

void slChrono::setup(){
    
    setStartTime();
    
}


void slChrono::getTime(timeval *t){
    
    gettimeofday(t, NULL);
    
}

void slChrono::getTime(chrono_t *ct){
    
    timeval t;
    getTime(&t);
    *ct = convertToChrono(&t);
    
}

chrono_t slChrono::getTime(){
    
    updateNow();
    return now;
    
}


void slChrono::updateNow(){
    
    timeval t;
    getTime(&t);
    now = convertToChrono(&t);
    
}

void slChrono::setStartTime(){
    
    getTime(&tv);
    st_time = convertToChrono(&tv);
    
}

void slChrono::setStartTime(timeval *t){ //Set StartTime to specified time
    
    st_time = convertToChrono(t);
    
}

chrono_t slChrono::elapsed(){
    
    getTime();
    return (now - st_time);
    
}

chrono_t slChrono::elapsed(chrono_t t1,chrono_t t2){
    
    //Elapsed is usec
    return t2 - t1;
    
}

chrono_t slChrono::convertToChrono(timeval *t){
    getTime(t);
    sec = t->tv_sec; usec = t->tv_usec;
    total = (sec*1000000)+usec;
    return (chrono_t)total;
    
}

