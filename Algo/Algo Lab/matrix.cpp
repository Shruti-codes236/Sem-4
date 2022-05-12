#include <iostream>
#include <vector>
using namespace std;
void display(vector <vector<int> > ar)
{
    for(int i=0;i<ar.size();i++)
    {
        for(int j=0;j<ar[i].size();j++)
        cout<<ar[i][j]<<" ";
        cout<<endl;
        
    }
}

vector<vector<int>> split(vector<vector<int>> m,int r1, int r2,int c1,int c2)
{
    vector<vector<int>> x;
    for(int i=r1;i<=r2;i++)
        {   
            vector <int> temp;
             for(int j=c1;j<=c2;j++)
             {
                 temp.push_back(m[i][j]);
             }
             x.push_back(temp);
        }
                
    return x;
    
}

vector<vector<int>> add(vector<vector<int>> a,vector<vector<int>> b)
{
    vector<vector<int>> ans;
    
    for(int i=0;i<a.size();i++)
    {
        vector <int> temp;
        for(int j=0;j<a[i].size();j++)
        { 
            int num=a[i][j] + b[i][j];
            temp.push_back(num);
        }
        ans.push_back(temp);
    }
    return ans;
}


vector<vector<int>> sub(vector<vector<int>> a,vector<vector<int>> b)
{
    vector<vector<int>> ans;
    
    for(int i=0;i<a.size();i++)
    {
        vector <int> temp;
        for(int j=0;j<a[i].size();j++)
        { 
            int num=a[i][j] - b[i][j];
            temp.push_back(num);
        }
        ans.push_back(temp);
    }
    return ans;
}

vector<vector<int> > multiply(vector<vector<int> > a,vector<vector<int> > b,int n)
{
    
        vector<vector<int> > c;
            
        /*c[0][0]=a[0][0]*b[0][0]+a[0][1]*b[1][0];  
        c[0][1]=a[0][0]*b[0][1]+a[0][1]*b[1][1];  
        c[1][0]=a[1][0]*b[0][0]+a[1][1]*b[1][0];  
        c[1][1]=a[1][0]*b[0][1]+a[1][1]*b[1][1];*/
        if(n==1)
        {
            vector<int> temp;
            temp.push_back(a[0][0]*b[0][0]);
            c.push_back(temp);
        }
        else if(n<=2){
            for(int i=0;i<n;i++)
            {   vector <int> temp;
                
                temp.push_back(a[i][0]*b[0][0]+a[i][1]*b[1][0]);
                temp.push_back(a[i][0]*b[0][1]+a[i][1]*b[1][1]);
                
                 c.push_back(temp);
            }
            return c;
        }
        else
        {
            vector<vector<int>> a11=split(a,0,n/2-1,0,n/2-1);
            vector<vector<int>> a12=split(a,0,n/2-1,n/2,n-1);
            vector<vector<int>> a21=split(a,n/2,n-1,0,n/2-1);
            vector<vector<int>> a22=split(a,n/2,n-1,n/2,n-1);
            
            vector<vector<int>> b11=split(b,0,n/2-1,0,n/2-1);
            vector<vector<int>> b12=split(b,0,n/2-1,n/2,n-1);
            vector<vector<int>> b21=split(b,n/2,n-1,0,n/2-1);
            vector<vector<int>> b22=split(b,n/2,n-1,n/2,n-1);
            
            vector<vector<int>> p = multiply(add(a11,a22),add(b11,b22),n/2);  //p5
            vector<vector<int>> q = multiply(add(a21,a22),b11,n/2);   //p3
            vector<vector<int>> r = multiply(a11,sub(b12,b22),n/2);  //p1
            vector<vector<int>> s = multiply(a22,sub(b21,b11),n/2);  //p4
            vector<vector<int>> t = multiply(add(a11,a12),b22,n/2);  //p2
            vector<vector<int>> u = multiply(sub(a11,a21),add(b11,b12),n/2);//p7
            vector<vector<int>> v = multiply(sub(a12,a22),add(b21,b22),n/2);  //p6
            
            
            
            /*vector<vector<int>> p1 = add((multiply(a11,b11,n/2)),multiply(a12,b21,n/2));
            vector<vector<int>> p2 = add((multiply(a11,b12,n/2)),multiply(a12,b22,n/2));
            vector<vector<int>> p3 = add((multiply(a21,b11,n/2)),multiply(a22,b21,n/2));
            vector<vector<int>> p4 = add((multiply(a21,b12,n/2)),multiply(a22,b22,n/2));*/
            
            
            vector<vector<int>> p1 = add(add(p,v),sub(s,t));
            vector<vector<int>> p2 = add(r,t);
            vector<vector<int>> p3 = add(q,s);
            vector<vector<int>> p4 = sub(add(p,r),add(u,q));
            
            
            
            for(int i=0;i<n;i++)
            {
                vector <int> temp;
                for(int j=0;j<n;j++)
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
    int r1,c1,r2,c2;
     cout<<"Enter the size of first square matrix\n";
    cin>>r1;
    cout<<"Enter the size of second square matrix\n";
    cin>>r2;
    
    c1=r1;
    c2=r2;
    
    if(c1!=r2)
    cout<<"multiplication not possible"<<endl;
    else
    {
        
        vector <vector<int> > a;
        vector <vector<int> > b;
        int num;
        cout<<"Enter the first matrix"<<endl;
        for(int i=0;i<r1;i++)
        {   vector <int> temp;
            
            for(int j=0;j<c1;j++){
            cin>>num;
            temp.push_back(num);
            }
            a.push_back(temp);
            
        }
        cout<<"Enter the second matrix"<<endl;
        for(int i=0;i<r2;i++)
        {
               vector <int> temp;
            for(int j=0;j<c2;j++)
            {
            cin>>num;
            temp.push_back(num);
            }
            b.push_back(temp);
            
        }
        cout<<"The product of the two matrices:\n";
        vector<vector<int>> P=multiply(a,b,r1);
        display(P);
        
    }
    return 0;
}
//Recurrence relation T(n)=7T(N/2)+O(n^2)








