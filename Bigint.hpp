#include<bits/stdc++.h>
using namespace std;
//helper functions
string intToString(int n)
{
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}
string longlongToString(long long n)
{
    stringstream ss;
    ss<<n;
    string s;
    ss>>s;
    return s;
}
void strip_leading_zeroes(string& num) {
    size_t i;
    for (i = 0; i < num.size(); i++)
        if (num[i] != '0')
            break;

    if (i == num.size())
        num = "0";
    else
        num = num.substr(i);
}

bool isbiggerorequalstring(string s1,string s2)
{
    if(s1.size()>s2.size())
    {
        return true;
    }
    else if(s1.size()<s2.size())
    {
        return false;
    }
    else
    {
        for(int i=0;i<s1.size();i++)
        {
            if((int)(s1[i]-'0')<(int)s2[i]-'0')
            {
                return false;
            }
        }
        return true;
    }
}
void add_leading_zeroes(std::string& num, size_t num_zeroes) {
    num = string(num_zeroes, '0') + num;
}
class Bigint
{
        int sign;
        string s;
    public:
        Bigint(string s)
        {
            if(s[0]=='-')
            {
                this->sign=-1;
            }
            else
            {
                this->sign=1;
            }
            this->s=s;
        }
        Bigint(int n)
        {
            if(n<0)
            {
                this->sign=-1;
            }
            else
            {
                this->sign=1;
            }
            this->s= intToString(n);
        }
        Bigint(long long n)
        {
             if(n<0)
            {
                this->sign=-1;
            }
            else
            {
                this->sign=1;
            }
            this->s= longlongToString(n);
        }
        Bigint()
        {
            this->s="0";
            this->sign=+1;
        }
        bool operator<(Bigint x)
        {
            if (sign != x.sign)
                return sign < x.sign;

            if (s.size() != x.s.size())
                return (sign == 1 ? s.size() < x.s.size() : s.size() > x.s.size());

            for (int a = s.size() - 1; a >= 0; a--)
                if (s[a] != x.s[a])
                    return (sign == 1 ? s[a] < x.s[a] : s[a] > x.s[a]);

            return false;
        }
        bool operator==(Bigint n)
        {
            if(s==n.s&&sign==n.sign)
            {
                return true;
            }
            else
            {
                return false;
            }
        }
        bool operator==(string s1)
        {
            Bigint n;
            if(s[0]=='-')
            {
                n.sign=-1;
            }
            else
            {
                n.sign=1;
            }
            n.s=s1;
            return *this==n;
        }
        void operator+()
        {
            return;
        }
        Bigint operator-()
        {
            return this->sign=this->sign*-1;
        }
        Bigint operator-(Bigint n)
        {
            if(this->sign==1 && n.sign==-1)
            {
                n.sign=+1;
                Bigint res = *this + n;
                n.sign=-1;
                return res;
            }
            else if(this->sign==-1 && n.sign==1)
            {
                this->sign=1;
                Bigint res = -(*this + n);
                this->sign=-1;
                return  res;
            }
            string bigger,smaller;
            Bigint result;
            if (isbiggerorequalstring(this->s,n.s)) 
            {
                bigger = this->s;
                smaller = n.s;

                if (this->sign == -1)  
                {    
                    result.sign = -1;
                }
            }
            else 
            {
                bigger = n.s;
                smaller = this->s;

                if (n.sign == 1)        
                    result.sign = -1;
            }

            add_leading_zeroes(smaller, bigger.size() - smaller.size());

            result.s = "";  
            short difference;
            long i, j;

            for (i = bigger.size() - 1; i >= 0; i--)
            {
                difference = bigger[i] - smaller[i];
                if (difference < 0) 
                {
                    for (j = i - 1; j >= 0; j--)
                    {
                        if (bigger[j] != '0') 
                        {
                            bigger[j]--;    
                            break;
                        }
                    }
                    j++;
                    while (j != i) 
                    {
                        bigger[j] = '9';    
                        j++;
                    }
                    difference += 10;   
                }
                result.s = to_string(difference) + result.s;
            }
            strip_leading_zeroes(result.s);

            if (result.s == "0")
                result.sign = 1;

            return result;
        }
        Bigint operator+(Bigint n)
        {
            if(this->sign==1&&n.sign==-1)
            {
                n.sign=1;
                Bigint res= *this-n;
                n.sign=-1;
                return res;
            }
            else if(this->sign==-1&&n.sign==1)
            {
                this->sign=1;
                Bigint res=-(*this-n);
                this->sign=-1;
                return res;
            }
            Bigint result;
            result.s="";
            result.sign=this->sign;
            string bigger,smaller;
            if(isbiggerorequalstring(this->s,n.s))
            {
                bigger=this->s;
                smaller=n.s;
            }
            else
            {
                bigger=n.s;
                smaller=this->s;
            }
            int carry=0,sum=0;
            for(long i = bigger.size() - 1; i >= 0; i--) 
            {
                sum = bigger[i] - '0' + smaller[i] - '0' + carry;
                result.s = to_string(sum % 10) + result.s;
                carry = sum /  10;
            }
            if (carry)
                result.s = to_string(carry) + result.s;

            if (result.s == "0" || result.s=="")
            {
                result.sign = 1;
                result.s=="0";
            }
            return result;
        }
        Bigint operator*(Bigint n)
        {
            Bigint result;

            if(n.s=="0")
            {
                result.s="0";
                result.sign=1;
                return result;
            }

            for (int a = 0, b = s[a] - '0'; a < s.size(); a++, b = s[a] - '0') 
            {
                while (b--)
                    result = result + n;

                n.s.insert(n.s.begin(), '0');
            }

            if(this->sign==n.sign)
            {
                result.sign=1;
            }
            else
            {
                result.sign=-1;
            }
            return result;
        }
        Bigint operator/(Bigint n)
        {
            if (n.s=="0")
            throw "Can't divide a no. by zero";

            Bigint temp, result;

            if(this->sign==n.sign)
            {
                result.sign=1;
            }
            else
            {
                result.sign=-1;
            }

            for (int a = 0; a < s.size(); a++)
                result.s += "0";

            n.sign = 1;

            for (int a = s.size() - 1; a >= 0; a--) {
                temp.s.insert(temp.s.begin(), '0');
                temp = temp + s.substr(a, 1);

                while (!(temp < n)) {
                    temp = temp - n;
                    result.s[a]++;
                }
            }

            return result;
        }
        
};
void tests()
{
    Bigint n1("123456789"),n2("123456789");
    long long l1=1023245,l2=23425212;
    Bigint n3(l1),n4(l2);
    assert(n1==n2);
    assert((n1+n2)=="246913578");
    assert((n1*n2)=="15241578750190521");
    assert((n1/n2)=="1");
    assert((n1-n2)=="0");
}
int main()
{
    tests();
    return 0;
}