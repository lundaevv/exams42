#pragma once

#include "searchable_bag.hpp"


class set
{
    private:
        searchable_bag& bag;

        set();
        set(const set& source);
        set& operator=(const set& source);
    public:
        set(searchable_bag& s_bag);

        searchable_bag& get_bag() const;

        bool has(int) const;

        void insert(int);
	    void insert(int *, int);
	    void print() const;
	    void clear();
        ~set();
};