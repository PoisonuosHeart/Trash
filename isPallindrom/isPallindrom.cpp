#include <iostream>
#include <cmath>

//  Return true when value is pallindrom, else - false
bool isPallindrom(int value) {
    if (value == 0) return true;
    value = abs(value);
    int j = 0, tmp = value;
    while (tmp > 0) {
        ++j; tmp = static_cast <int> (floor(tmp / 10));
    }
    int i = 1, tmpNext = value; tmp = value;
    while (j > i) {
        tmp = tmp % 10;
        tmpNext = static_cast <int> (floor(value / pow(10, j - 1)));
        if (tmp != tmpNext) return false;
        value -= static_cast <int>(tmpNext * pow(10, j - 1));
        tmp = static_cast <int> (floor(((value - (tmp * pow(10, i - 1))) / pow(10, i))));
        ++i; --j;
    }
    return true;
}

int main()
{
    
    _ASSERT(isPallindrom(0) == true);    
    _ASSERT(isPallindrom(3) == true);
    _ASSERT(isPallindrom(33) == true);
    _ASSERT(isPallindrom(383) == true);
    _ASSERT(isPallindrom(3883) == true);
    _ASSERT(isPallindrom(38783) == true);
    _ASSERT(isPallindrom(388883) == true);
    _ASSERT(isPallindrom(3887883) == true);
    _ASSERT(isPallindrom(-3) == true);
    _ASSERT(isPallindrom(38) == false);
    _ASSERT(isPallindrom(3153) == false);
   
    std::cout << "Hello World!\n";
}

