#ifndef BIGINT
#define BIGINT

#include <sstream>
#include <string>
#include <iostream>

class bigint
{
    private:
        std::string str;
    public:
        bigint();
        bigint(unsigned int num);
        bigint(const bigint& source);

        std::string getStr() const;

        bigint& operator=(const bigint& source);

        bigint operator+(const bigint& other) const;
        bigint& operator+=(const bigint& other);

        
}

#endif