#include <iostream>
#include <string>
#include <sstream>
using namespace std;
int main()
{
    string line;
    while (getline(cin, line))
    {
        int sum = 0, x;
        stringstream arr(line);
        while (arr >> x)
        {
            sum += x;
        }
        cout << sum << '\n';
    }
    return 0;
}