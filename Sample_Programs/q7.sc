int ar[1000000],cnt[1000000],tmp[1000000];
func int countsort(int n)
{
	int i,j,k;
	for(i=0;i<1000000;i=i+1)
	{
		cnt[i] = 0;
	}
	for(i=0;i<n;i=i+1)
	{
		cnt[ar[i]] = cnt[ar[i]]+1;
	}
	k = 0;
	for(i=0;i<n;i=i+1)
	{
		for(j=0;j<=cnt[i];j=j+1)
		{
			tmp[k] = i;
			k = k+1;
		}
	}
	for(i=0;i<n;i=i+1)
	{
		ar[i] = tmp[i];
	}
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
	countsort(n);
	for(i=0;i<n;i=i+1)
	{
		cout(ar[i]);
		cout(" ");
	}
	cout("\n");
	return 0;
}
