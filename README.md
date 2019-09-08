## 团伙题 
A1034 
2019年春季第三题
存储方式：邻接矩阵，邻接表，邻接矩阵最大为1000 x 1000 x 64 B
1. 确定团伙：可以使用dfs, union find
- union find 一般要求数据从1-N 进行编号，如果编号为字符串，可以使用map进行映射。进行union find 之后，key 为 root，使用map 来标识每个团伙。然后将团伙导入到vector中进行排序
- 如果团伙中两个节点有1-->2的关系，一般使用邻接矩阵存储
-  使用dfs 一般适合用邻接表来存储的题目

## dfs 与 bfs 
- dfs 适用于找路径的题目
- dfs 可以用来判断图的连通性
- bfs 适用于有前后依赖关系的题目(如A1076 转发微博）

## 当不回头的时候，dfs不用标记visited
## 建树
- 建树的时候可以存储很多信息 (如2019年春季第四题）

## 判断是否为完全二叉树
- A1110

## 数据没读完就break

## 递归结束时要return
## 第一题多为暴力破解题，多想想机械的方法
- 如狼人杀
## 对于题目的限制条件，先列出来，程序一一执行
## 分叉路口问题
- 每次dfs push 都要接着 pop

## 对于字符串问题，有两种做法
- 使用两次 for
- 在字符串变化的时候，进行读入，所以一般在末尾加一个字符‘*’， 表示将最后的读入

## 排名问题
- A1140
- 前一次分数与后一次相同，则排名相同
- 若分数不同，则与循环当前次数有关
-  一定要注意排名的条件
- 
## 二维数组在确定是否连接这方面很有优势，当数据量小的时候，可以使用，比map好
- A1142

## lowest common ancestor
- 可以使用递归写
- 也可以dfs 找出路径，然后比较

## 读数据的时候，多分析，存储，可以加快程序

## 图的路径问题，使用map来去重复
## 集合的交集问题
## 给的图有时候并不连通，要注意
## 二次探针法：公式，(a + step * step) % Tsize // 0 <= step < Tsize
A1145
## unorderedmap
## 下一次循环，数据要更新
## 
## tolower() toupper()
## isdigit()
## isalpha()
## getline(cin, s) 与 getchar() 搭配使用
## sscanf(s, form, output)
## floor() ceil() round()

