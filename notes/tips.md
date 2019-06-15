## 函数

- distance是返回容器中两个地址之间的距离

distance(find(a, a+10, 2), find(a, a+10, 7));

- unique 而是将重复的元素放到容器的末尾，返回值是去重之后的尾地址
- 去重
  ModuleArr.erase(unique(ModuleArr.begin(), ModuleArr.end()), ModuleArr.end());
- 深度优先搜索可能栈溢出，所以使用广度优先搜索

- 坐标离散化

判断 map 中是否存在某 key

pre.**find**(**make_pair**(xx, yy)) == pre.**end**()



用 memset 头文件 cstring

pair 有函数 distance 有可能冲突，注意！

小根堆  priority_queue<P,vector<P>,greater<P> > q;



