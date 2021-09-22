#include<bits/stdc++.h>
using namespace std;
string intToString(int n)
{
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}
class Bigint{
        int sign;
        string s;
    public:
        Bigint(string s)
        {
            this->s=s;
        }
        Bigint(int n)
        {
            this->s= intToString(n);
        }
        bool operator==(Bigint n)
        {
            if(s==n.s)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
};
void tests()
{
    Bigint n1=123456789,n2=123456789;
    assert(n1==n2);
}
int main()
{
    tests();
    return 0;
}