int mat1[1000][1000],mat2[1000][1000],prd[1000][1000];
int main()
{
	int n,m,s;
	cin(n);
	cin(m);
	cin(s);
	int i,j,k;
	for(i=1;i<=n;i=i+1)
	{
		for(j=1;j<=m;j=j+1)
		{
			cin(mat1[i][j]);
		}
	}
	for(i=1;i<=m;i=i+1)
	{
		for(j=1;j<=s;j=j+1)
		{
			cin(mat2[i][j]);
		}
	}
	for(i=1;i<=n;i=i+1)
	{
		for(j=1;j<=s;j=j+1)
		{
			for(k=1;k<=m;k=k+1)
			{
				prd[i][j] = prd[i][j]+mat1[i][k]*mat2[k][j];
			}
		}
	}
	for(i=1;i<=n;i=i+1)
	{
		for(j=1;j<=m;j=j+1)
		{
			cout(prd[i][j]);
			cout(" ");
		}
		cout("\n");
	}
	return 0;
}
