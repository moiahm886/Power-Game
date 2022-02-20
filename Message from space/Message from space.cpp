#include<iostream>
#include<string>
#include<cmath>
#include<vector>
using namespace std;
int fact(int n)
{
	int res = 1;
	for (int i = 2; i <= n; i++)
		res = res * i;
	return res;
}
int combination(int n, int r)
{
	return fact(n) / (fact(r) * fact(n - r));
}
void formula(int n)
{
	vector<string>vect;
	if (n == 0)
	{
		string str = "1";
		vect.push_back(str);
	}
	else if (n == 1)
	{
		string str =  "a+b";
		vect.push_back(str);
	}
	else if (n > 1)
	{
		for (int i = 0; i < n+1; i++)
		{
			int x;
			string str;
			x = combination(n, i);
			str = to_string(x);
			vect.push_back(str);
			vect.push_back("a");
			vect.push_back("^");
			x = n-i;
			if (x != 1)
			{
				str = to_string(x);
				vect.push_back(str);
			}
			if (i != 0)
			{
				vect.push_back("b");
				vect.push_back("^");
				x = i;
				if (x != 1)
				{
					string str = to_string(x);
					vect.push_back(str);
				}
			}
			vect.push_back("+");
		}
	}
	else if (n < 0)
	{
		if (n == -1)
		{
			string str = "1/(a+b)";
			vect.push_back(str);
		}
		else
		{
			vect.push_back("1/(");
			n *= -1;
			for (int i = 0; i < n + 1; i++)
			{
				int x;
				string str;
				x = combination(n, i);
				str = to_string(x);
				vect.push_back(str);
				vect.push_back("a");
				vect.push_back("^");
				x = n - i;
				str = to_string(x);
				vect.push_back(str);
				if (i != 0)
				{
					vect.push_back("b");
					vect.push_back("^");
					x = i;
					string str = to_string(x);
					vect.push_back(str);
				}
				vect.push_back("+");
			}
			vect.pop_back();
			vect.push_back(")");
		}
	}
	
    for (auto &x:vect)
	{
		cout << x;
	}
	cout << endl;
}
int main()
{
	int number;
	cin >> number;
	formula(number);
}