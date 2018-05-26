
## uva10474
<p>iterator lower_bound(iterator begin, iterator end, T val)：查找大于或等于val的第一个位置</p>
<p>iterator upper_bound(iterator begin, iterator end, T val)：查找小于或等于val的最后一个位置</p>

## uva10815
```c++
    char c;
    cin >> c;       // 会忽略空格
    c = getchar();  // 不会忽略空格
```

## uva12096
<p>首先说下思路</p>
<p>这道题的玩法让我有一种想写`set<set<...>>`的冲动，不过凭借之前看过紫书的残留记忆，想到了递归定义</p>
<p>使用数字来代表集合以及集合的集合，以及更深一层的递归定义</p>
<p>0代表{}，1代表{{}}的话，那么{{},{{}}}={0,1}，更进一步，令2代表{0,1}，那么就可以做到数字与集合之间的一一映射</p>
<p>这种一一映射完全由输入的操作顺序决定，输入的操作顺序不同，数字代表的集合也不同</p>

操作 | 逻辑栈 | 栈 | 数字<->集合
---- | ----- | -- | ---------
PUSH | {} | 0 | 0={}
DUP | {},{} | 0,0 | 0={}
ADD | {{}} | 1 | 0={}, 1={{}}={0}
PUSH | {{}},{} | 1,0 | 0={}, 1={{}}={0}
ADD | {{}} | 1 | 0={}, 1={{}}={0}
DUP | {{}},{{}} | 1,1 | 0={}, 1={{}}={0}
ADD | {{},{{}}} | 2 | 0={}, 1={{}}={0}, 2={{},{{}}}={0,1}
DUP | {{},{{}}},{{},{{}}} | 2,2 | 0={}, 1={{}}={0}, 2={{},{{}}}={0,1}
UNION | {{},{{}}} | 2 | 0={}, 1={{}}={0}, 2={{},{{}}}={0,1}

<p>也就是说，存在着这样的关系：数字={数字1,数字2,...,数字n}，而其中的每个数字又代表一个集合</p>
<p>第二点是又学到了一些有用的东西</p>

```c++
#include <algorithm>
iterator set_union(iterator a, b, c, d, e); // 在e迭代器上插入[a,b)与[c,d)的并集, 返回最后一个插入的迭代器的下一个迭代器
iterator set_intersection(iterator a, b, c, d, e); // 在e迭代器上插入[a,b)与[c,d)的交集, 返回最后一个插入的迭代器的下一个迭代器
// 类似的还有set_difference，set_symmetric_difference
#include <iterator>
iterator inserter(容器名,容器内部的某个迭代器) 
/* 不断调用容器的insert操作，这样在set_union以及类似方法时
 * 令形参e=insert(v, v.begin())，这样容器v就不必预分配空间（否则会出现不能赋值给常量的错误）
 */
```

<p>第三点是惊奇的发现stack是没有clear方法的，替代方法有两种，一个是不断pop直到空，另一种是直接赋给一个新的stack</p>

## uva540
原来的思路是这样的：

```
Enqueue x:
    hashx = hash1(x)
    idx = hash2(hashx)
    queue[idx].push(x) // queue: deque<std::queue<int>>
```
<p>也就是说，使用两层哈希找到x在queue中应该在的位置。然而实现之后发现，hash2这个map&lt;int,int&gt;并不能随着queue的变化而变化</p>
<p>随后理清思路，可以发现使用team的编号来串联一切。整个队列中，相同team的元素肯定是团在一起的。于是整个队列也就是编号的队列（queue&lt;int&gt;），而每个编号既可以代表这个团队（map&lt;int,int&gt;），也可以代表当前队列里这个团队的队列（我采用map&lt;int,queue&lt;int&gt;&gt;, 紫书用的是queue&lt;int&gt;[]）</p>

## uva136
<p>没有输入的题目，直接cout完事……</p>
<p>思路：声明一个越小的数优先度越高的优先队列</p>

```c++
priority_queue<long long, vector<long long>, greater<long long> > q;
// 模板参数里，long long代表类型，vector<long long>代表容器（默认缺省，但要改变优先度就要填上）
/* greater是一个functor，中文叫做仿函数，是一个重载了()运算符的类或者结构体，我们甚至能自己定义比较函数
struct cmp {
    bool operator() (T a, T b);
}
常见的functor有less,greater等等
*/
```
<p>有了优先队列之后，我们每次取top，然后push `2*top,3*top,4*top`，等到1500次之后，取top就是答案</p>

## uva400
<p>紫书上有些代码确实出乎我的意料，靠左输出没有用ios以及iomanip头文件里的流操作符，而是自己定义一个输出函数</p>
<p>另外一个就是`ceil((double)n/c)`可以用`(n-1)/c+1`来处理</p>

# uva1592
https://sites.google.com/view/oyz/%E9%A6%96%E9%A1%B5/%E7%B4%AB%E4%B9%A6/%E7%AC%AC5%E7%AB%A0/uva-1592
