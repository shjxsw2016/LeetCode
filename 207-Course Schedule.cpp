/*
�����Ŀ���� ������ ����������ϵ�Ŀγ̣����Ƿ�����������еĿγ̣��ȼ������еĿγ��Ƿ���Խ�����������

��ÿ���γ̿���һ�����㣬�γ�֮���������ϵ����һ������ߣ��͹�����һ������ͼ����������ͼ�ܲ�����������ȡ��������ͼ���Ƿ���ڻ���
*/
class Solution {
public:
	bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
		vector<int> a;
		vector<vector<int>> graph(numCourses, a);//����ͼ
		vector<int> in(numCourses, 0);//����ÿ���ڵ�����
		for (auto c : prerequisites){
			graph[c.second].push_back(c.first); //[1,0],graph[0]=1,��ʾѧ��0֮�󣬿���ѧ1
			in[c.first]++; //����1���������1
		}
		queue<int> q;
		for (int i = 0; i < numCourses; i++){
			if (in[i] == 0){
				q.push(i);//�����Ϊ0�Ľڵ�push������
			}
		}
		while (!q.empty()){
			int a = q.front();
			q.pop();
			for (auto g : graph[a]){
				in[g]--;
				if (in[g] == 0) q.push(g);//�����Ϊ0�Ľڵ�push������
			}
		}
		for (int i = 0; i < numCourses; i++){
			if (in[i] != 0)
				return false;
		}
		return true;
	}
};