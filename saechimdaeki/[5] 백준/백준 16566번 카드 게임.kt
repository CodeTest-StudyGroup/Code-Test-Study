package 백준
private lateinit var arr:IntArray
private lateinit var visited:BooleanArray
fun main() {
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val (n, m, k) = br.readLine().split(" ").map { it.toInt() }
    visited= BooleanArray(n+1)
    arr=br.readLine().split(" ").map { it.toInt() }.toIntArray()
    arr.sort()
    val chulSu=br.readLine().split(" ").map { it.toInt() }.toIntArray()
    for(i in chulSu.indices){
        var temp= upperBound(arr,chulSu[i])
        if(!visited[temp]){
            visited[temp]=true
            bw.write("${arr[temp]}\n")
        }else {
            while (visited[temp]){
                temp++
            }
            visited[temp]=true
            bw.write("${arr[temp]}\n")
        }
    }
    bw.flush()
}
private fun upperBound(a: IntArray, `val`: Int): Int {
    var left = 0
    var right = a.size
    while (left < right) {
        val mid = (left + right) / 2
        if (a[mid] <= `val`) {
            left = mid + 1
        } else {
            right = mid
        }
    }
    return left
}
