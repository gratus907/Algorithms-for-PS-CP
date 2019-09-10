struct SegTree
{
	int n;
	vector<int> segtree;

	SegTree(const vector<int> &data)
	{
		n = data.size();
		segtree.resize(4 * n);
		initialize(data, 0, n - 1, 1);
	}
	int initialize(const vector<int> &data, int l, int r, int node)
	{
		if (l == r)
			return segtree[node] = data[l];
		int mid = (l + r) / 2;
		int ls = initialize(data, l, mid, node * 2);
		int rs = initialize(data, mid + 1, r, node * 2 + 1);
		return segtree[node] = ls + rs;
	}
	void update(int ind, int diff){update(0,n-1,1,ind,diff);}
	void update(int left, int right, int node, int ind, int diff)
	{
		if (ind < left || ind > right)
			return;
		segtree[node] += diff;
		if (left != right)
		{
			int mid = (left + right) / 2;
			update(left, mid, node * 2, ind, diff);
			update(mid +1,right, node * 2 +1, ind, diff);
		}
	}
	int sum(int l, int r){return sum(l,r,1,0,n-1);}
	int sum(int l, int r, int node, int nodeleft, int noderight)
	{
		if (r < nodeleft || noderight < l)
			return 0;
		if (l <= nodeleft && noderight <= r)
			return segtree[node];
		int mid = (nodeleft + noderight) / 2;
		return sum(l,r,node*2,nodeleft,mid) + sum(l,r,node*2+1,mid+1,noderight);
	}
};
