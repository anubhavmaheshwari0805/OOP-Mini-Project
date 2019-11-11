#include<iostream>
#include<string.h>
#include<iomanip>
#define m 20
using namespace std;
void line(char ch,int n)
{
    for(int i=0;i<n;i++)
    cout<<ch;
    cout<<"\n";
}
template <class X> void set(X x,int n)
{
    int i=0;
    X temp=x;
	if(x==0)
	i++;
    while(temp!=0)
    {
        i++;
        temp=int(temp/10);
    }
    int len=i;
	if(x<0)
	len++;
    int l=(n-len)/2;
    for(i=0;i<l;i++)
	cout<<" ";
	cout<<setprecision(len)<<x;
	for(i=0;i<(n-len-l);i++)
	cout<<" ";
}
void set(char s[],int n)
{
	int i=0;
	int l=strlen(s);
    int x=(n-l)/2;
	for(i=0;i<x;i++)
	cout<<" ";
	cout<<s;
	for(i=0;i<(n-x-l);i++)
	cout<<" ";
}
class person
{
	protected:
		char name[m];
		float paid[m],htp[m],total,tpaid,thtp;
    public:
    	int code;
    	person()
    	{
			total=0;
			tpaid=0;
			thtp=0;
		}
		void init(int i)
		{
    		paid[i]=htp[i]=0;
		}
    	void read(char a[m],int c)
		{
			strcpy(name,a);
			code=c;
		}
		int check(char b[m],int c)
		{
			int i=0;
			if(!strcmp(name,b))
			{
			    cout<<"Enter different name."<<endl;
			    i+=1;
		    }
		    if(code==c)
		    {
		    	cout<<"Enter different code."<<endl;
		    	i+=2;
			}
			return i;
		}
		void displayname()
		{
			set(name,15);
		}
		void displaycode()
		{
			set(name,15);
			cout<<"->";
			set(code,10);
			cout<<endl;
		}
		void amountpaid(float i,int r)
		{
			paid[r]=i;
		}
		void amounthtp(float j,int r)
		{
			htp[r]=j;
		}
		void calculate(int r)
		{
			for(int i=0;i<r;i++)
			{
				tpaid+=paid[i];
				total+=htp[i];
			}
			thtp=total-tpaid;
		}
		void showarray(int i)
		{
			set(paid[i],7);
			cout<<"|";
			set(htp[i],7);
		}
		void showtotal()
		{
			set(total,15);
		}
		void showpaid()
		{
			set(tpaid,15);
		}
		void showhtp()
		{
			set(thtp,15);
		}
};
void isnum(int i)
{
	if(i==0)
	{
		cout<<"ERROR! : You entered a character or 0.\nQuiting...\n";
		exit(0);
	}
}
int main()
{
	int n;
	cout<<"Enter the no. of peoples : ";
	cin>>n;
	isnum(n);
	person p[n];
	char name[20];
	int code,i,j,k;
	line('-',66);
	cout<<"Enter the names with a numeric integral code(except 0) : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" - ";
		cin>>name;
		cin>>code;
		jump1: isnum(code);
		for(j=0;j<i;j++)
		{
			k=p[j].check(name,code);
			if(k==1)
			cin>>name;
			else if(k==2)
			cin>>code;
			else if(k==3)
			cin>>name>>code;
			if(k==1||k==2||k==3)
			goto jump1;
		}
		p[i].read(name,code);
	}
	line('=',66);
	cout<<"Person's name with their name code (Use these codes for entries) : "<<endl;
	for(i=0;i<n;i++)
	{
		set(i+1,7);
		cout<<"-";
		p[i].displaycode();
	}
	char reason[m][m];
	i=0;
	int n1,n2;
	float bill[m],tbill=0,paid,part;
	line('=',64);
	cout<<i+1<<"-Enter Reason ( if finished, write 'end' ) : ";
	cin>>reason[i];
	while(strcmp(reason[i],"end\0"))
	{
		for(j=0;j<n;j++)
		{
			p[j].init(i);
		}
		bill[i]=0;
		cout<<"----Enter no. of peoples who paid (if all paid equally then enter -1 ) : ";
		jump2 : cin>>n1;
		isnum(n1);
		if(n1==-1)
		{
			cout<<"------Enter amount paid per person : ";
			cin>>paid;
			isnum(paid);
			for(k=0;k<n;k++)
			{
			    p[k].amountpaid(paid,i);
			    bill[i]+=paid;
		    }
		}
		else if(n1>0&&n1<=n)
		{
		    for(j=0;j<n1;j++)
		    {
				cout<<"------Enter namecode of person : ";
			    jump3: cin>>code;
				for(k=0;k<n;k++)
				{
					if(p[k].code==code)
					break;
				}
				if(k==n)
				{
					cout<<"------ERROR! : Enter a valid namecode : ";
					goto jump3;
				}
				cout<<"------Enter amount paid by "<<code<<" : ";
			    cin>>paid;
				isnum(paid);
			    for(k=0;k<n;k++)
			    {
				    if(p[k].code==code)
					{
                        p[k].amountpaid(paid,i);
						break;
					}
		    	}
			    bill[i]+=paid;
		    }
	    }
		else
		{
			cout<<"----ERROR! : Enter a valid number : ";
            goto jump2;
		}
		cout<<"----Enter no. of peoples whose amount is paid (for all, enter -1 or "<<n<<" ): ";
		jump4: cin>>n2;
		if(n2==-1||n2==n)
		{
			for(k=0;k<n;k++)
		    p[k].amounthtp(bill[i]/n,i);
		}
		else if(n2>0&&n2<n)
		{
		    for(j=0;j<n2;j++)
			{
				cout<<"------Enter name code of person : ";
				jump5: cin>>code;
				for(k=0;k<n;k++)
				{
					if(p[k].code==code)
					break;
				}
				if(k==n)
				{
					cout<<"------ERROR! : Enter a valid namecode : ";
					goto jump5;
				}
		        for(k=0;k<n;k++)
		        {
		        	if(p[k].code==code)
					{
                        p[k].amounthtp(bill[i]/n2,i);
						break;
					}
				}
		    }
		}
		else
		{
			cout<<"----ERROR! : Enter a valid number : ";
			goto jump4;
		}
	    tbill+=bill[i];
	    i++;
	    cout<<i+1<<"-Enter Reason ( if finished, enter 'end' ) : ";
		cin>>reason[i];
	}
	int r=i;
	for(i=0;i<n;i++)
	{
	    p[i].calculate(r);
    }
	line('=',15*n+2*n+36);
	cout<<"||";
	char c1[20]="Reason";
    set(c1,20);
	cout<<"||";
    for(i=0;i<n;i++)
    {
        p[i].displayname();
        cout<<"||";
    }
	char c2[10]="Bills";
    set(c2,10);
	cout<<"||"<<endl;
	line('=',15*n+2*n+36);
    for(i=0;i<r;i++)
    {
		cout<<"||";
    	set(reason[i],20);
		cout<<"||";
    	for(j=0;j<n;j++)
		{
            p[j].showarray(i);
			cout<<"||";
		}
        set(bill[i],10);
		cout<<"||"<<endl;
		line('=',15*n+2*n+36);
	}
	cout<<"||";
	char c3[20]="Total Expenses";
	set(c3,20);
	cout<<"||";
	for(i=0;i<n;i++)
	{
        p[i].showtotal();
		cout<<"||";
	}
	set(tbill,10);
	cout<<"||"<<endl;
	line('=',15*n+2*n+36);
	cout<<"||";
	char c4[20]="Paid";
	set(c4,20);
	cout<<"||";
	for(i=0;i<n;i++)
	{
        p[i].showpaid();
		cout<<"||";
	}
	cout<<endl;
	line('=',(15*n+2*n+24));
	cout<<"||";
	char c5[20]="Have to Pay";
	set(c5,20);
	cout<<"||";
	for(i=0;i<n;i++)
	{
        p[i].showhtp();
		cout<<"||";
	}
	cout<<endl;
	line('=',15*n+2*n+24);
	return 0;
}