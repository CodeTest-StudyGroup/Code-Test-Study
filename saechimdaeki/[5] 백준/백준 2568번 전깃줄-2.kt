package 백준

import java.util.*
import kotlin.system.exitProcess

private val arr= arrayListOf<Pair<Int,Int>>()
private val visited=BooleanArray(500001)//500000
private lateinit var dp:IntArray
fun main() {
    val br = System.`in`.bufferedReader()
    val bw = System.out.bufferedWriter()
    val n = br.readLine().toInt()
    repeat(n) {
        val (a, b) = br.readLine().split(" ").map { it.toInt() }
        arr.add(Pair(a, b))
        visited[a] = true
    }
    dp=IntArray(n)
    arr.sortBy { it.first }
    var idx=0
    dp[0]=arr[0].second
    val stack= Stack<Pair<Int,Int>>()
    stack.add(Pair(0,arr[0].first))
    for(i in 1 until n){
        if(dp[idx]<arr[i].second){
            idx++
            dp[idx]=arr[i].second
            stack.add(Pair(idx,arr[i].first))
        }else{
            var (left,right)= arrayOf(0,idx)
            while (left<right){
                val mid=(left+right)/2
                when {
                    dp[mid]>=arr[i].second -> right=mid
                    else -> left=mid+1
                }
            }
            dp[right]=arr[i].second
            stack.add(Pair(right,arr[i].first))
        }
    }
    bw.write("${(n-idx-1)}\n")
    val temp=(n-idx-1)
    val answer= arrayListOf<Int>()
    while (stack.isNotEmpty()){
        val tmp=stack.pop()
        if(tmp.first==idx){
            answer.add(tmp.second)
            idx--
        }
    }
    var cnt=0
    for(i in 0 ..500000){
        when (cnt) {
            temp -> {
                bw.flush()
                exitProcess(0)
            }
        }
        when {
            visited[i]&& !(answer.contains(i)) -> {
                bw.write("$i\n")
                cnt++
            }
        }
    }
    bw.flush()
}




