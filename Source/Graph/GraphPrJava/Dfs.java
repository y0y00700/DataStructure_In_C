package DataStructure;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;

/*  pseudoCode
    // 깊이 우선 탐색의 구현
    void search(Graph vertex){
        visit(vertex); // 1. 기준 vertex 방문
        vertex.visited = true; // 1-1. 방문한 노드를 표시
        // 2. 현재 정점과 인접한 정점을 모두 방문
        for each(Node n in root.adjacent){
            if(n.visited == false){ // 4. 방문하지 않은 정점을 찾는다.
                search(n); // 3. root 노드와 인접한 정점 정점을 시작 정점으로 DFS 시작
            }
        }
    }
 */

// void DFSWithStack (Graph vertex){
//     let S be a stack;  // 1. 스택을 초기화
//     S.push(vertex);    // 2. 시작 정점을 stack에 push
//     while S is not empty do{ // 3. Stack이 Empty 되면 반복 종료
//         v = S.pop() // 3. 최초 시작 정점을 Stack에 저장
//         if (vertex is not labeled as visited then){  // 4. 방문되지 않은 정점인 경우,
//             label v as discovered // 5. 정점을 방문 처리
//             for (all edges from v to w in Graph.adjacentEdges(v) do){ // 6. 해당 정점을 기준으로 인접 정점을 차례대로 방문
//                 if (w is not labeled as visited then) // 7. 아직 방문되지 않은 정점으로 이동시, Stack에 현재 정점을 저장
//                   S.push(w)
//             }
//         }
//     }
// }
 class Graph{
    private int V;
    private LinkedList<Integer> adjList[];
   
    Graph(int v){
        V = v;
        adjList = new LinkedList[v];
        for(int i=0;i<v;i++)
        adjList[i] = new LinkedList();
    }

    void addEdge(int v,int w) {
        adjList[v].add(w);
    }

    void DFSHelper(int v,boolean visited[]){
        visited[v] = true;
        System.out.print(v + " ");

        Iterator <Integer> i = adjList[v].listIterator();
        while(i.hasNext()){
            int n = i.next();

            if(!visited[n])
                DFSHelper(n, visited);
        }
    }

    void DFS(int v){
        boolean visited[] = new boolean[V];
        DFSHelper(v, visited);
        System.out.println(" ");
    }

    void DFS(){
        boolean visited[] = new boolean[V];
        for(int i=0;i<V;i++){
            if(visited[i]== false)  DFSHelper(i, visited);
        }
    }


    // boolean DFSHelper(int v){
    //     System.out.println(v + " ");
        
    //     // first 방문
    //     if(visitdS[v] == false){
    //         visitedS[v] = TRUE;
    //         return TRUE;
    //     }
    //     // 이미 방문되었었던 vertex
    //     return FALSE;
    // }

    void DFSWithStack(int v){
        // Init
        boolean[] visited = new boolean[V];
        Stack<Integer> stV = new Stack<Integer>();
        //DFSHelper(v); // 현재 정점 방문 처리
        stV.push(v); // stack 에 현재 Vertex 저장
        while(!stV.empty()){
            int nextV = stV.pop();
            if(!visited[nextV]){
                System.out.print(nextV+" ");
                visited[nextV] = true;
                for(int i=0;i<adj[nextV].size();i++){
                        int nV = adjList[nextV].get(i);
                        if(!visited[i])
                            stV.push(i);
                }
            }
        }
    }


 }
public class Dfs {

    public static void main(String[] args){
        Graph g = new Graph(4);

        g.addEdge(0, 1);
        g.addEdge(0, 2);
        g.addEdge(1, 2);
        g.addEdge(2, 0);
        g.addEdge(2, 3);

        g.DFS(2);
        g.DFS();
        //g.DFSWithStack(2);
    }
   
}