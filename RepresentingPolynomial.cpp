#include <iostream>
using namespace std;

//  n(term)=5;
//  cofficient  3 2 5 6 7
//  exp         5 4 3 1 0

struct term{
    int c;
    int e;
};

struct poly{
    int n;
    struct term *t;
};

void create(struct poly *p){
    int i;
    cout<<"enter no of ternm :- "<<endl;
    cin>>p->n;
    p->t=new term[p->n]; 

    if(p->n!=0){
        cout << "Enter coefficient and exponent:- "<<endl;
        for(i=0;i<p->n;i++)
            cin>>p->t[i].c>>p->t[i].e;
    }
}

void display(struct poly p){
    int i,j;
    int k=0;
    for(i=0;i<p.n;i++){
        if(i<p.n-1)
            cout<<p.t[i].c<<"x^"<<p.t[i].e<<"+";
        else
            cout<<p.t[i].c<<"x^"<<p.t[i].e<<endl;
    }
}

struct poly * add(struct poly *s1,struct poly *s2){
    struct poly *sum;
    int i,j,k;
    i=j=k=0;

    sum = (struct poly *)malloc(sizeof(struct poly));  
    sum->t= new term[s1->n+s2->n];
    while(i<s1->n && j<s2->n){
        if(s1->t[i].e<s2->t[j].e)
            sum->t[k++]=s2->t[j++];
        else if(s1->t[i].e>s2->t[j].e)
            sum->t[k++]=s1->t[i++];
        else{
             sum->t[k].e=s1->t[i].e;
             sum->t[k++].c=s1->t[i++].c+s2->t[j++].c;
        }
    }
    for(;i<s1->n;i++)
        sum->t[k++]=s1->t[i];
    for(;j<s2->n;j++)
        sum->t[k++]=s2->t[j];

    sum->n=k;
    return sum;
}

int main(){
    struct poly s1,s2,*s3;

    create(&s1);
    create(&s2);
    s3=add(&s1,&s2);

    cout<<"polynomial 1 "<<endl;
    display(s1);
    cout<<"polynomial 2 "<<endl;
    display(s2);
    cout<<"polynomial 3 (SUM) "<<endl;
    display(*s3);
    return 0;
}