package 백준

import java.util.*
import kotlin.collections.ArrayList

data class node1167(val to:Int,val cost:Int)
private lateinit var arr:Array<ArrayList<node1167>>
private lateinit var visited:BooleanArray
private lateinit var dist:IntArray
fun main() {
    val br=System.`in`.bufferedReader()
    val v=br.readLine().toInt()
    arr=Array(v+1){ arrayListOf<node1167>()}
    repeat(v){
        val input=br.readLine().split(" ").map { it.toInt() }
        var to=-1
        var cost=-1
        var cnt=0
        for(i in 1 until input.size ){
            if(input[i]==-1) break
            if(cnt==0){
                to=input[i]
            }else if(cnt==1){
                cost=input[i]
            }
            cnt++
            if(cnt==2) {
                arr[input[0]].add(node1167(to,cost))
                cnt=0
            }
        }
    }
    bfs(v,1) // 탐색
    var vertex=1
    for(i in 2..v){
        if(dist[i]>dist[vertex]){
            vertex=i
        }
    }
    bfs(v,vertex) //탐색
    var answer=dist[1]
    for(i in 2..v){
        if(answer<dist[i])
            answer=dist[i]
    }
    println(answer)

}
private fun bfs(v:Int,vertex:Int){
    visited= BooleanArray(v+1)
    dist= IntArray(v+1)
    val q=LinkedList<Int>()
    q.offer(vertex)
    visited[vertex]=true
    while (q.isNotEmpty()){
        val now=q.poll()
        for(i in arr[now]){
            val to=i.to
            val cost=i.cost
            if(!visited[to]){
                dist[to]=dist[now]+cost
                q.offer(to)
                visited[to]=true
            }
        }
    }
}