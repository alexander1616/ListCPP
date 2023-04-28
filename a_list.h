#ifndef a_list_h
#define a_list_h1
#include <iostream>

class a_list_t{
public:
    a_list_t(); //constructor
    ~a_list_t(); //destructor

    a_list_t& operator = (const a_list_t&);
    a_list_t(const a_list_t&);
	friend std::ostream& operator<<(std::ostream& os, const a_list_t&);
    int operator [] (int);
	
public:
    void 		add(int);
    void 		deleteIndex(int);
    int 		count(){
        return data_count;
    };
    int     	pop();
    void	    sort_ascending();
	void    	sort_descending();

private:
    int 		data_count;
    int 		*data_pool;
    int 		data_max;
    int         data_start;
    int         data_end;
    void 		reallocPool();
};
#endif
