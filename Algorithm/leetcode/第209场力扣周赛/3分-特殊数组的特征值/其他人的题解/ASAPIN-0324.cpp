typedef long long LL;
typedef double D;
#define all(v) (v).begin(), (v).end()
inline LL fastpo(LL x, LL n, LL mod) {
	LL res(1);
	while(n) {
		if(n & 1) {
			res = res * (LL)x % mod;
		}
		x = x * (LL) x % mod;
		n /= 2;
	}
	return res;
}
LL gcd(LL a, LL b) { return b ? gcd(b, a % b) : a; }
inline string itoa(int x, int width = 0) {
  string res;
  if(x == 0) res.push_back('0');
  while(x) {
    res.push_back('0' + x % 10);
    x /= 10;
  }
  while((int)res.size() < width) res.push_back('0');
  reverse(res.begin(), res.end());
  return res;
}
struct P {
	D x, y;
};
const int mod = 1e9 + 7;
const int inf = 1e9 + 7;
int dx[4] = {1, 0, -1, 0};
int dy[4] = {0, 1, 0, -1};
#define fi first
#define se second
#define ins insert
#define pb push_back

class Solution {
public:
    int specialArray(vector<int>& a) {
        sort(all(a));
        int ans = -1;
        int n = a.size();
        for(int i = 0; i <= n; i++) {
            if(i == (a.end() - lower_bound(all(a), i))) ans = i;
        }
        return ans;
    }
};