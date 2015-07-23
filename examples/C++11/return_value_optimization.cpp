/**
 * Illustrates 'Return Value Optimization'.
 *
 * Return Value Optimization (RVO) is also sometimes called 'elision' or 'copy
 * elision'.  The C++98/03 standard doesn't require the compiler to provide RVO
 * optimization, but most popular C++ compilers contain this optimization
 * technique: IBM XL C++, GCC and Clang.
 *
 * The technique is included in the C++11 standard due to its prevalence.  See
 * section 12.8 in the C++11 standard.  The name of the technique is 'copy
 * elision'.
 *
 * The conclusion is this:
 *
 * "RVO is a compiler optimization technique, while std::move is just an rvalue
 *  cast, which also instructs the compiler that it's eligible to move the
 *  object. The price of moving is lower than copying but higher than RVO, so
 *  never apply std::move to local objects if they would otherwise be eligible
 *  for the RVO."
 *
 *
 * References:
 *
 *   [1] https://www.ibm.com/developerworks/community/blogs/5894415f-be62-4bc0-81c5-3956e82276f3/entry/RVO_V_S_std_move
 */

#include <iostream>
#include <utility>

using namespace std;


class BigObject {

public:

    BigObject()
    {
        cout << "  constructing " << this << endl;
    }

    ~BigObject()
    {
        cout << "  destructing " << this << endl;
    }

    BigObject(const BigObject&)
    {
        cout << "  copy constructing " << this << endl;
    }

    BigObject(BigObject&&)
    {
        cout << "  move constructing " << this << endl;
    }

};


/**
 * Note that no copy constructor is being called here.  When the price of
 * copying is high, RVO enables us to run the program much faster.
 */
BigObject foo1()
{
    BigObject localObj;
    return localObj;
}


BigObject foo2()
{
    BigObject localObj;
    return std::move(localObj);
}


/**
 * Do not do this in real development, because you are returning a reference
 * to a local object here!
 */
BigObject&& foo3(int n)
{
    BigObject localObj;
    return std::move(localObj);
}


/**
 * Here, the copy constructor *is* called, so no Return Value Optimization.
 */
BigObject foo4(int n)
{
    BigObject localObj, anotherLocalObj;

    if (n > 2)
    {
        return localObj;
    }
    else
    {
        return anotherLocalObj;
    }
}


BigObject foo5(int n)
{
    BigObject localObj, anotherLocalObj;

    if (n > 2) {

       return std::move(localObj);

    } else {

       return std::move(anotherLocalObj);

    }
}


int main()
{
    {
        cout << "1 local object, no std::move applied:" << endl;
        BigObject obj = foo1();
    }
    cout << std::endl;
    {
        cout << "1 local object, std::move applied:" << endl;
        BigObject obj = foo2();
    }
    cout << std::endl;
    {
        cout << "1 local object, std::move applied, r-value return type:" << endl;
        auto f = foo3(1);
    }
    cout << std::endl;
    {
        cout << "2 local objects, no std::move applied:" << endl;
        BigObject obj = foo4(1);
    }
    cout << std::endl;
    {
        cout << "2 local objects, std::move applied" << endl;
        BigObject obj = foo5(1);
    }
}
