#include <cstdlib>
#include <iostream>
using namespace std;

struct Point{
    int x,y,z;
};

Point p[54];
int a[5][5][5];
int cosa=0,sina=1;
string tag="";

void translate(int tx, int ty, int tz){
    int i;
    for(i=0;i<54;i++){
      p[i].x+=tx;
      p[i].y+=ty;
      p[i].z+=tz;
    }
}

void tranX(){
    Point pt;
    translate(-2,-2,-2);
    for(int i=0;i<54;i++){
      pt=p[i];
      p[i].x=pt.x;
      p[i].y=pt.y*cosa-pt.z*sina;
      p[i].z=pt.y*sina+pt.z*cosa;
    }
    translate(2,2,2); 
}

void tranY(){
    Point pt;
    translate(-2,-2,-2);
    for(int i=0;i<54;i++){
      pt=p[i];
      p[i].x=pt.z*sina+pt.x*cosa;
      p[i].y=pt.y;
      p[i].z=pt.z*cosa-pt.x*sina;
    }
    translate(2,2,2);
}

void tranZ(){
    Point pt;
    translate(-2,-2,-2);
    for(int i=0;i<54;i++){
      pt=p[i];
      p[i].x=pt.x*cosa-pt.y*sina;
      p[i].y=pt.x*sina+pt.y*cosa;
      p[i].z=pt.z;
    }
    translate(2,2,2);
}

string getStr(){
    string str="";
    for(int i=0;i<54;i++)
      str.push_back(a[p[i].x][p[i].y][p[i].z]+'0');
    return str;
}

string test(){
    int i,j;
    string str;
    for(i=0;i<4;i++){
      for(j=0;j<4;j++){
        str=getStr();
        if(str==tag)
          return "Same";
        tranX();
      }
      tranY();
    }
    for(i=0;i<4;i++){
      if(i%2==1){
        for(j=0;j<4;j++){
          str=getStr();
          if(str==tag)
            return "Same";
          tranX();
        }
      }
      tranZ();
    }
    return "Not Same";
}

int main(int argc, char *argv[])
{
    int x,y,z;
    int i,j,k=0;
    
    for(z=1;z<=3;z++){
      for(y=1;y<=3;y++){
        p[k].x=4;
        p[k].y=y;
        p[k].z=z;
        p[k+9].x=0;
        p[k+9].y=y;
        p[k+9].z=z;
        k++;
      }
    }
    k+=9;
    for(x=3;x>=1;x--){
      for(y=1;y<=3;y++){
        p[k].x=x;
        p[k].y=y;
        p[k].z=4;
        p[k+9].x=x;
        p[k+9].y=y;
        p[k+9].z=0;
        k++;
      }
    }
    k+=9;
    for(z=1;z<=3;z++){
      for(x=3;x>=1;x--){
        p[k].x=x;
        p[k].y=0;
        p[k].z=z;
        p[k+9].x=x;
        p[k+9].y=4;
        p[k+9].z=z;
        k++;
      }
    }
    
    k=0;
    for(i=0;i<6;i++){
      for(j=0;j<9;j++){
        scanf("%d", &a[p[k].x][p[k].y][p[k].z]);
        k++;
      }
    }
    for(i=0;i<54;i++){
      scanf("%d", &k);
      tag.push_back(k+'0');
    }
    cout<<test()<<endl;
    
    return 0;
}
