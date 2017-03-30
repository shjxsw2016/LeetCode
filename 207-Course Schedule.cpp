/*
这个题目就是 “排序” 具有依赖关系的课程，看是否可以上完所有的课程，等价于所有的课程是否可以进行拓扑排序。

把每个课程看做一个顶点，课程之间的依赖关系看做一条有向边，就构成了一个有向图。而该有向图能不能拓扑排序，取决于有向图中是否存在环。
*/
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> a;
		vector<vector<int>> graph(numCourses, a);//构造图
		vector<int> in(numCourses, 0);//保存每个节点的入度
		for (auto c : prerequisites){
			graph[c.second].push_back(c.first); //[1,0],graph[0]=1,表示学完0之后，可以学1
			in[c.first]++; //所以1的入度增加1
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++){
			if (in[i] == 0){
				q.push(i);//把入度为0的节点push进队列
			}
		}
		while (!q.empty()){
			int a = q.front();
			q.pop();
			for (auto g : graph[a]){
				in[g]--;
				if (in[g] == 0) q.push(g);//把入度为0的节点push进队列
			}
		}
		for (int i = 0; i < numCourses; i++){
			if (in[i] != 0)
				return false;
		}
		return true;
	}
};