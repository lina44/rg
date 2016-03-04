#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define random(x) (rand()%x)
#include <iostream>
using namespace std;

int suiji()
{
	srand((int)time(0));
	int a,b,c,d,i;
	for(int j=0;j<30;j++)
	{		
		i=rand()%4;
		a=random(100);
		b=random(100);
		c=random(100);
		d=random(100);

		if (a<b && c<d)
		{
			switch(i)
			{
				case 0:cout<<"("<<a<<"/"<<b<<")"<<"+"<<"("<<c<<"/"<<d<<")"<<"="<<endl;break;
				case 1:cout<<"("<<a<<"/"<<b<<")"<<"-"<<"("<<c<<"/"<<d<<")"<<"="<<endl;break;
				case 2:cout<<"("<<a<<"/"<<b<<")"<<"*"<<"("<<c<<"/"<<d<<")"<<"="<<endl;break;
				case 3:cout<<"("<<a<<"/"<<b<<")"<<"/"<<"("<<c<<"/"<<d<<")"<<"="<<endl;break;
			}
		}
		else
		{
			switch(i)
			{
				case 0:cout<<a<<"+"<<b<<"="<<endl;break;
				case 1:cout<<a<<"-"<<b<<"="<<endl;break;
				case 2:cout<<a<<"*"<<b<<"="<<endl;break;
				case 3:cout<<a<<"/"<<b<<"="<<endl;break;
			}

		}

		
	}
	return 0;	
}

void main()
{
	suiji();
}