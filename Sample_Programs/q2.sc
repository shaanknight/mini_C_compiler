int main()
{
	int n;
	cin(n);
	int fl,i;
	fl = 0;
	for(i=2;i*i<=n;i=i+1)
	{
		if((n%i) == 0)
		{
			fl = 1;
		}
	}
	if(fl == 0)
	{
		cout("Prime");
	}
	else
	{
		cout("Composite");
	}
	return 0;
}
