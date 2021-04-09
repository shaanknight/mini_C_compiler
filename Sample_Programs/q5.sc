int main()
{
	int n;
	cin(n);
	int i,j,p;
	p = 1;
	for(i=1;i<=n;i=i+1)
	{
		p = p*2;
	}
	for(i=0;i<=p;i=i+1)
	{
		int q;
		q = 1;
		for(j=0;j<n;j=j+1)
		{
			if((q&i) > 0)
			{
				cout(j+1);
				cout(" ");
			}
			q = q*2;
		}
		cout("\n");
	}
}
