import java.util.*

fun main() {
    val br=System.`in`.bufferedReader()
    val (n,k)=br.readLine().split(" ").map {it.toInt()}
    val jewl=Array(n){Pair(0,0)}
    val map=TreeMap<Int,Int>()  //무게, 가치
    var answer:Long=0
    for(i in 0 until n){
        val jewltmp=br.readLine().split(" ").map { it.toInt() }
        jewl[i]= Pair(jewltmp[0],jewltmp[1])
    }
    jewl.sortBy {-it.second}
    repeat(k){
        val bag=br.readLine().toInt()
        var tmp=map[bag]
        if(tmp==null)
            tmp=0
        tmp++
        map[bag]=tmp
    }
    for(i in 0 until n){
        val tmp=map.ceilingEntry(jewl[i].first)
        if(tmp!=null){
            answer+=jewl[i].second
            val key=tmp.key
            val value=tmp.value-1
            if(value==0)
                map.remove(key)
            else
                map[key]=value
        }
    }
    println(answer)
}