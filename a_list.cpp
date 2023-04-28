#include <iostream>
#include <cstdlib>
#include "a_list.h"

//constructor
a_list_t::a_list_t(){
    data_count = 0;
    data_max = 0;
    data_pool = 0;
    reallocPool();
    data_start = 0;
    data_end = 0;
}

void a_list_t::reallocPool(){
    int *newDataPool;
    int incrSize = 5;
    newDataPool = new int[data_max + incrSize];
    if (data_count){
        int i;
        for (i = 0; i < data_count; i++){
            newDataPool[i] = data_pool[i];
        }        
        delete [] data_pool;
    }
    data_pool = newDataPool;
    data_max += incrSize;
}

//destructor
a_list_t::~a_list_t(){
    if (data_pool){
        delete [] data_pool;
        data_pool = 0;
    }
}

//copy constructor
a_list_t::a_list_t(const a_list_t& p){
	data_count = 0;
	data_max = 0;
	reallocPool();
	int i;
	for (i = p.data_start; i < p.data_end; i++){
		add(p.data_pool[i]);
	}
}

//assignment operator
a_list_t& a_list_t::operator = (const a_list_t& p){
    if (data_pool){
	    delete [] data_pool;
        data_pool = 0;
    }
	data_count = 0;
	data_max = 0;
    reallocPool();
	int i;
	for (i = p.data_start; i < p.data_end; i++){
		add(p.data_pool[i]);
	}
	return *this;
}

int a_list_t::operator [] (int idx){
	if (idx < 0 || idx > data_count){
		throw std::invalid_argument("bad idx");
	}
	return data_pool[data_start + idx];
}

void a_list_t::add(int x){
    if (data_end >= data_max){
        reallocPool();
    }
    data_pool[data_end++] = x;
    data_count++;
}

void a_list_t::deleteIndex(int idx){
    if (idx < 0 || idx > data_count){
        return;
    }
    for (; idx < data_count-1; idx++){
        data_pool[data_start + idx] = data_pool[data_start + idx + 1];
    }
    data_end--;
    data_count--;
}

int a_list_t::pop(){
    int val = data_pool[data_start];
    data_start++;
    return val;
}

static int cmpAscending(const void * a, const void * b){
    return ( *(int*)a - *(int*)b);
}

static int cmpDescending(const void * a, const void * b){
    return ( *(int*)b - *(int*)a);
}

void a_list_t::sort_ascending(){
    qsort(data_pool + data_start, data_count, sizeof(int), cmpAscending);
}

void a_list_t::sort_descending(){
    qsort(data_pool + data_start, data_count, sizeof(int), cmpDescending);
}

//friend
std::ostream& operator << (std::ostream& os, const a_list_t& p){
    int i;
    for (i = 0; i < p.data_count; i++){
        os << p.data_pool[p.data_start + i] << ' ';
    } 
    return os;
}