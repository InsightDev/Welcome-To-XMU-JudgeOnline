#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <iostream>
using namespace std;

#define PI 3.1415926535898

double area(double radius){
	return PI*radius*radius;
}

double distance(double x0, double y0, double x1, double y1){
	double dx=x1-x0;
	double dy=y1-y0;
	return sqrt(dx*dx+dy*dy);
}

double cover(double x0, double y0, double r0, double x1, double y1, double r1){
	double dist=distance(x0,y0,x1,y1);
	double cosa,cosb,a,b;
	double minr=min(r0,r1);
	double maxr=max(r0,r1);
	if(dist>=r0+r1)
		return 0;
	if(dist+minr<=maxr)
		return area(minr);
	cosa=(r0*r0+dist*dist-r1*r1)/(2*r0*dist);
	cosb=(r1*r1+dist*dist-r0*r0)/(2*r1*dist);
	a=acos(cosa);
	b=acos(cosb);
	return r0*r0*a+r1*r1*b-0.5*r0*r0*sin(2*a)-0.5*r1*r1*sin(2*b);
}

int main(int argc, char** argv) {
	int x0,y0,r0,x1,y1;
	double low,high,mid;
	double dest,tmp;

	scanf("%d %d %d", &x0, &y0, &r0);
	scanf("%d %d", &x1, &y1);
	dest=pi*r0*r0*2/3;

	low=0;
	high=distance(x0,y0,x1,y1)+r0;
	while(true){
		mid=(low+high)/2;
		tmp=cover(x0,y0,r0,x1,y1,mid);
		if(abs(tmp-dest)<=0.000001)
			break;
		else if(tmp<dest)
			low=mid;
		else
			high=mid;
	}
	printf("%.6f\n", mid);

	return 0;
}
