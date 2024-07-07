import java.util.LinkedList;
import java.util.ListIterator;

class Graph{
    private int V;
    private LinkedList<Integer> adjList[];
    public Graph(int v){
        V = v;
        adjList = new LinkedList[v];
        for(int i=0; i<adjList.length;i++){
            adjList[i] = new LinkedList<Integer>();
        }
    }
    
    void addEdge(int v, int w){
        adjList[v].add(w);
        adjList[w].add(v);
    }

    public void BFSFunc(int startV,boolean [] visited){
        LinkedList<Integer> queue = new LinkedList<>();
        visited[startV] = true;
        queue.add(startV);
        while(!queue.isEmpty()){
            int visitV = queue.poll();
            System.out.println(visitV+" ");
            ListIterator<Integer> it = adjList[visitV].listIterator();
            while(it.hasNext()){
                int i = it.next();
                if(!visited[i]){
                    queue.add(i);
                    visited[i] = true;
                }
            }
        }
    }
        
}


public class BFS {
    public static void main(String[] args){
        Graph pg = new Graph(5);
        pg.addEdge(0, 3);
        pg.addEdge(0, 4);
        pg.addEdge(0,1);
        pg.addEdge(0, 2);

        boolean visited [] = new boolean[5];
        pg.BFSFunc(0,visited);
    }    
}
