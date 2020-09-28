import java.util.*
import kotlin.math.max
import kotlin.math.min

private lateinit var arr:Array<Array<Int>>
private lateinit var dist1:Array<Int>
private lateinit var dist2:Array<Int>
private const val maxi=1000000000
fun main() {
    val br=System.`in`.bufferedReader()
    val (n,m,x)=br.readLine().split(" ").map { it.toInt() }
    arr=Array(n+1){Array(n+1){0}}
    dist1=Array(n+1){maxi}
    dist2=Array(n+1){maxi}
    dist1[x]=0
    dist2[x]=0
    repeat(m){
        val (a,b,c)=br.readLine().split(" ").map{it.toInt()}
        arr[a][b]= c
    }
    val q=LinkedList<Int>()
    q.offer(x)
    while (q.isNotEmpty())
    {
        val cur=q.poll()
        for(i in 1..n)
        {
            if(arr[i][cur]==0)
                continue
            if(dist1[i]>dist1[cur]+arr[i][cur])
            {
                dist1[i]=dist1[cur]+arr[i][cur]
                q.offer(i)
            }
        }
    }
    q.offer(x)
    while (q.isNotEmpty())
    {
        val cur=q.poll()
        for(i in 1..n)
        {
            if(arr[cur][i]==0)
                continue
            if(dist2[i]>dist2[cur]+arr[cur][i])
            {
                dist2[i]=dist2[cur]+arr[cur][i]
                q.offer(i)
            }
        }
    }
    var answer=0
    for(i in 1..n)
    {
        if(dist1[i]==maxi )
            continue
        if (dist2[i]== maxi)
            continue
        answer= max(answer,dist1[i]+dist2[i])
    }
    println(answer)
}