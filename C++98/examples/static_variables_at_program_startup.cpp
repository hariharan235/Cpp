/*
 * References:
 *
 *   [filipek20180226] What happens to your static variables at the start of the program?
 *     http://www.bfilipek.com/2018/02/staticvars.html
 */

class Test
{
public:
    Test() {}
public:
    int _a;
};

Test t;

int main()
{
    return t._a
}
