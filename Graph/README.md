# Graph
## Test

[main.cpp](https://github.com/vlyf/DataStructure/blob/master/Graph/main.cpp)

### Constructors

```

```

### Memember Funciton

```
void AddEdge(int v1, int v2);           // 添加连通
Bag* Adjs(int v) const;					// 返回顶点v的list
int Count(int v) const;					// The number of connected with v
bool Connected(int v) const;			// v is connected with start
bool Connected(int v1, int v2) const;	// v1 is connected with v2
int Degree(int v) const;				// 顶点v的度数
int MaxDegree() const;					// 顶点的最大度数
int SelfLoop() const;					// 自环个数
```