#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
int main() {
int m;
cin >> m;
while (m--) {
	int n,x;
	bool flag = false;
	cin >> n >> x;
	unordered_set<int>s;
	//vector<int>a(n);
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		if (s.count(x - num) != 0) {
			flag = true;
		}
		s.insert(num);
	}
	//for (int i = 0; i < x; i++) {
	//	if(s.count(i)!=0&&s.count(x-i)!=0){
	//		//cout << i << ' ' << a[i] << endl;
	//		flag = true;
	//		break;
	//	}
	//}
	cout << (flag ? "yes" : "no") << endl;
	}
}