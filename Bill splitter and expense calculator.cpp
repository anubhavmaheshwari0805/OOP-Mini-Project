#include<iostream>
#include<string.h>
#include<conio.h>
#include<iomanip>
#define m 30
using namespace std;
class person
{
	protected:
		char name[m];
		float paid[m],htp[m],total,tpaid,thtp;
    public:
    	int code;
    	person()
    	{
    		for(int i=0;i<m;i++)
    		{
    			paid[i]=htp[i]=0;
			}
			total=0;
			tpaid=0;
			thtp=0;
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
			cout<<name;
		}
		void displaycode()
		{
			cout<<name<<"\t-\t"<<code<<endl;
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
			cout<<paid[i]<<"-"<<htp[i]<<setw(10);
		}
		void showtotal()
		{
			cout<<total;
		}
		void showpaid()
		{
			cout<<tpaid;
		}
		void showhtp()
		{
			cout<<thtp;
		}
};
void line()
    {
            for(int i=1;i<41;i++)
          cout<<"--";

     cout<<"\n";
   }
int main()
{
	int n;
	cout<<"Enter the no. of peoples : ";
	cin>>n;
	person p[n];
	char name[20];
	int code,i,j,k;
	cout<<"Enter the names with a numeric integral code : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" - ";
		cin>>name>>code;
		for(j=0;j<i;j++)
		{
			k=p[j].check(name,code);
			if(k==1)
			cin>>name;
			else if(k==2)
			cin>>code;
			else if(k==3)
			cin>>name>>code;
		}
		p[i].read(name,code);
	}
	cout<<"Person's name with their name code (Use these codes for entries) : "<<endl;
	for(i=0;i<n;i++)
	{
		cout<<i+1<<" -\t";
		p[i].displaycode();
	}
	line();
	cout<<"\t*****IMPORTANT INSTRUCTION FOR ENTRIES*****"<<endl;
	cout<<"~~ In 'Reason' column , write the reason of paying in single string."<<endl;
	cout<<"~~ In 'No._of_payers' column , write the no. of payers who are paying the bill."<<endl;
	cout<<"   ~ If all are paying equally then write 0 ."<<endl;
	cout<<"   ~ If all are paying but not equally then write total no. of peoples."<<endl;
	cout<<"~~ In 'Name_code - Amount' column , write the name code of payers with amount they paid respectively."<<endl;
	cout<<"   ~ If all are paying equally then write only amount price that paid individually."<<endl;
	cout<<"~~ In 'no._of_beneficials' column , write the no. of persons whose bill is paid."<<endl;
	cout<<"   ~ If the bill is paying for all then write 0 or total no. peoples."<<endl;
	cout<<"~~ In last 'Name_code' column , write the name code of beneficials."<<endl;
	cout<<"   ~ If all are beneficials then write nothing and continue."<<endl;
	cout<<"~~ Write 'end' when the entries are finished."<<endl;
	cout<<"Examples :"<<endl;
	cout<<"~ aaa 0 amount 0 \\ Bill is paid by all."<<endl;
	cout<<"~ bbb 0 amount 3 2 4 6 \\ 2,4,6's Bill is paid by all."<<endl;
	cout<<"~ ccc 2 1 am1 3 am2 0 \\ 1 and 3 paid the bill of all with amount am1,am2 respectively."<<endl;
	cout<<"~ ddd 3 3 am1 4 am2 6 am3 4 2 3 4 6 \\ 2,3,4,6's bill is paid by 3,4,6 with amount am1,am2,am3 respectively."<<endl;
	char reason[m][m];
	i=0;
	int n1,n2;
	float bill[m],tbill=0,paid,part;
	line();
	line();
	cout<<"Reason | No._of_payers(n1) | [Name_code - Amount](n1_times) | no._of_beneficials(n2) | Name_code(n2_times)"<<endl;	cout<<i+1<<" -\t";
	//cout<<setw(10)<<"Reason"<<setw(20)<<"| No._of_payers(n1) |"<<setw(40)<<" [Name_code - Amount](n1_times) "<<setw(40)<<"| no._of_beneficials(n2) |"<<setw(40)<<" Name_code(n2_times)"<<setw(40)<<endl;	cout<<i+1<<" -\t";

	cin>>reason[i];
	while(strcmp(reason[i],"end\0"))
	{
		bill[i]=0;
		cin>>n1;
		if(n1==0)
		{
			cin>>paid;
			for(k=0;k<n;k++)
			{
			    p[k].amountpaid(paid,i);
			    bill[i]+=paid;
		    }
			cin>>n2;
			if(n2==0||n2==n)
			{
				for(k=0;k<n;k++)
			    p[k].amounthtp(bill[i]/n,i);
			}
			else
			{
				for(j=0;j<n2;j++)
				{
					cin>>code;
			        for(k=0;k<n;k++)
			        {
			        	if(p[k].code==code)
			        	p[k].amounthtp(bill[i]/n2,i);
					}
			    }
			}
		}
		else
		{
		    for(j=0;j<n1;j++)
		    {
			    cin>>code;
			    cin>>paid;
			    for(k=0;k<n;k++)
			    {
				    if(p[k].code==code)
				    p[k].amountpaid(paid,i);
		    	}
			    bill[i]+=paid;
		    }
		    cin>>n2;
		    if(n2==0||n2==n)
		    {
		    	for(k=0;k<n;k++)
			    p[k].amounthtp(bill[i]/n,i);
		    }
		    else
			{
		        for(j=0;j<n2;j++)
		        {
			        cin>>code;
			        for(k=0;k<n;k++)
			        {
				        if(p[k].code==code)
				        p[k].amounthtp(bill[i]/n2,i);
			        }
		        }
	        }
	    }
	    tbill+=bill[i];
	    i++;
	    cout<<i+1<<" -\t";
		cin>>reason[i];
	}
	int r=i;
	for(i=0;i<n;i++)
	{
	    p[i].calculate(r);
    }
    cout<<setw(20)<<"Reason"<<setw(20);
    for(i=0;i<n;i++)
    {
        p[i].displayname();
        cout<<setw(12);
    }
    cout<<setw(20)<<"Bills  "<<endl;
    for(i=0;i<r;i++)
    {
    	cout<<setw(20)<<reason[i]<<setw(20);
    	for(j=0;j<n;j++)
    	{	
    		cout<<setw(13);
    	    p[j].showarray(i);
    	    cout<<setw(13);
        }
        cout<<setw(20)<<bill[i]<<endl;
	}
	cout<<setw(20)<<"Total Expenses"<<setw(20);
	for(i=0;i<n;i++)
	{
		p[i].showtotal();
		cout<<setw(12);
	}
	cout<<setw(20)<<tbill<<endl;
	cout<<setw(20)<<"Paid"<<setw(20);
	for(i=0;i<n;i++)
	{
		p[i].showpaid();
		cout<<setw(12);
	}
	cout<<endl;
	cout<<setw(20)<<"Have to Pay"<<setw(20);
	for(i=0;i<n;i++)
	{
		p[i].showhtp();
		cout<<setw(12);
	}
	cout<<endl;
	return 0;
}
