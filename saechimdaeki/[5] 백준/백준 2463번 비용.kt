package 백준
private val arr= arrayListOf<Triple<Int,Int,Int>>()
private lateinit var parent:IntArray
private lateinit var size:LongArray
fun main() {
    val br=System.`in`.bufferedReader()
    val (n,m)=br.readLine().split(" ").map { it.toInt() }
    parent=IntArray(n+1){it}
    size= LongArray(n+1){1}
    var costsum:Long=0
    repeat(m) {
        val (a,b,c)=br.readLine().split(" ").map { it.toInt() }
        arr.add(Triple(a,b,c))
        costsum+=c
    }
    arr.sortByDescending{ it.third }
    var ans:Long=0
    for(i in arr){
        if(find(i.first)!= find(i.second)){
            ans+=((((size[find(i.first)]* size[find(i.second)])%1000000000)*costsum))
            ans%=1000000000
            union(i.first,i.second)
        }
        costsum-=i.third
    }
    println(ans)
}
private fun find(x:Int):Int{
    return when (x) {
        parent[x] -> {
            x
        }
        else -> {
            parent[x] = find(parent[x])
            parent[x]
        }
    }
}
private fun union(x:Int,y:Int){
    val (px,py)= arrayOf(find(x), find(y))
    when {
        px>py -> {
            parent[px]=py
            size[py]+= size[px]
            size[px]=1
        }
        else -> {
            parent[py]=px
            size[px]+= size[py]
            size[py]=1
        }
    }
}