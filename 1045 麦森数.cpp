#include<iostream>
#include<vector>
#include<string>
using namespace std;
struct HugeInt:vector<int>//�ñ�׼��vector�����࣬�������λ�����⣬ͬʱ������ʵ��
{
    //���;���ת�߾��ȵĳ�ʼ���������Զ�������������
    //������赥��д�߾������͵;����������㺯����ʮ�ַ���
    HugeInt(int n = 0)//Ĭ�ϳ�ʼ��Ϊ0����0�ı�����ʽΪ��
    {
        push_back(n);
        check();
    }
    HugeInt& check()//�ڸ��������о����õ��Ľ�λС��������������
    {
        while (!empty() && !back()) pop_back();//ȥ�����λ���ܴ��ڵ�0
        if (empty()) return *this;
        for(int i = 1;i < size();++i)
        {
            (*this)[i] += (*this)[i - 1] / 10;
            (*this)[i - 1] %= 10;
        }
        while(back() >= 10)
        {
            push_back(back() / 10);
            (*this)[size() - 2] %= 10;
        }
        return *this;//Ϊʹ�÷��㣬����λ�������������
    }
};
//�������
istream& operator >> (istream &in, HugeInt &n)
{
    string s;
    in >> s;
    n.clear();
    for (int i = s.size() - 1; i >= 0;--i)n.push_back(s[i] - '0');
    return in;
}

ostream& operator << (ostream &out, const HugeInt &n)
{
    if (n.empty()) out << 0;
    for (int i = n.size() - 1;i >= 0;--i) out << n[i];
    return out;
}
//�Ƚϣ�ֻ��Ҫд������������ֱ�Ӵ��뼴��
//�������õ����������⿽������Ч
bool operator != (const HugeInt &a, const HugeInt &b)
{
    if (a.size() != b.size()) return 1;
    for(int i=a.size() - 1;i >= 0;--i)
        if(a[i] != b[i])return 1;
    return 0;
}

bool operator == (const HugeInt &a, const HugeInt &b)
{
    return !(a != b);
}

bool operator < (const HugeInt &a, const HugeInt &b)
{
    if (a.size() != b.size()) return a.size() < b.size();
    for (int i = a.size() - 1;i >= 0; --i)
        if (a[i]!=b[i])return a[i] < b[i];
    return 0;
}

bool operator > (const HugeInt &a, const HugeInt &b)
{
    return b < a;
}

bool operator <= (const HugeInt &a, const HugeInt &b)
{
    return !(a > b);
}

bool operator >= (const HugeInt &a, const HugeInt &b)
{
    return !(a < b);
}
//�ӷ�����ʵ��+=������������Ч
HugeInt& operator += (HugeInt &a, const HugeInt &b)
{
    if(a.size() < b.size()) a.resize(b.size());
    for(int i = 0;i != b.size();++i) a[i] += b[i];
    return a.check();
}

HugeInt operator + (HugeInt a, const HugeInt &b)
{
    return a += b;
}
//���������ز�ľ���ֵ�����ں����н������ʲ�����������
HugeInt& operator -= (HugeInt &a, HugeInt b)
{
    if (a<b) swap(a,b);
    for (int i = 0;i != b.size();a[i] -= b[i],++i)
        if (a[i]<b[i])//��Ҫ��λ
        {
            int j = i + 1;
            while (!a[j]) ++j;
            while (j > i)
            {
                --a[j];
                a[--j] += 10;
            }
        }
    return a.check();
}
HugeInt operator - (HugeInt a, const HugeInt &b)
{
    return a -= b;
}
//�˷�������ʵ��*=��ԭ���Լ���
HugeInt operator * (const HugeInt &a, const HugeInt &b)
{
    HugeInt n;
    n.assign(a.size() + b.size() - 1, 0);
    for(int i = 0; i != a.size();++i)
        for(int j = 0; j != b.size();++j)
            n[i+j] += a[i] * b[j];
    return n.check();
}

HugeInt& operator *= (HugeInt &a, const HugeInt &b)
{
    return a = a * b;
}

//������ȡģ��ʵ��һ�������������
HugeInt divmod(HugeInt &a, const HugeInt &b)
{
    HugeInt ans;
    for(int t = a.size() - b.size();a >= b; --t)
    {
        HugeInt d;
        d.assign(t + 1, 0);
        d.back() = 1;
        HugeInt c = b * d;
        while(a >= c)
        {
            a -= c;
            ans += d;
        }
    }
    return ans;
}

HugeInt operator / (HugeInt a, const HugeInt &b)
{
    return divmod(a, b);
}

HugeInt& operator /= (HugeInt &a, const HugeInt &b)
{
    return a = a / b;
}

HugeInt& operator %= (HugeInt &a, const HugeInt &b)
{
    divmod(a,b);
    return a;
}

HugeInt operator % (HugeInt a, const HugeInt &b)
{
    return a %= b;
}

HugeInt POW(HugeInt a, int ww)
{
	HugeInt ss;
	ss += 1;
	for (int i = 0;i < ww;i++)
	{
		ss *= a;
	}
	return ss;
}

int main()
{
	int s;
	cin >> s;
	HugeInt a;
	a += 2;
	cout << POW(a, s);
}