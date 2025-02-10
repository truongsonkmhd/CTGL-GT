#include<bits/stdc++.h>
using namespace std;

int n;
char s[100100];

void Input() {
	freopen("C:\\Users\\DUC VU\\Downloads\\bin\\input.txt","r",stdin);
	freopen("C:\\Users\\DUC VU\\Downloads\\bin\\output.txt","w",stdout);
	scanf("%d", &n);
	scanf("%s", s);
}

int pow_mod(int n, int k, int m) {
	if(k == 0)
		return (1 % m);
	if(k == 1)
		return (n % m);
	int b = pow_mod(n, k / 2, m);
	if(k % 2 == 0)
		return (b * b) % m;
	return (b * b * n) % m;
}

struct Node {
	int v, l;
	Node() {}
	Node(int _v, int _l) {
		v = _v;
		l = _l;
	}
};

Node operator+(Node a, Node b) {
	return Node((a.v * pow_mod(2, b.l, 3) + b.v) % 3, a.l + b.l);
}

Node T[400400];

void update(int id, int l, int r, int x, int v) {
	if(x < l || r < x)
		return;
	if(l == r) {
		T[id] = Node(v, 1);
		return;
	}
	int mid = (l + r) / 2;
	update(id * 2, l, mid, x, v);
	update(id * 2 + 1, mid + 1, r, x, v);
	T[id] = T[id * 2] + T[id * 2 + 1];
}

Node get(int id, int l, int r, int L, int R) {
	if(r < L || R < l)
		return Node(0, 0);
	if(L <= l && r <= R)
		return T[id];
	int mid = (l + r) / 2;
	return get(id * 2, l, mid, L, R) + get(id * 2 + 1, mid + 1, r, L, R);
}

int ST_RunQuery(int t, int x, int y = -1) {
	if(t == 0) {
		Node ret = get(1, 0, n - 1, x, y);
		return ret.v;
	} else if(t == 1) {
		if(s[x] == '1')
			return 0;
		s[x] = '1';
		update(1, 0, n - 1, x, 1);
		return 1;
	}
	return -1;
}

void ST_Process() {
	for(int i = 0; i < n; i++)
		if(s[i] == '1')
			update(1, 0, n - 1, i, 1);
		else
			update(1, 0, n - 1, i, 0);
	int q;
	scanf("%d", &q);
	while(q --> 0) {
		int t, x, y = -1;
		scanf("%d", &t);
		if(t == 0)
			scanf("%d %d", &x, &y);
		else if(t == 1)
			scanf("%d", &x);
		int ret = ST_RunQuery(t, x, y);
		if(t == 0)
			printf("%d\n", ret);
	}
}
void Xuat(int x = -1){
	cout << x;
}
int main() {
	Input();
	ST_Process();
}
