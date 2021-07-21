//
// Created by xieyuschen on 2021/7/21.
//
#include "pthread.h"
#ifndef RWLOCK_PTHREAD_RWLOCK_H
#define RWLOCK_PTHREAD_RWLOCK_H
typedef struct{
    //if you want to examine or manipulate this struct,you need to hole rw_mutex
    pthread_mutex_t rw_mutex;
    pthread_cond_t  rw_condreaders;
    pthread_cond_t  rw_condwriters;
    int rw_magic;
    int rw_nwaitreaders;
    int rw_nwaitwriters;
    int rw_refcount;
}pthread_rwlock_t ;
#define RW_MAGIC 0x19283746;
#define PTHREAD_RWLOCK_INITIALIZER { PTHREAD_MUTEX_INITIALIZER, \
    PTHREAD_COND_INITIALIZER,PTHREAD_COND_INITIALIZER         \
    RW_MAGIC,0,0,0}
typedef int pthread_rwlocattr_t;
int pthread_rwlock_destory(pthread_rwlock_t*);
int pthread_rwlock_init(pthread_rwlock_t*,pthread_rwlockattr_t*);
int pthread_rwlock_rdlock(pthread_rwlock_t*);
int pthread_rwlock_tryrdlock(pthread_rwlock_t*);
int pthread_rwlock_trywrlock(pthread_rwlock_t*);
int pthread_rwlock_unlock(pthread_rwlock_t*);
int pthread_rwlock_wrlock(pthread_rwlock_t*);

//Wrapper functions
void Pthread_rwlock_destory(pthread_rwlock_t*);
void Pthread_rwlock_init(pthread_rwlock_t*);
void Pthread_rwlock_rdlock(pthread_rwlock_t*);
void Pthread_rwlock_tryrdlock(pthread_rwlock_t*);
void Pthread_rwlock_trywrlock(pthread_rwlock_t*);
void Pthread_rwlock_unlock(pthread_rwlock_t*);
void Pthread_rwlock_wrlock(pthread_rwlock_t*);
#endif //RWLOCK_PTHREAD_RWLOCK_H
