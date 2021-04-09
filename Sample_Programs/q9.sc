int mat1[1000][1000],mat2[1000][1000],sum[1000][1000];
int main()
{
	int n,m;
	cin(n);
	cin(m);
	int i,j;
	for(i=1;i<=n;i=i+1)
	{
		for(j=1;j<=m;j=j+1)
		{
			cin(mat1[i][j]);
		}
	}
	for(i=1;i<=n;i=i+1)
	{
		for(j=1;j<=m;j=j+1)
		{
			cin(mat2[i][j]);
		}
	}
	for(i=1;i<=n;i=i+1)
	{
		for(j=1;j<=m;j=j+1)
		{
			sum[i][j] = mat1[i][j]+mat2[i][j];
		}
	}
	for(i=1;i<=n;i=i+1)
	{
		for(j=1;j<=m;j=j+1)
		{
			cout(sum[i][j]);
			cout(" ");
		}
		cout("\n");
	}
	return 0;
}