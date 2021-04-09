bool prime[1000000];
int main()
{
	int n;
	cin(n);
	int fl,i,j;
	fl = 0;
	for(i=1;i<=n;i=i+1)
	{
		prime[i] = true;
	}
	prime[1] = false;
	int sum;
	sum = 0;
	for(i=2;i<=n;i=i+1)
	{
		if(prime[i] == true)
		{
			sum = sum + i;
		}
		for(j=i+i;j<=n;j=j+i)
		{
			prime[j] = false;
		}
	}
	cout(sum);
	return 0;
}
