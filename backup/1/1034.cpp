#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;

string dst = "Begin the Escape execution at the Break of Dawn";
bool hash[331077];
int hsize = 331077;

int hashcode(const string &tx)
{
	int i,hash=0,len=tx.length();
	for(i=0; i<len; ++i)
		hash+=tx[i]*i;
	return abs(hash)%hsize;
}

bool possible(const string &tx){
	int i=-1,j,len=tx.length();
	do{
		for(j=i+1; j<len; ++j)
			if(tx[j]=='C'||tx[j]=='O'||tx[j]=='W')
				break;
		if(j!=i+1&&dst.find(tx.substr(i+1,j-i-1))==-1)
			return false;
		i=j;
	}while(i!=len);
	return true;
}

bool query(const string &tx)
{
	int code=hashcode(tx);
	if(hash[code])
		return false;
	hash[code]=true;

	if(tx==dst) return true;
	if(!possible(tx)) return false;
	
	int i,k,len=tx.length();
	char buff[76];
	buff[len-3]='\0';
	for(int o=1; o<len-1; ++o){
		if(tx[o]=='O'){
			for(int c=0; c<o; ++c){
				if(tx[c]=='C'){
					for(int w=len-1; w>o; --w){
						if(tx[w]!='W')
							continue;
						k=0;
						for(i=0; i<c; ++i) buff[k++]=tx[i];
						for(i=o+1; i<w; ++i) buff[k++]=tx[i];
						for(i=c+1; i<o; ++i) buff[k++]=tx[i];
						for(i=w+1; i<len; ++i) buff[k++]=tx[i];
						if(query(buff))
							return true;
					}
				}
			}
		}
	}
	return false;
}

int main(int argc, char* argv[])
{
	string str;
	char buff[76];
	int n, m;
	int c, o, w;

	gets(buff);
	str = buff;
	n = dst.length();
	m = str.length();
	c = count(str.begin(), str.end(), 'C');
	o = count(str.begin(), str.end(), 'O');
	w = count(str.begin(), str.end(), 'W');

	if (c != o || o != w || n + 3 * c != m || !query(str))
		printf("0 0\n");
	else
		printf("1 %d\n", c);

	return 0;
}
