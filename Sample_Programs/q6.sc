int ar[1000000];
int main()
{
    int i, k, j, n;
    cin(n);
    for(i=0;i<n;i=i+1)
    {
        cin(ar[i]);  
    }
    for(i=1;i<n;i=i+1) 
    {  
        k = ar[i];  
        j = i-1;  
        while ((j>=0) && (ar[j] > k)) 
        {  
            ar[j+1] = ar[j];  
            j = j-1;  
        }  
        ar[j+1] = k;  
    }
    for(i=0;i<n;i=i+1)
    {
        cout(ar[i]);
        cout(" ");
    }
    cout("\n");
}
