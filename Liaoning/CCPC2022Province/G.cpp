#include <bits/stdc++.h>
//#include <ranges>
using namespace std;
#define endl '\n'
#define all(A,i) A.begin()+i, A.end()
#define rep(i,l,r) for(int i=l;i<=r;i++)
#define per(i,r,l) for(int i=r;i>=l;i--)
#define pb push_back
#define dbg(x) cout<<#x<<"="<<x<<endl;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
using cd = complex<double>;
using pii = array<int, 2>;
const int INF=1e9+7;
const int MOD=1e9+7;
const int MAXX=200000,LIMIT=20;
const double eps=1e-6;
const double PI = acos(-1);
int dx[]={0,0,1,-1}, dy[]={1,-1,0,0};
int dx8[]={0,0,1,1,1,-1,-1,-1}, dy8[]={1,-1,-1,0,1,-1,0,1};

//快读
int read(){
    bool flag = false;
    int ans = 0;
    char c = getchar();
    while(c < '0' || c > '9') {
        if(c == '-') flag = true;
        c = getchar();
    }
    while(isdigit(c)){
        ans = ans * 10 + c - '0';
        c = getchar();
    }
    return flag ? -ans : ans;
}
//快写
void write(ll x){
    if(x == 0){
        putchar('0');
        return;
    }
    if(x < 0){
        putchar('-');
        x = -x;
    }
    char ch[50];
    int index = 0;
    while(x){
        ch[index++] = x % 10 + '0';
        x /= 10;
    }
    for(int i = index - 1; i >= 0; i--) {
        putchar(ch[i]);
    }
}
array<int, MAXX> st;
int top;

void solve()
{
	int op = read();
	if(op == 1) {
		int x = read();
		st[++top] = x;
	}
	if(op == 2) {
		top--;
	}
	if(op == 3) {
		// dbg(top)
		cout << st[top] << endl;
	}
	if(op == 4) {
		int k; k = read();
		int g = 0;
		for(int i = 1; i <= k; i++) {
			g = gcd(g, st[top - i + 1]);
			if(g == 1) break;
		}
		for(int i = 1; i <= k; i++) {
			st[top - i + 1] = g;
		}
	}
}






signed main() {
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);

	int t=1;
	t = read();
	while(t--){
	
		solve();
	
	}
	return 0;
}
// 难道我不配AC吗
//   ▄████  █    ██  ▄▄▄██▀▀▀██▓ █    ██
//  ██▒ ▀█▒ ██  ▓██▒   ▒██  ▓██▒ ██  ▓██▒
// ▒██░▄▄▄░▓██  ▒██░   ░██  ▒██▒▓██  ▒██░
// ░▓█  ██▓▓▓█  ░██░▓██▄██▓ ░██░▓▓█  ░██░
// ░▒▓███▀▒▒▒█████▓  ▓███▒  ░██░▒▒█████▓
//  ░▒   ▒ ░▒▓▒ ▒ ▒  ▒▓▒▒░  ░▓  ░▒▓▒ ▒ ▒
//   ░   ░ ░░▒░ ░ ░  ▒ ░▒░   ▒ ░░░▒░ ░ ░
//  ░   ░  ░░░ ░ ░  ░ ░ ░   ▒ ░ ░░░ ░ ░
//       ░    ░      ░   ░   ░     ░