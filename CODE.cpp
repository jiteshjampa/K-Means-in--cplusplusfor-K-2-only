#include<iostream>
#include<cmath>
using namespace std;
void centroid(int n,float(*arr)[2],float a,float b,int i,int j)
{
    int p,q;
    a=(a+arr[i][j])/2;
    b=(b+arr[i][j+1])/2;
}
void cluster(int n,float (*arr)[2],int iterations)
{
    float x1,y1,x2,y2,q,r,z,m,e2,h2,k,l,e,h,o;
    int i,j;
    float ww[n];
    float qq[n];
    for(i=0;i<n;i++)
    {
        ww[i]=0;
        qq[i]=0;
    }
    i=0;
    j=0;
    z=0;
    ww[1]=2;
    qq[0]=1;
    x1=arr[0][0];
    y1=arr[0][1];
    x2=arr[1][0];
    y2=arr[1][1];
    for(i=0;i<iterations;i++)
    {
    for(i=2;i<n;i++)
    {
            o=((arr[i][j])-x1);
            k=o*o;
            m=((arr[i][j+1])-y1);
            l=m*m;
            e=((arr[i][j])-x2);
            e2=e*e;
            h=((arr[i][j+1])-y2);
            h2=h*h;
            q=k+l;
            q=sqrt(q);
            r=e2+h2;
            r=sqrt(r);
            if(q>r)
            {
                centroid(n,arr,x2,y2,i,j);
                ww[i]=i+1;
            }
            else if(q<r)
            {
                centroid(n,arr,x1,y1,i,j);
                qq[i]=i+1;
            }
            z++;
    }
    }
     cout<<"The data points formed in cluster1 is:";
    for(i=0;i<n;i++)
    {
        cout<<ww[i]<<"\t";
    }
    cout<<endl;
     cout<<"The data points formed in cluster2 is:";
    for(i=0;i<n;i++)
    {
        cout<<qq[i]<<"\t";
    }
    cout<<endl;
}
int value(int n,float (*arr)[2])
{
    int p,i,j;
    for( i=0;i<n;i++)
    {
        for(j=0;j<2;j++)
        {
            cout<<"The value for arr["<<i<<"]"<<"["<<j<<"]"<<"is:"<<endl;
            cin>>arr[i][j];
        }
    }
    cout<<endl;
    return 0;
}
int main()
{
    int i,ch,k,j,n,iterations;
    cout<<"enter the number of rows:";
    cin>>n;
    cout<<"Enter the number of iterations:";
    cin>>iterations;
    float ppw[n][2];
    value(n,ppw);
    cluster(n,ppw,iterations);
    return 0;
    
}
