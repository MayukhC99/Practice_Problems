#include <bits/stdc++.h>
#define speed ios_base::sync_with_stdio(false)
#define boost cin.tie(NULL)
#define endl "\n"
using namespace std;

int main(){
	
	speed;
	boost;
	
    long n(0), q(0); 
    cin>>n>>q;
    long long *array = new long long[n + 1]; array[0] = 0;
    long long *times = new long long[n + 1]; times[0] = 0;

    for(long k = 1; k <= n; k++){cin>>array[k]; times[k] = 0;}

    long left(0), right(0);
    for(long k = 0; k < q; k++){
        cin>>left>>right;
        ++times[left];
        if(right < n){--times[right + 1];}
    }
    for(long k = 2; k <= n; k++){times[k] += times[k - 1];}

    std::sort(array, array + n + 1); std::sort(times, times + n + 1);
    long long total(0); for(long k = 1; k <= n; k++){total += times[k] * array[k];}

    cout<<total;
    return 0;
}
