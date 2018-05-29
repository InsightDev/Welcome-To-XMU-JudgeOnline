#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cmath>
using namespace std;

bool bound(int rx, int ry){
    return (rx>=0&&rx<=1000&&ry>=0&&ry<=1000);
}

double distance(double x0, double y0, double x1, double y1){
    return sqrt((x1-x0)*(x1-x0)+(y1-y0)*(y1-y0));
}

bool check(double x0, double y0, double r0, double x1, double y1, double ds){
    double rx,ry,rate,dist;
    double a,b,c,cond;
    dist=distance(x0,y0,x1,y1);
    if(dist>=r0)
        return true;
    if(x0==x1&&y0==y1)
        return ds>=r0;

    rate=r0/dist;
    rx=x0+(x1-x0)*rate;
    ry=y0+(y1-y0)*rate;
    if(bound(rx,ry)&&distance(rx,ry,x1,y1)<=ds)
        return true;
    
    double x[]={0,1000};
    for(int i=0; i<2; i++){
        a=1;
        b=-2*y0;
        c=(x[i]-x0)*(x[i]-x0)+y0*y0-r0*r0;
        cond=b*b-4*a*c;
        if(cond>=0){
            rx=x[i];
            ry=(-b+sqrt(cond))/(2*a);
            if(bound(rx,ry)&&distance(rx,ry,x1,y1)<=ds)
                return true;
            ry=(-b-sqrt(cond))/(2*a);
            if(bound(rx,ry)&&distance(rx,ry,x1,y1)<=ds)
                return true;
        }
    }
    double y[]={0,1000};
    for(int i=0; i<2; i++){
        a=1;
        b=-2*x0;
        c=x0*x0+(y[i]-y0)*(y[i]-y0)-r0*r0;
        cond=b*b-4*a*c;
        if(cond>=0){
            ry=y[i];
            rx=(-b+sqrt(cond))/(2*a);
            if(bound(rx,ry)&&distance(rx,ry,x1,y1)<=ds)
                return true;
            rx=(-b-sqrt(cond))/(2*a);
            if(bound(rx,ry)&&distance(rx,ry,x1,y1)<=ds)
                return true;
        }
    }
    return false;
}

int main(int argc, char** argv) {
    int x0,y0,r0;
    int x1,y1,r1;
    int ds;
    
    scanf("%d %d %d", &x0, &y0, &r0);
    scanf("%d %d %d", &x1, &y1, &r1);
    scanf("%d", &ds);
    if(check(x0,y0,r0+r1,x1,y1,ds))
        printf("Yes\n");
    else
        printf("No\n");

    return 0;
}
