#include "bigint.hpp"
#include <cstddef>
#include <sstream>

bigint::bigint()
{
    this->str = "0";
}

bigint::bigint(unsigned int n)
{
    std::stringstream ss;
    ss << n;
    this->str = ss.str();
}

bigint::bigint(const bigint& source)
{
    this->str = source.str;
}

bigint& bigint::operator=(const bigint& source)
{
    this->str = source.str;
    return *this;
}

std::string bigint::getStr() const
{
    return this->str;
}

std::string reverse(const std::string& str)
{
    std::string revStr;
    for (size_t i = str.length(); i > 0; i--)
        revStr.push_back(str[i - 1]);
    return revStr;
}

std::string addition(const bigint& obj1, const bigint& obj2)
{
    std::string str1 = reverse(obj1.getStr());
    std::string str2 = reverse(obj2.getStr());
    std::string result;

    size_t len1 = str1.length();
    size_t len2 = str2.length();

    if (len1 > len2)
    {
        int diff = len1 - len2;
        while (diff > 0)
        {
            str2.push_back('0');
            diff--;
        }
    }
    if (len2 > len1)
    {
        int diff = len2 - len1;
        while (diff > 0)
        {
            str1.push_back('0');
            diff--;
        }
    }
    int digit1;
    int digit2;
    int carry = 0;
    size_t len = str1.length();
    for (size_t i = 0; i < len; i++)
    {
        digit1 = str1[i] - '0';
        digit2 = str2[i] - '0';
        int res = digit1 + digit2 + carry;
        if (res > 9)
        {
            carry = res / 10;
            result.push_back(res % 10 + '0');
        }
        else {
            result.push_back(res + '0');
        }
    }
    if (carry != 0)
        result.push_back(carry + '0');
    return reverse(result);
}

bigint bigint::operator+(const bigint& other) const
{
    bigint temp = *this;
    temp.str = addition(*this, other);
    return temp;
}

bigint& bigint::operator+=(const bigint& other)
{
    *this = *this + other;
    return *this;
}

bigint& bigint::operator++()
{
    *this = *this + bigint(1);
    return *this;
}

bigint bigint::operator++(int)
{
    bigint temp = *this;
    ++(*this);
    return temp;
}

bigint bigint::operator<<(unsigned int n) const
{
    bigint temp = *this;
    temp.str.insert(temp.str.end(), n, '0');
    return temp;
}

bigint bigint::operator>>(unsigned int n) const
{
    bigint temp = *this;
    if (temp.str.length() <= n)
        temp.str = "0";
    temp.str.erase(temp.str.length() - n, n);
    return temp;
}

bigint& bigint::operator<<=(unsigned int n)
{
    *this = *this << n;
    return *this;
}

bigint& bigint::operator>>=(unsigned int n)
{
    *this = *this >> n;
    return *this;
}

unsigned int stringToUINT(const std::string& str)
{
    unsigned int res;
    std::stringstream ss(str);
    ss >> res;
    return res;
}

bigint bigint::operator<<(const bigint& other) const
{
    return *this << stringToUINT(other.str);
}

bigint bigint::operator>>(const bigint& other) const
{
    return *this >> stringToUINT(other.str);
}

bigint& bigint::operator<<=(const bigint& other)
{
    return *this <<= stringToUINT(other.str);
}

bigint& bigint::operator>>=(const bigint& other)
{
    return *this >>= stringToUINT(other.str);
}

bool bigint::operator==(const bigint& other) const
{
    return this->str == other.str;
}

bool bigint::operator!=(const bigint& other) const
{
    return this->str != other.str;
}

bool bigint::operator<(const bigint& other) const
{
    if (this->str.length() == other.str.length())
        return this->str < other.str;
    return this->str.length() < other.str.length();
}

bool bigint::operator>(const bigint& other) const
{
    return other < *this;
}

bool bigint::operator<=(const bigint& other) const
{
    return *this < other || *this == other;
}

bool bigint::operator>=(const bigint& other) const
{
    return *this > other || *this == other;
}

std::ostream& operator<<(std::ostream& output, const bigint& obj)
{
    output << obj.getStr();
    return output;
}