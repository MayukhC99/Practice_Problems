#include<bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
typedef long long int lld;

#define F(a,n) for(int i=0;i<n;i++){cin>>a[i];}
#define F1(a,n) for(int i=1;i<=n;i++){cin>>a[i];}

using namespace std;

typedef struct node{
	lld grade;
	lld essay;
}node;

bool compare(node i,node j){
	return i.essay < j.essay ;
}

int main(){
	
	lld n,r,avg,sum=0;
	cin>>n>>r>>avg;
	
	node ar[n];
	
	for(lld i=0;i<n;i++){
		cin>>ar[i].grade;
		cin>>ar[i].essay;
		sum+= ar[i].grade;
	}
	
	sort(ar,ar+n,compare);
	
	double cur_avg= ( (double)sum / (double)n );
	
	if(cur_avg>=avg){
		cout<<0;
		return 0;	
	}
	
	double eq1= ((double)avg-(double)cur_avg);
	double eq2= (1/(double)n);
	double needed= ceil( (eq1 / eq2) - .000001 );
	//cout<<"needed is "<<needed<<endl;
	
	lld essay_count=0;
	for(lld i=0;i<n;i++){
		
		lld less= (r-ar[i].grade);
		if(less >= needed){
			essay_count+= (needed*ar[i].essay);
			needed=0;
			break;
		}
		else {
			essay_count+= (less*ar[i].essay);
			needed-= less;
		}
	}
	
	cout<<essay_count;
	
	return 0;
}

