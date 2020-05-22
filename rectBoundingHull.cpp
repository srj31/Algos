#include<bits/stdc++.h>
using namespace std;

struct pt{
	long double x,y;

	bool operator < (pt b) const{
		return x < b.x || (x==b.x && y<b.y);
	}

	long double operator &(pt b) const{
		return x*b.y - y*b.x;
	}

	long double operator *(pt b)const{
		return x*b.x + y*b.y;
	}
	pt operator -(pt b) const{
		pt res;
		res.x = x-b.x;
		res.y = y-b.y;
		return res;
	}

	pt operator /(long double b){
		pt res;
		res.x = x/b;
		res.y = y/b;
		return res;
	}
 };

long double ccw(pt a, pt b, pt c){
	return ((b-a)&(c-a));
}

vector<pt> hull(vector<pt> pts){
	int n = pts.size();
	vector<pt> h;
	if(n==1){
		h.push_back(pts[0]);
	// cerr << "HULL DONE" << endl;

		return h;
	}

	pt p1 = pts[0];
	pt p2 = pts[n-1];
	vector<pt> up,down;
	up.push_back(p1);
	down.push_back(p1);
	for(int i =1;i<n;i++){
		if(i==n-1 || ccw(p1,pts[i],p2)<0){
			while(up.size()>=2 && ccw(up[up.size()-2],up[up.size()-1],pts[i])>=0)
				up.pop_back();
			up.push_back(pts[i]);
		}
		if(i==n-1 || ccw(p1,pts[i],p2)>0){
			while(down.size()>=2 && ccw(down[down.size()-2],down[down.size()-1],pts[i])<=0)
				down.pop_back();
			down.push_back(pts[i]);
		}
	}
	for(int i =0;i<up.size();i++)
		h.push_back(up[i]);
	for(int i = down.size()-2;i>0;i--){
		h.push_back(down[i]);
	}
	// cerr << "HULL DONE" << endl;
	reverse(h.begin(),h.end());
	return h;
}

long double dist(pt a, pt b){
	return sqrt((b-a)*(b-a));
}

pt ccw90(pt a, pt b){
	pt vec = (b-a);
	pt res;
	res.x  = -vec.y;
	res.y = vec.x;
	return res;
}

const long double INF = 1e+30;
void rec(vector<pt> h){
	int l=1,r=1,u=1;
	int n= h.size();
	long double area = INF,per = INF;
	for(int i =0;i<n;i++){
		pt side1 = (h[(i+1)%n] - h[i])/dist(h[(i+1)%n],h[i]);
		while(side1*(h[(r+1)%n]-h[i]) > (side1*(h[r%n]-h[i])))
			r++;
		while(u<r || (side1&(h[(u+1)%n]-h[i])) > (side1&(h[u%n]-h[i])))
			u++;
		while(l<u || (side1*(h[(l)%n] - h[i])) > (side1*(h[(l+1)%n]-h[i])))
			l++;

		long double w = (side1*(h[r%n]-h[i])) - (side1*(h[l%n]-h[i]));
		long double b = fabs((h[i]-h[u%n])&(h[(i+1)%n]-h[u%n]))/dist(h[i],h[(i+1)%n]);
		per = min(per,2*(w+b));
		area = min(area,w*b);
	}
	cout << fixed << setprecision(2) << area << " " << per << endl;
}


int main(){
	while(true){
		int n;
		cin >>n;
		if(n==0)break;
		vector<pt> pts(n);
		for(int i =0;i<n;i++)
			cin >> pts[i].x >> pts[i].y;
		sort(pts.begin(),pts.end());

		vector<pt> h = hull(pts);
		rec(h);
		// cout << fixed << setprecision(9) << ans <<endl;

	}
}