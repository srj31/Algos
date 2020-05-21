#include<bits/stdc++.h>
using namespace std;

struct pt{
	int x,y;

	bool operator <(pt b)const{
		return x<b.x || (x==b.x && y<b.y);
	}
};

double area(pt a, pt b, pt c){
	return a.x*(b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y - b.y);
}

vector<pt> convexHull(vector<pt>pts){
	int n = pts.size();
	pt pt1 = pts[0];
	pt pt2 = pts[n-1];
	vector<pt> up,down;
	up.push_back(pt1);
	down.push_back(pt1);
	for(int i =1;i<n;i++){
		if(i==pts.size()-1 || area(pt1,pts[i],pt2)<0){
			while(up.size()>=2 && area(up[up.size()-2],up[up.size()-1],pts[i])>=0)
				up.pop_back();
			up.push_back(pts[i]);

		}
		if(i==pts.size()-1 || area(pt1,pts[i],pt2)>0){
			while(down.size()>=2 && area(down[down.size()-2], down[down.size()-1],pts[i])<=0)
				down.pop_back();
			down.push_back(pts[i]);
		}
	}	
	vector<pt>hull;
	for(int i =0;i<up.size();i++)
		hull.push_back(up[i]);
	for(int i = down.size()-2;i>0;i--){
		hull.push_back(down[i]);
	}
	return hull;

}


double dist(pt a, pt b){
	return hypot(a.x-b.x, a.y-b.y);
}

double dia(vector<pt> hull){

	int n = hull.size();
	if(n==2){
		return dist(hull[0],hull[1]);
	}
	int k = 1;
	while(abs(area(hull[n-1],hull[0],hull[(k+1)%n])) > abs(area(hull[n-1],hull[0],hull[k])))
		k++;

	double res=  0;
	for(int i =0,j=k;i<=k && j<n;i++){
		res = max(res, dist(hull[i],hull[j]));
		while(j<n && (abs(area(hull[i],hull[(i+1)%n],hull[(j+1)%n])) > abs(area(hull[i],hull[(i+1)%n],hull[j])))){
			res = max(res,dist(hull[i],hull[(j+1)%n]));
			j++;

		}
	}
	return res;
}

int main(){
	int n;
	cin >> n;
	vector<pt> pts(n);
	for(int i =0;i<n;i++){
		cin >> pts[i].x >> pts[i].y;
	}

	sort(pts.begin(),pts.end());

	vector<pt> hull = convexHull(pts);
	double ans = dia(hull);
	cout << fixed << setprecision(6) << ans << endl;
}