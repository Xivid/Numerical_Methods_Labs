#include<iostream>
#include<cmath>
using namespace std;
#define N 20
int power(int m,int n) {
    int sum=1;
    if(n==0&&m!=0)   return 1;
    else{
        for(int i=0;i<n;i++)     sum*=m;
        return sum;
    }
}
double det(double a[N][N],int n){
    double A;  double b[N];
    if(n==1)  { A=a[0][0];   return A;  }
    else if(n==2)  {   A=a[0][0]*a[1][1]-a[0][1]*a[1][0];   return A;  }
    else if(n==3)  {
       A=a[0][0]*a[1][1]*a[2][2]+a[0][1]*a[1][2]*a[2][0]+a[0][2]*a[1][0]*a[2][1]-a[0][2]*a[1][1]*a[2][0]-a[0][1]*a[1][0]*a[2][2]-a[0][0]*a[1][2]*a[2][1];
       return A;
    }
    else  {
       A=0;
       double c[N][N];
       for(int i=0;i<n;i++) b[i]=a[i][0]*power(-1,i+1+1);
       for(int i=0;i<n;i++)
         for(int j=0;j<n-1;j++) a[i][j]=a[i][j+1];
       for(int i=0;i<n;i++)
        for(int j=0;j<n-1;j++) c[i][j]=a[i][j];
       for(int i=0;i<n;i++) {
               for(int j=i;j<n;j++)
                {
                    for(int k=0;k<n-1;k++)  {      a[j][k]=a[j+1][k];       }
                 }
            A+=b[i]*det(a,n-1);
            for(int i=0;i<n;i++)
                for(int j=0;j<n-1;j++)       a[i][j]=c[i][j];
        }
        return A;
      }
}
int main() {
    double a[N][N];
    int m;
    cout<<"请输入行列式的阶数:"<<endl;
    cin>>m;
    cout<<"请输入行D列式各项值:"<<endl;
    for(int i=0;i<m;i++)
        for(int j=0;j<m;j++)
           cin>>a[i][j];
    cout<<det(a,m)<<endl;
    return 0;
}
