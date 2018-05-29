#include <iostream>
#include <map>
#include <set>
using namespace std;


struct Node{
    int s;
    int t;
};

map<char,int> mp;
map<char,int> mt;
Node p1[5];
Node p2[5];

bool comp(Node n1, Node n2){
    return n1.s<n2.s;
} 

bool tonghua(Node p[]){
    for(int i=0;i<4;i++)
      if(p[i].t!=p[i+1].t)
        return false;
    return true;
}

bool shunzi(Node p[]){
    for(int i=0;i<4;i++)
      if(p[i].s+1!=p[i+1].s)
        return false;
    return true;
}

int main()
{
    int i,val;
    char s,t;
    
    mp['J']=11;
    mp['Q']=12;
    mp['K']=13;
    mp['A']=14;
    mt['S']=4;
    mt['H']=3;
    mt['C']=2;
    mt['D']=1;
    
    for(i=0;i<5;i++){
      scanf(" %c", &s);
      if(isalpha(s)){
         p1[i].s=mp[s];
      }
      else{
         ungetc(s,stdin);
         scanf("%d", &val);
         p1[i].s=val;
      }
      scanf("%c", &t);
      p1[i].t=mt[t];
    }
    
    for(i=0;i<5;i++){
      scanf(" %c", &s);
      if(isalpha(s)){
         p2[i].s=mp[s];
      }
      else{
         ungetc(s,stdin);
         scanf("%d", &val);
         p2[i].s=val;
      }
      scanf("%c", &t);
      p2[i].t=mt[t];
    }
    
    sort(p1,p1+5,comp);
    sort(p2,p2+5,comp);
    // 1
    if(tonghua(p1)&&tonghua(p2)){
       bool tag1=shunzi(p1);
       bool tag2=shunzi(p2);
       if(tag1&&tag2){
          if(p1[4].s!=p2[4].s){
             if(p1[4].s>p2[4].s)
               printf("Player1 Win\n");
             else
               printf("Player2 Win\n");
          }
          else{
             if(p1[4].t>p2[4].t)
               printf("Player1 Win\n");
             else
               printf("Player2 Win\n");
          }
          return 0;
       }
       else if(tag1){
          printf("Player1 Win\n");
          return 0;
       }
       else if(tag2){
          printf("Player2 Win\n");
          return 0;
       }
    }
    
    // 2
       map<int,int> ma1;
       map<int,int> ma2;
       for(i=0;i<5;i++)
         ma1[p1[i].s]++;
       for(i=0;i<5;i++)
         ma2[p2[i].s]++;
         
       int c1=ma1[p1[2].s];
       int c2=ma2[p2[2].s];
       if(c1==4&&c2==4){
          if(p1[2].s>p2[2].s)
            printf("Player1 Win\n");
          else
            printf("Player2 Win\n");
          return 0;
       }
       else if(c1==4){
          printf("Player1 Win\n");
          return 0;
       }
       else if(c2==4){
          printf("Player2 Win\n");
          return 0;
       }
    
    // 3
      int d3=-1, d2=-1, dz=-1;
    int f3=-1, f2=-1, fz=-1;
    for(i=0;i<5;i++){
       if(ma1[p1[i].s]==3){
          d3=p1[i].s;
          if(p1[i].t>dz)
            dz=p1[i].t;
       }
       if(ma1[p1[i].s]==2)
          d2=p1[i].s;
    }
    for(i=0;i<5;i++){
       if(ma2[p2[i].s]==3){
          f3=p2[i].s;
          if(p2[i].t>fz)
            fz=p2[i].t;
       }
       if(ma2[p2[i].s]==2)
          f2=p2[i].s;
    }
    if(d3!=-1&&d2!=-1&&f3!=-1&&f2!=-1){
       if(d3!=f3){
          if(d3>f3)
            printf("Player1 Win\n");
          else
            printf("Player2 Win\n");
       }                        
       else{
          if(d2!=f2){
             if(d2>f2)
               printf("Player1 Win\n");
             else
               printf("Player2 Win\n");
          }
          else{
             if(dz>fz)
               printf("Player1 Win\n");
             else
               printf("Player2 Win\n");
          }
       } 
       return 0;
    } 
    else if(d3!=-1&&d2!=-1){
       printf("Player1 Win\n");
       return 0;
    }
    else if(f3!=-1&&f2!=-1){
       printf("Player2 Win\n");
       return 0;
    }
    
    
    // Í¬»¨ 
    if(tonghua(p1)&&tonghua(p2)){
       if(p1[4].s!=p2[4].s){
          if(p1[4].s>p2[4].s)
            printf("Player1 Win\n");
          else
            printf("Player2 Win\n");
       }
       else{
          if(p1[4].t>p2[4].t)
            printf("Player1 Win\n");
          else
            printf("Player2 Win\n");
       }
       return 0;
    }
    else if(tonghua(p1)){
       printf("Player1 Win\n");
       return 0;
    } 
    else if(tonghua(p2)){
       printf("Player2 Win\n");
       return 0;
    }
    
   
    
    
    // 4
    if(shunzi(p1)&&shunzi(p2)){
       if(p1[4].s!=p2[4].s){
          if(p1[4].s>p2[4].s)
            printf("Player1 Win\n");
          else
            printf("Player2 Win\n");
       }
       else{
          if(p1[4].t>p2[4].t)
            printf("Player1 Win\n");
          else
            printf("Player2 Win\n");
       }
       return 0;
    }
    else if(shunzi(p1)){
       printf("Player1 Win\n");
       return 0;
    }
    else if(shunzi(p2)){
       printf("Player2 Win\n");
       return 0;
    }
    
    
    // 5
    c1=ma1[p1[2].s];
    c2=ma2[p2[2].s];
    if(c1==3&&c2==3){
       if(p1[2].s>p2[2].s)
         printf("Player1 Win\n");
       else
         printf("Player2 Win\n");
       return 0;
    }
    else if(c1==3){
       printf("Player1 Win\n");
       return 0;
    }
    else if(c2==3){
       printf("Player2 Win\n");
       return 0;
    }
    
    
    //  6
    set<int> st1;
    set<int> st2;
    int z1=-1, z2=-1;
    for(i=0;i<5;i++){
       if(ma1[p1[i].s]==2){
          st1.insert(p1[i].s);
          if(p1[i].t>z1)
            z1=p1[i].t;
       }
    } 
    for(i=0;i<5;i++){
       if(ma2[p2[i].s]==2){
          st2.insert(p2[i].s);
          if(p2[i].t>z2)
            z2=p2[i].t; 
       }
    }
    if(st1.size()==2&&st2.size()==2){
       set<int>::iterator it1=st1.begin();
       set<int>::iterator it2=st2.begin();
       if(*it1!=*it2){
          if(*it1>*it2)
            printf("Player1 Win\n");
          else
            printf("Player2 Win\n");
       }
       else{
          it1++;
          it2++;
          if(*it1!=*it2){
             if(*it1>*it2)
               printf("Player1 Win\n");
             else
               printf("Player2 Win\n"); 
          } 
          else{
             if(z1>z2)
               printf("Player1 Win\n");
             else
               printf("Player2 Win\n");
          }
       }
       return 0;
    }
    else if(st1.size()==2){
       printf("Player1 Win\n");
       return 0;
    }
    else if(st2.size()==2){
       printf("Player2 Win\n");
       return 0;
    }
    
    // 7
    int v1,m1=-1;
    int v2,m2=-1;
    for(i=0;i<5;i++){
      if(ma1[p1[i].s]==2){
        v1=p1[i].s;
        if(p1[i].t>m1)
          m1=p1[i].t;
      }
    }
    for(i=0;i<5;i++){
      if(ma2[p2[i].s]==2){
        v2=p2[i].s;
        if(p2[i].t>m2)
          m2=p2[i].t;
      }
    }
    if(m1!=-1&&m2!=-1){
       if(v1!=v2){
         if(v1>v2)
           printf("Player1 Win\n");
         else
           printf("Player2 Win\n");
       }
       else{
         if(m1>m2)
           printf("Player1 Win\n");
         else
           printf("Player2 Win\n"); 
       }
       return 0;
    }
    else if(m1!=-1){
       printf("Player1 Win\n");
       return 0;
    }
    else if(m2!=-1){
       printf("Player2 Win\n");
       return 0;
    } 
    
    
    // 8
    if(p1[4].s!=p2[4].s){
       if(p1[4].s>p2[4].s)
         printf("Player1 Win\n");
       else
         printf("Player2 Win\n");
    }
    else{
       if(p1[4].t>p2[4].t)
         printf("Player1 Win\n");
       else
         printf("Player2 Win\n");
    }
    
    
    return 0;
}
