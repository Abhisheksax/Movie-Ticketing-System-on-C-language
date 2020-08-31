#include<iostream>
#include <time.h>
using namespace std;

struct system
{
	char uname[1000],status[100];
	long long pno;
	int tno;
	int ttimehh,ttimemm;
	
}t[1000];



int timehh[1000],timemm[1000],showcounter=0;

int check(int stimeh,int stimem)
{
	int i,len,res=-1;
	len = sizeof(timehh)/sizeof(timehh[0]);
	for(i=1;i<=showcounter;i++)
	{
		if(timehh[i]==stimeh && timemm[i]==stimem)
		{
			res=i;
			break;
		}
	}
	return res;
}

void newshow(int count)
{
	cout<<"\nEnter new show timing(HH:MM): ";
	cin>>timehh[count];
	cin>>timemm[count];
}

void showtiming()
{
	for(int i=1;i<=showcounter;i++)
	{
		cout<<i<<". "<<timehh[i]<<":"<<timemm[i]<<"\n";
	}
}

void updateshowtimimg()
{
	int stimeh,stimem,counter=-1,ntimeh,ntimem,res;
	showtiming();
	int len = sizeof(timehh)/sizeof(timehh[0]);
	cout<<"\n\nEnter Timing to get updated: ";
	cin>>stimeh;
	cin>>stimem;
	res = check(stimeh,stimem);
	if(res!=-1)
	{
		cout<<"\nEnter New timing: ";
		cin>>ntimeh;
		cin>>ntimem;
		timehh[res]= ntimeh;
		timemm[res]=ntimem;
		cout<<"\nShow Timing Updated";	
	}
	else{
	
		do{
			cout<<"\n\tShow not found, Enter Again: ";
			cin>>stimeh;
			cin>>stimem;
			res = check(stimeh,stimem);
		}while(res==-1);
	
			cout<<"\nEnter New timing: ";
			cin>>ntimeh;
			cin>>ntimem;
			timehh[res]= ntimeh;
			timemm[res]=ntimem;
			cout<<"\nShow Timing Updated";
	}
}

void book(int count)
{
	
	int stime,len,res=0,option=0;
	len = sizeof(timehh)/sizeof(timehh[0]);
	cout<<"\n\nEnter Name: ";
	cin>>t[count].uname;
	cout<<"\nEnter Phone Number: ";
	cin>>t[count].pno;
	cout<<"\nEnter Show timing: ";
	
	cout<<"\n Show timings available: ";
	showtiming();
	cout<<"\nEnter your option: ";
	cin>>option;
	if(option>len || option<=0){
	do{
		
		cout<<"\n\tWrong Option!!";
		cout<<"\n Show timings available: ";
	showtiming();
	cout<<"\n\tEnter Again: ";
		cin>>option;
	}while(option>len || option<=0);}
	t[count].tno=count;
	t[count].ttimehh = timehh[option];
	t[count].ttimemm = timemm[option];
	cout<<"\n Booking Confirmed";
}

void timeS(int hh,int mm) 
{ 
   int i; 
   for (i=1; i<=showcounter; i++) 
      	if (timehh[i] == hh && timemm[i]==mm) 
         	break; 
  		
   if (i < showcounter) 
   { 
     //showcounter = showcounter - 1; 
     for (int j=i; j<=showcounter; j++) 
     {
		   timehh[j] = timehh[j+1];
		timemm[j] = timemm[j+1];} 
   } 
   cout<<"\n New Show Timings:\n ";
   
   showtiming();
}

void deletetime()
{
	int hh,mm;
	showtiming();
	cout<<"\nEnter Time(HH:MM): ";
	cout<<"\nHours: ";
	cin>>hh;
	cout<<"\nMinutes";
	cin>>mm;
	timeS(hh,mm);	
}

void alltickets(int count)
{
	int stime,counter=0,hh,mm;
	if(count==0)
	{
		cout<<"No tickets founds";
	}
	else
	{
		cout<<"\nHours: ";
	cin>>hh;
	cout<<"\nMinutes";
	cin>>mm;
		for(int i=1;i<=count;i++)
		{
			if(t[i].ttimehh==hh && t[i].ttimemm==mm)
			{
				counter++;
				cout<<"\n\nTicket "<<counter;
				cout<<"\nTicket no.: "<<t[i].tno;
				cout<<"\nUser Name: "<<t[i].uname;
				cout<<"\nPhone No.: "<<t[i].pno;
				cout<<"\nShow Time: "<<t[i].ttimehh<<":"<<t[i].ttimemm;
			}
		}
	}
}

void viewticket(int count)
{
	int ticketno,c=0;
	cout<<"\nEnter ticket no.: ";
	cin>>ticketno;
	for(int i=1;i<=count;i++)
	{
		if(t[i].tno==ticketno)
		{
			c=i;
		}
	}
	if(c!=0)
	{
			cout<<"\nTicket no.: "<<t[c].tno;
			cout<<"\nUser Name: "<<t[c].uname;
			cout<<"\nPhone No.: "<<t[c].pno;
			cout<<"\nShow Time: "<<t[c].ttimehh<<":"<<t[c].ttimemm;
	}
	else
	{
		cout<<"\nNO TICKET FOUND";
	}
}

int main()
{
	int option,count=0,counter;;
	do{	
	time_t t = time(NULL);
	tm* timePtr = localtime(&t);
    cout<<"\nMenu:\t";
    cout << "Time = " << timePtr->tm_hour <<":"<<timePtr->tm_min<< endl;
    cout<<"1. Book Ticket\n";
    cout<<"2. Update Show Timings\n";
    cout<<"3. All tickets at Particular Time\n";
    cout<<"4. Delete Show Timing\n";
    cout<<"5. View Booking details\n";
    cout<<"6. Exit\t";
    cin>>option;
    switch(option)
    {
    	case 1:
    		{
    			count++;
    			book(count);
    			break;
			}
		case 2:
			{
				cout<<"\n1. New show\n2. Update Existing";
				cin>>counter;
				if(counter == 1)
				{
					showcounter++;
					newshow(showcounter);
					break;
				}
				else
				{
					updateshowtimimg();
					break;
				}
				
			}
		case 3:
			{
				alltickets(count);
				break;	
			}	
		case 4:
			{
				deletetime();
				break;
			}
		case 5:
			{
				viewticket(count);
				break;
			}
	}
    
	
	}while(option!=6);

	return 0;
}
