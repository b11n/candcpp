#include <stdio.h>
#include <iostream>

#include <ctime>
using namespace std;

int main()
{
	unsigned long long n = 12334334534433445ll;
	int sum = 0;
	clock_t start,end;
    start=clock();

	while (n != 0) {
		int c = n%10;
		c=c*c;
		sum += c;
		n /= 10;
	}
	for(long long i=0;i<n;i++);
	end=clock();
cout<<"Version 1 takes "<<end-start<<" "<<CLOCKS_PER_SEC<<" msec"<<endl;


	printf("The sum is %d\n", sum);
	scanf("%d",&n);
	return 0;
	
}

