#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
#define inf 1000000000
using namespace std;

struct point{
    void set(double x, double y){
        this->x=x;
        this->y=y;
    }
    double x;
    double y;
}p[82];

struct line{
    void set(point p0, point p1){
        this->p0=p0;
        this->p1=p1;
    }
    point p0;
    point p1;
}l[120];

double a[82][82];
double d[82];
bool v[82];
int pn,ln=0;

double crossproduct(point p0, point p1, point p2){
    double x1=p1.x-p0.x;
    double y1=p1.y-p0.y;
    double x2=p2.x-p0.x;
    double y2=p2.y-p0.y;
    return x1*y2-x2*y1;
}

bool check(point p2, point p3){
    for(int i=0; i<ln; i++){
        double d0=crossproduct(l[i].p0,l[i].p1,p2);
        double d1=crossproduct(l[i].p0,l[i].p1,p3);
        double d2=crossproduct(p2,p3,l[i].p0);
        double d3=crossproduct(p2,p3,l[i].p1);
        if(d0*d1<0&&d2*d3<0)
            return false;
    }
    return true;
}

double dist(point p0, point p1){
    if(!check(p0,p1))
        return inf;
    double dx=p1.x-p0.x;
    double dy=p1.y-p0.y;
    return sqrt(dx*dx+dy*dy);
}

void cgraph(){
    int i,j;
    for(i=0; i<=pn; i++)
    for(j=0; j<=i; j++)
        a[i][j]=a[j][i]=(i==j?0:dist(p[i],p[j]));
}

double dijkstra(){
    int i,j,t;
    double mind;
    for(i=0; i<=pn; i++){
        d[i]=a[0][i];
        v[i]=false;
    }
    v[0]=true;
    for(i=1; i<=pn; i++){
        t=0;
        mind=inf;
        for(j=1; j<=pn; j++){
            if(!v[j]&&d[j]<mind){
                t=j;
                mind=d[j];
            }
        }
        if(t==pn)
            return mind;
        v[t]=true;
        for(j=1; j<=pn; j++)
            if(!v[j]&&d[j]>d[t]+a[t][j])
                d[j]=d[t]+a[t][j];
    }
}

int main(int argc, char** argv) {
    int n,i,k=1;
    double x0,y0,x2,y2;

    scanf("%d", &n);
    pn=4*n+1;
    for(i=1; i<=n; i++){
        scanf("%lf %lf %lf %lf", &x0, &y0, &x2, &y2);
        p[k].set(x0,y0);
        p[k+1].set(x2,y0);
        p[k+2].set(x2,y2);
        p[k+3].set(x0,y2);
        l[ln++].set(p[k],p[k+1]);
        l[ln++].set(p[k+1],p[k+2]);
        l[ln++].set(p[k+2],p[k+3]);
        l[ln++].set(p[k+3],p[k]);
        l[ln++].set(p[k],p[k+2]);
        l[ln++].set(p[k+1],p[k+3]);
        k+=4;
    }
    scanf("%lf %lf %lf %lf", &p[0].x, &p[0].y, &p[pn].x, &p[pn].y);

    cgraph();
    printf("%.9f\n", dijkstra());

    return 0;
}
