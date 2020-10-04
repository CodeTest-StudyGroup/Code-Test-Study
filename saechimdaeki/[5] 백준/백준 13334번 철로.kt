package 백준

import java.util.*
import kotlin.math.max


fun main() {
    val br=System.`in`.bufferedReader()
    val n=br.readLine().toInt()
    val arr= arrayListOf<Pair<Int,Int>>()
    repeat(n){
        val (a,b)=br.readLine().split(" ").map { it.toInt() }
        arr.add(Pair(minOf(a,b), maxOf(a,b)))
    }
    arr.sortBy { it.second }
    val d=br.readLine().toInt()
   // for(i in arr){
   //     println("${i.first} ${i.second}")
   // }
    var answer=-12345
    val pq=PriorityQueue<Int>()
    for(i in 0 until n){
        pq.offer(arr[i].first)
        while (pq.isNotEmpty() && (arr[i].second-pq.peek()>d)){
                pq.remove()
        }
        answer= max(answer,pq.size)
    }
    println(answer)
}
