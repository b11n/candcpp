#include<iostream.h>
int main()
{
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
	long k;
	cout<<"Enter a number whose factorial needs to be calculated:";
	cin>>k;
//////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////code for numbers which are less than 33 and greater than 3///////////////////////////////////////////////////////////
if (k<=33)
{
		long long fact=1;
		fact=1;
		for(int b=k;b>=1;b--)
		{
			fact=fact*b;
		}
		cout<<"The factorial of "<<k<<" is "<<fact<<endl;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////code for numbers which are greater than 33 ///////////////////////////////////////////////////////////
else
{
	int numArr[10000];
	int total,rem=0,count;		//rem use to save remainder of division(Carry Number).
	register int i;             //register will enhance performance by minimizing access time
	//int i;
	for(i=0;i<10000;i++)
		numArr[i]=0;            //set all array on NULL.
				
	numArr[10000]=1; //start from end of array.
	for(count=2;count<=k;count++)   
	{
		while(i>0)
		{
			total=numArr[i]*count+rem;  //rem will add the carry number to the next array digit that is multiplied to the count
			rem=0;
			if(total>9)
			{
				numArr[i]=total%10;
				rem=total/10;
			}
			else
			{
				numArr[i]=total;   //numArr[i] is being accessed in this for loop because we have made i as register which means the memory is allocated 
			}
			i--;             
		}
		rem=0;
		total=0;
		i=10000;
	}
	cout<<"The factorial of "<<k<<" is ";
	for(i=0;i<10000;i++)            
	{
		if(numArr[i]!=0 || count==1)  
		{
			cout<<numArr[i];
			count=1;
		}
	}
	cout<<endl;
}
int g;
cin>>g;
return 0;
}
