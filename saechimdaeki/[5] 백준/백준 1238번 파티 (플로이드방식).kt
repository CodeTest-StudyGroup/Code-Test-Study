package 백준

import kotlin.math.min

private lateinit var arr:Array<IntArray>
private lateinit var answer:IntArray
private val inf=1000000000
fun main() {
    val br=System.`in`.bufferedReader()
    val (n,m,x)=br.readLine().split(" ").map { it.toInt() }
    arr=Array(n+1){IntArray(n+1){inf}}
    answer= IntArray(n+1)
    for(i in 1..n){
        for(j in 1..n){
            if(i==j) arr[i][j]=0
        }
    }
    repeat(m){
        val (a,b,c)=br.readLine().split(" ").map { it.toInt() }
        arr[a][b]=c
    }
    for(k in 1..n){
        for(i in 1..n){
            for(j in 1..n){
                if(arr[i][k]!=inf && arr[k][j]!=inf){
                    arr[i][j]= min(arr[i][j],arr[k][j]+arr[i][k])
                }
            }
        }
    }
    for(i in 1..n){
        answer[i]=arr[i][x]+arr[x][i]
    }
    println(answer.max())
}