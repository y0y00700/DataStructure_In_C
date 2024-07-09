package Source.Graph.BFS;

import java.io.IOException;
import java.util.ArrayList;
import java.util.Iterator;
import java.util.LinkedList;
import java.util.Queue;

class Graph{
    private int vertex;
    private ArrayList <Integer> adjList[];

    Graph(int v){
        this.vertex = v;
        adjList = new ArrayList[vertex];

        for(int i=0;i<vertex;i++){
            adjList[i] = new ArrayList<>();
        }
    }

    void addEdge(int v,int w){
        adjList[v].add(w);
        adjList[w].add(v);
    }

    void BFS(int startV,Graph pg){
        // Breadth First Search  Code;
        boolean [] visited = new boolean[pg.vertex];
        Queue <Integer>queue = new LinkedList<Integer>();
        StringBuilder sb = new StringBuilder();
        
        visited[startV] = true;
        queue.add(startV); // base vertex
        while(!queue.isEmpty()){
            int nextV = queue.poll();
            sb.append(nextV+" ");
            Iterator <Integer> iter = pg.adjList[nextV].iterator();
            while(iter.hasNext()){
                int i = iter.next();
                if(!visited[i]){
                    queue.add(i);
                    visited[i] = true;
                }
            }
        }
        System.out.println(sb.toString());
    }

    void showGraph(Graph pg){
        StringBuilder sb = new StringBuilder();
        System.out.println("Vertex = " +pg.vertex);
        
        sb.append("Vertex Detail is {");
        for(int i=0; i<pg.vertex;i++){
            sb.append(i+"("+pg.adjList[i]+"), ");
        }
        sb.append("} ");
        System.out.println(sb.toString());
    }
}

public class BFSPr {
    public static void main(String[] args)throws IOException{
        Graph pg = new Graph(7);
        pg.addEdge(0, 1);
        pg.addEdge(0, 2);
        pg.addEdge(0, 4);
        pg.addEdge(4, 3);
        pg.addEdge(3, 5);
        pg.addEdge(3, 6);
        //pg.showGraph(pg);
        //pg.BFS(0, pg);
    }
}