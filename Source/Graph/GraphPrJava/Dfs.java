package DataStructure;

import java.util.Iterator;
import java.util.LinkedList;
import java.util.Stack;

/*  pseudoCode
    // 깊이 우선 탐색의 구현
    void search(Node root){
        // 1. root 노드 방문
        visit(root);
        root.visited = true; // 1-1. 방문한 노드를 표시
        // 2. root 노드와 인접한 정점을 모두 방문
        for each(Node n in root.adjacent){
            if(n.visited == false){ // 4. 방문하지 않은 정점을 찾는다.
                search(n); // 3. root 노드와 인접한 정점 정점을 시작 정점으로 DFS 시작
            }
        }
    }
 */

 class Graph{
    private int V;
    private LinkedList<Integer> adj[];
   
    Graph(int v){
        V = v;
        adj = new LinkedList[v];
        for(int i=0;i<v;i++)
            adj[i] = new LinkedList();
    }

    void addEdge(int v,int w) {
        adj[v].add(w);
    }

    void DFSUtil(int v,boolean visited[]){
        visited[v] = true;
        System.out.print(v + " ");

        Iterator <Integer> i = adj[v].listIterator();
        while(i.hasNext()){
            int n = i.next();

            if(!visited[n])
                DFSUtil(n, visited);
        }
    }

    void DFS(int v){
        boolean visited[] = new boolean[V];
        DFSUtil(v, visited);
        System.out.println(" ");
    }

    void DFS(){
        boolean visited[] = new boolean[V];
        for(int i=0;i<V;i++){
            if(visited[i]== false)  DFSUtil(i, visited);
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
                        int nV = adj[nextV].get(i);
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
        g.addEdge(3, 3);

        g.DFS(2);
        g.DFS();
        //System.out.println(" ");
        //g.DFSWithStack(2);
    }
   
}