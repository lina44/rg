#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)
#include<iostream>
#include<fstream>
#include<iomanip>
#include<cmath>
using namespace std;

int zuidagongyueshu(int a, int b)//避免可约分分数出现
{
	int c = 0, min, i;
	min = a < b ? a : b;
	for (i = 1; i < min; i++)
	{
		if (a%i == 0 && b%i == 0)
			c = i;
		else
			c = 1;
	}
	return c;
}

int chenchu(int q)//是否有乘除
{
	int k;
	if (q == 1)
	{
		k = rand() % 4;//有
	}
	else
		k = rand() % 2;//无

	return k;
}

int suiji(int k, int q, int f, int g, int v, int z)
{

	int a, b, c, d, i,mo;
	double re;


	srand((int)time(0));
	ofstream outfile;
	outfile.open("e://2.txt");

	for (int j = 0; j<k; j++)
	{
		i = chenchu(q);

	a://如果加减有负数或除法有余数被要求，情况不合，则重新生成随机数（即：在a处重来）
		a = random(f);
		b = random(f);
		c = random(f);
		d = random(f);

		if (a<b && c<d && b != 0 && d != 0)//构成分数
		{
			int l, p;
			l = zuidagongyueshu(a, b);
			p = zuidagongyueshu(c, d);
			if (l != 0)
			{
				a = a / l;
				b = b / l;
			}
			if (k != 0)
			{
				c = c / p;
				d = d / p;
			}
			if (g != 1)//不用打印到文件
			{
				goto g;//跳过“输出到文件”部分代码
			}
			if ((c / d) == 0)
			{
				goto a;
			}
			switch (i)//输出到文件
			{
			case 0:{re = (a / b) + (c / d);  outfile << setprecision(10) << "(" << a << "/" << b << ")" << "+" << "(" << c << "/" << d << ")" << "=" << endl; break;}
			case 1:{re = (a / b) - (c / d);  if ((re < 0) && (v != 1)){ goto a; }  outfile << setprecision(10) << "(" << a << "/" << b << ")" << "-" << "(" << c << "/" << d << ")" << "=" << endl; break; }
			case 2:{re = (a / b) * (c / d);  outfile << setprecision(10) << "(" << a << "/" << b << ")" << "*" << "(" << c << "/" << d << ")" << "=" << endl; break;}
			case 3:{re = (a / b) / (c / d);  outfile << setprecision(10) << "(" << a << "/" << b << ")" << "/" << "(" << c << "/" << d << ")" << "=" << endl; break;}
			}
		g:
			switch (i)//输出到屏幕
			{
			case 0:{re = (a / b) + (c / d);  cout << "(" << a << "/" << b << ")" << "+" << "(" << c << "/" << d << ")" << "=" << endl;  break;}
			case 1:{re = (a / b) - (c / d); if ((re < 0) && (v!=1)) {goto a; }  cout << "(" << a << "/" << b << ")" << "-" << "(" << c << "/" << d << ")" << "=" << endl;  break; }
			case 2:{re = (a / b) * (c / d);  cout << "(" << a << "/" << b << ")" << "*" << "(" << c << "/" << d << ")" << "=" << endl;  break;}
			case 3:{re = (a / b) / (c / d);  cout << "(" << a << "/" << b << ")" << "/" << "(" << c << "/" << d << ")" << "=" << endl;  break;}
			}
		}
		//构成整数
		if (i == 3 && b == 0)//如果除数为0，去除法
		{
			i = rand() % 3;//随机的符号只有+、-、*
		}

		else
		{
			if (g != 1)//不用打印到文件
			{
				goto h; //跳过“输出到文件”部分代码
			}

			switch (i)//输出到文件
			{
			case 0:{re = a + b;  outfile << setprecision(10) << a << "+" << b << "=" << endl; break;}
			case 1:{re = a - b; if ((re < 0) && (v!=1)){ goto a; } outfile << setprecision(10) << a << "-" << b << "=" << endl; break; }
			case 2:{re = a * b;  outfile << setprecision(10) << a << "*" << b << "=" << endl; break;}
			case 3:{re = a / b;  outfile << setprecision(10) << a << "/" << b << "=" << endl; break;}
			}
		h:

			switch (i)//输出到屏幕
			{
			case 0:{re = a + b;  cout << a << "+" << b << "=" << endl;  break;}
			case 1:{re = a - b;  if ((re < 0) && (v != 1)){ goto a; }  cout << a << "-" << b << "=" << endl;  break; }
			case 2:{re = a * b;  cout << a << "*" << b << "=" << endl;  break;}
			case 3:{re = a / b;  mo = a%b; if ((mo != 0)&& (z!=1)){ goto a; } cout << a << "/" << b << "=" << endl;  break; }
			}

		}
	}
	outfile.close();
	return 0;
}


int main()
{
	int k , q, f , g , v , z ;

	cout << "请输入生成四则运算数量=\n"; cin >> k;
	cout << "请输入数值范围\n"; cin >> f; 
	cout << "请输入是否有乘除（有，按1）\n";cin >> q;
	cout << "是否输出到文件（是，按1）\n"; cin >> g;
	cout << "加减有无负数（有，按1）\n"; cin >> v;
	cout << "乘除有无余数（有，按1）\n"; cin >> z;

	suiji(k, q, f, g, v, z);
}
