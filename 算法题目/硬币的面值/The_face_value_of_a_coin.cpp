#include <iostream>
#include <algorithm>

using namespace std;

long long n, m, a[2000002], ans, tot;

int main(){
    cin>>n>>m;
	for(int i = 1; i <= n; i++)
		cin>>a[i];
	sort(a + 1, a + n + 1);
	if(a[1] != 1) {
        cout<<"No answer!!!"<<endl;
		return 0;
	}
	a[n + 1] = m;
	for(int i = 1; i <= n; i++){
		if(tot < a[i + 1] - 1){
			long long k = (a[i + 1] - 2 - tot) / a[i] + 1;
			tot += a[i] * k;
			ans += k;
			if(tot >= m){
                cout<<ans<<endl;
				return 0;
			}
		}
	}
    cout<<ans+1<<endl;
	return 0;
} 