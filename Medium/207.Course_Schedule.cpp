//using BFS
class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        set<int> vertices;
        stack<int> zeroVertices;
        vector<vector<int>> adjustList(numCourses, vector<int>());
        vector<int> inDegree(numCourses, 0);
        for(int i = 0; i < prerequisites.size(); i++)
        {
            vertices.insert(prerequisites[i].first);
            vertices.insert(prerequisites[i].second);
            inDegree[prerequisites[i].second]++;
            adjustList[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        for(int i = 0; i < numCourses; i++)
        {
            if(inDegree[i] == 0)
                zeroVertices.push(i);
        }
        while(!zeroVertices.empty())
        {
            int vertex = zeroVertices.top();
            zeroVertices.pop();
            for(auto it : adjustList[vertex])
            {
                inDegree[it]--;
                if(inDegree[it] == 0)
                    zeroVertices.push(it);
            }
            vertices.erase(vertex);
        }
        if(vertices.empty())
            return true;
        
        return false;
    }
};

//using DFS
class Solution {
public:
    bool findCircleByDFS(int visit, vector<vector<int>>& adjust, vector<int>& visited, set<int>& list)
    {
        if(visited[visit]) return false;
        visited[visit] = 1;
        list.insert(visit);
        for(auto it : adjust[visit])
        {
            if(!visited[it])
            {
                if(findCircleByDFS(it, adjust, visited, list))
                    return true;
            }
            else
            {
                if(list.find(it) != list.end())
                    return true;
            }
        }
        list.erase(visit);
        return false;
    }
    bool canFinish(int numCourses, vector<pair<int, int>>& prerequisites) {
        
        vector<vector<int>> adjustList(numCourses, vector<int>());
        for(int i = 0; i < prerequisites.size(); i++)
        {
           
            adjustList[prerequisites[i].first].push_back(prerequisites[i].second);
        }
        vector<int> visited(numCourses, 0);
        for(auto it : prerequisites)
        {
            set<int> list;
            if(visited[it.first] != 1)
            {
                bool result = findCircleByDFS(it.first, adjustList, visited, list);
                if(result)
                    return false;
            }
        }
        
        return true;
    }
};