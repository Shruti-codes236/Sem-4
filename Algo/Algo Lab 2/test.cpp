#include <iostream>
#include <vector>
#define ll long long int
using namespace std;
void display(vector <vector<ll> > ar)
{
    for(ll i=0;i<ar.size();i++)
    {
        for(ll j=0;j<ar[i].size();j++)
        cout<<ar[i][j]<<" ";
        cout<<endl;
        
    }
}

vector<vector<ll>> split(vector<vector<ll>> m,ll from, ll to,ll from1,ll to1)
{
    vector<vector<ll>> x;
    for(ll i=from;i<=to;i++)
        {   
            vector <ll> temp;
             for(ll j=from1;j<=to1;j++)
             {
                 temp.push_back(m[i][j]);
             }
             x.push_back(temp);
        }
                
    return x;
    
}

vector<vector<ll>> matAdd(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>> ans;
    
    for(ll i=0;i<a.size();i++)
    {
        vector <ll> temp;
        for(ll j=0;j<a[i].size();j++)
        { 
            ll num=a[i][j] + b[i][j];
            temp.push_back(num);
        }
        ans.push_back(temp);
    }
    return ans;
}


vector<vector<ll>> matSub(vector<vector<ll>> a,vector<vector<ll>> b)
{
    vector<vector<ll>> ans;
    
    for(ll i=0;i<a.size();i++)
    {
        vector <ll> temp;
        for(ll j=0;j<a[i].size();j++)
        { 
            ll num=a[i][j] - b[i][j];
            temp.push_back(num);
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<ll> > multiply(vector<vector<ll> > a,vector<vector<ll> > b,ll n)
{
    
        vector<vector<ll> > c;
            
        /*c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];  
        c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];  
        c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];  
        c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];*/
        if(n==1)
        {
            vector<ll> temp;
            temp.push_back(a[0][0]*b[0][0]);
            c.push_back(temp);
        }
       else if(n<=2){
            for(ll i=0;i<n;i++)
            {   vector <ll> temp;
                
                temp.push_back(a[i][0]*b[0][0]+a[i][1]*b[1][0]);
                temp.push_back(a[i][0]*b[0][1]+a[i][1]*b[1][1]);
                
                 c.push_back(temp);
            }
            return c;
        }
        else
        {
            vector<vector<ll>> a11=split(a,0,n/2-1,0,n/2-1);
            vector<vector<ll>> a12=split(a,0,n/2-1,n/2,n-1);
            vector<vector<ll>> a21=split(a,n/2,n-1,0,n/2-1);
            vector<vector<ll>> a22=split(a,n/2,n-1,n/2,n-1);
            
            vector<vector<ll>> b11=split(b,0,n/2-1,0,n/2-1);
            vector<vector<ll>> b12=split(b,0,n/2-1,n/2,n-1);
            vector<vector<ll>> b21=split(b,n/2,n-1,0,n/2-1);
            vector<vector<ll>> b22=split(b,n/2,n-1,n/2,n-1);
            
            vector<vector<ll>> p = multiply(matAdd(a11,a22),matAdd(b11,b22),n/2);  //p5
            vector<vector<ll>> q = multiply(matAdd(a21,a22),b11,n/2);   //p3
            vector<vector<ll>> r = multiply(a11,matSub(b12,b22),n/2);  //p1
            vector<vector<ll>> s = multiply(a22,matSub(b21,b11),n/2);  //p4
            vector<vector<ll>> t = multiply(matAdd(a11,a12),b22,n/2);  //p2
            vector<vector<ll>> u = multiply(matSub(a11,a21),matAdd(b11,b12),n/2);//p7
            vector<vector<ll>> v = multiply(matSub(a12,a22),matAdd(b21,b22),n/2);  //p6
            
            
            
            /*vector<vector<ll>> p1 = matAdd((multiply(a11,b11,n/2)),multiply(a12,b21,n/2));
            vector<vector<ll>> p2 = matAdd((multiply(a11,b12,n/2)),multiply(a12,b22,n/2));
            vector<vector<ll>> p3 = matAdd((multiply(a21,b11,n/2)),multiply(a22,b21,n/2));
            vector<vector<ll>> p4 = matAdd((multiply(a21,b12,n/2)),multiply(a22,b22,n/2));*/
            
            
            vector<vector<ll>> p1 = matAdd(matAdd(p,v),matSub(s,t));
            vector<vector<ll>> p2 = matAdd(r,t);
            vector<vector<ll>> p3 = matAdd(q,s);
            vector<vector<ll>> p4 = matSub(matAdd(p,r),matAdd(u,q));
            
            
            
            for(ll i=0;i<n;i++)
            {
                vector <ll> temp;
                for(ll j=0;j<n;j++)
                {
                    if(i<n/2 && j<n/2)
                    temp.push_back(p1[i][j]);
                    else if(i<n/2 && j>=n/2)
                    temp.push_back(p2[i][j-n/2]);
                    else if(i>=n/2 && j<n/2)
                    temp.push_back(p3[i-n/2][j]);
                    else
                    temp.push_back(p4[i-n/2][j-n/2]);
                }
                c.push_back(temp);
            }
                 
        }
            
                
        return c;   
    
    
}

int main()
{
    ll r1,c1,r2,c2;
     cout<<"Enter the size of first square matrix\n";
    cin>>r1;
    cout<<"Enter the size of second square matrix\n";
    cin>>r2;
    
    c1=r1;
    c2=r2;
    
    if(c1!=r2)
    cout<<"multiplyiplication not possible"<<endl;
    else
    {
        
        vector <vector<ll> > a;
        vector <vector<ll> > b;
        ll num;
        cout<<"Enter the first matrix"<<endl;
        for(ll i=0;i<r1;i++)
        {   vector <ll> temp;
            
            for(ll j=0;j<c1;j++){
            cin>>num;
            temp.push_back(num);
            }
            a.push_back(temp);
            
        }
        cout<<"Enter the second matrix"<<endl;
        for(ll i=0;i<r2;i++)
        {
               vector <ll> temp;
            
            for(ll j=0;j<c2;j++)
            {
            cin>>num;
            temp.push_back(num);
            }
            b.push_back(temp);
            
        }
        cout<<"The product of the two matrices:"<<endl;
        vector<vector<ll>> P=multiply(a,b,r1);
        display(P);
        
    }
    return 0;
}
//Recurrence relation T(n)=7T(N/2)+O(n^2)








