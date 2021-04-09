int main()
{
	int n,k,i,g;
	bool trg;
	trg = false;
	g = 0;
	cin(n);
	cin(k);
	for(i=1;i<=n;i=i+1)
	{
		int j,p,a;
		j = k;
		p = 1;
		a = i;
		while(j>0)
		{
			if((j%2) == 1)
			{
				p = p*a;
			}
			j = j/2;
			a = a*a;
		}
		g = g+p;
	}
	cout(g);
	return 0;
}
