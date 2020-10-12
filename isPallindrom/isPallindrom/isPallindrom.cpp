#include <iostream>
#include <cmath>
#include <assert.h>

//  Return true when value is pallindrom, else - false
bool isPallindrom(int value) {
    if (value > 0) {
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
    else if (value == 0) return true;
    return false;
}

int main()
{
    {
        assert(isPallindrom(0));
    }

    {
        assert(isPallindrom(3));
    }

    {
        assert(isPallindrom(33));
    }

    {
        assert(isPallindrom(383));
    }

    {
        assert(isPallindrom(3883));
    }

    {
        assert(isPallindrom(38783));
    }

    {
        assert(isPallindrom(388883));
    }

    {
        assert(isPallindrom(3887883));
    }

    {
        assert(isPallindrom(-3) == false);
    }

    {
        assert(isPallindrom(38) == false);
    }

    {
        assert(isPallindrom(3153) == false);
    }
    std::cout << "Hello World!\n";
}

