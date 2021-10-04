#include <iostream>
#include <stdlib.h>
using namespace std;

class element{
public:
    int i;
    int j;
    int x;
};

class sparce{
        int m;
        int n;
        int num;
        element *e;
    public:
        sparce(int m,int n,int num){
            this->n=n;
            this->m=m;
            this->num=num;
            e = new element [this->num]; 
        }

        ~sparce(){
            delete [] e;
        }
        
        friend istream & operator>>(istream &is , sparce &s);           //void get();
        friend ostream & operator<<(ostream &os , sparce &s);           //void display();

        sparce operator + (sparce &s);                                  //sparce add(sparce s);
};

istream & operator>>(istream &is , sparce &s)                           //void  sparce::get()
{
    int i;
    cout << "Enter non zero elements:- "<<endl;
    for(i=0;i<s.num;i++){
        cin>>s.e[i].i>>s.e[i].j>>s.e[i].x;
    }
    return is;
}

ostream & operator<<(ostream &os , sparce &s)                           //void sparce::display()
{
    int i,j;
    int k=0;
    for(i=0;i<s.m;i++){
        for(j=0;j<s.n;j++){
            if(i==s.e[k].i && j==s.e[k].j)
                cout<<s.e[k++].x<<" ";
            else
                cout<<"0 ";
        }
        cout<<endl;
    }
    return os;
}

sparce sparce :: operator + (sparce &s)                                //sparce sparce :: add(sparce s)
{
    int i,j,k;
    i=j=k=0;

    if(n!=s.n || m!=s.m)
        return sparce(0,0,0);

    sparce *sum=new sparce(m,n,num+s.num);

    while(i<num && j<s.num){
        if(e[i].i<s.e[j].i)
            sum->e[k++]=e[i++];
        else if(e[i].i>s.e[j].i)
            sum->e[k++]=s.e[j++];
        else{
            if(e[i].j<s.e[j].j)
                sum->e[k++]=e[i++];
            else if(e[i].j>s.e[j].j)
                sum->e[k++]=s.e[j++];
            else{
                sum->e[k]=e[i];
                sum->e[k++].x=e[i++].x+s.e[j++].x;
            }
        }
    }
    for(;i<num;i++)
        sum->e[k++]=e[i];
    for(;j<s.num;j++)
        sum->e[k++]=s.e[j];
    sum->num=k;

    return *sum;
}

int main(){
    sparce s1(3,4,3);
    sparce s2(3,4,4);
    

    cin>>s1;                                                        //s1.get();
    cin>>s2;                                                        //s2.get();
    cout<<"MATRIX 1 :- "<<endl;
    cout<<s1;                                                       //s1.display();
    cout<<"MATRIX 2 :- "<<endl;
    cout<<s2;                                                       //s2.display();
    sparce sum = s1 + s2;                                           //s2.add(s1);
    cout<<"MATRIX 3 (SUM) :- "<<endl;
    cout<<sum<<endl;                                                //sum.display();
    return 0;
}