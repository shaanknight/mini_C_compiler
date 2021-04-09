int ar[1000000],tmp[1000000];
func int merge(int l,int m,int r)
{
	int i,j,k;
	i = l;
	j = m+1;
	k = i;
	while(i<=m && j<=r)
	{
		if(ar[i]<=ar[j])
		{
			tmp[k] = ar[i];
			k = k+1;
			i = i+1;
		}
		else
		{
			tmp[k] = ar[j];
			k = k+1;
			j = j+1;
		}
	}
	while(i<=m)
	{
		tmp[k] = ar[i];
		k = k+1;
		i = i+1;
	}
	while(j<=r)
	{
		tmp[k] = ar[j];
		k = k+1;
		j = j+1;
	}
}
func int mergesort(int l,int r)
{
	if(l>=r)
	{
		return 0;
	}
	int m;
	m = (l+r)/2;
	mergesort(l,m);
	mergesort(m+1,r);
	merge(l,m,r);
	return 0;
}
int main()
{
	int n;
	cin(n);
	int i;
	for(i=0;i<n;i=i+1)
	{
		cin(ar[i]);
	}
	mergesort(0,n-1);
	for(i=0;i<n;i=i+1)
	{
		cout(ar[i]);
		cout(" ");
	}
	cout("\n");
	return 0;
}
