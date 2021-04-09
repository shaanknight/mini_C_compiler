int main()
{
	int i,j,k,max;
	max = 100000000;
	for(i=1;i<=max;i=i+1)
	{
		for(j=1;j<=max;j=j+1)
		{
			for(k=1;k<=max;k=k+1)
			{
				if(i*i+j*j == k*k)
				{
					cout(i);
					cout(" ");
					cout(j);
					cout(" ");
					cout(k);
					cout("\n");
				}
			}
		}
	}
}
