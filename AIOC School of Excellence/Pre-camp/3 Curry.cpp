//
//  curry.cpp
//  
//
//  Created by Jennivine on 18/11/18.

#include <cstdio>
bool check(int c, int r, int v);
int max(int a, int b, int c);
int min(int a, int b, int c);

int main(){
    freopen("curryin.txt","r",stdin);
    freopen("curryout.txt","w", stdout);
    
    int c,r,v;
    scanf("%d %d %d",&c, &r, &v);
	
	int cr = 0;
	int cv = 0;
	int rv = 0;
	
	while (check(c,r,v)){
		if (min(c,r,v) == c){
			c += 1;
			rv += 1;
		} else if (min(c,r,v) == r){
			r += 1;
			cv += 1;
		} else {
			v += 1;
			cr += 1;
		}
		c--;
		r--;
		v--;
	}
	
	printf("%d %d %d\n",rv,cv,cr);
	
}

bool check(int c, int r, int v){
	return (max(c,r,v) != c+r+v);
}

int max(int a, int b, int c){
	if ((a > b) && (a > c)){
		return a;
	} else if ((b > a) && (b > c)){
		return b;
	} else {
		return c;
	}
}

int min(int a, int b, int c){
	if ((a <= b) && (a <= c)){
		return a;
	} else if ((b <= a) && (b <= c)){
		return b;
	} else {
		return c;
	}
}
