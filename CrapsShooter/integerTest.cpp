#include <iostream>
#include <cstdlib>
#include <limits>
using namespace std;

class Test
{
private:
    int newValue;
public:
    void testForInt(int inTest)
    {
        while (!(inTest))
        {
            cout << "     Invalid input! \n     Try again! ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        newValue = inTest;
    }
    int getNewValue()
    {
        return newValue;
    }
};
