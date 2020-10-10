package 백준

import java.util.LinkedList


private lateinit var arr:Array<CharArray>
private lateinit var key:BooleanArray
private lateinit var check:Array<BooleanArray>
private val dx= intArrayOf(0, 0, 1, -1)
private val dy= intArrayOf(1, -1, 0, 0)
fun main() {
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    val t=br.readLine().toInt()
    repeat(t){
        var (h, w) = br.readLine().split(" ").map { it.toInt() }
        var answer=0
        arr=Array(h+10){ CharArray(w+10) }
        key= BooleanArray(27)
        check=Array(h+10){BooleanArray(w+10)}
        for(i in 2 until h+2) {
            val input = br.readLine()
            for (j in input.indices) {
                arr[i][j + 2]=input[j]
            }
        }
        h+=4
        w+=4
        for(i in 0 until h){
            arr[i][0]='*'
            arr[i][1]='.'
            arr[i][w - 2]='.'
            arr[i][w - 1]='*'
        }
        for(i in 1 until w-1){
            arr[0][i]='*'
            arr[1][i]='.'
            arr[h - 2][i]='.'
            arr[h - 1][i]='*'
        }
        val sangGun=br.readLine()
        if(sangGun[0]!='0'){
            for(i in sangGun.indices){
                key[sangGun[i] - 'a']=true
            }
        }
        val q=LinkedList<Pair<Int,Int>>()
        val doors= Array(26){LinkedList<Int>()}
        check[1][1]=true
        q.offer(Pair(1,1))
        while (q.isNotEmpty()){
            val (x,y)=q.poll()
            for(i in 0 until 4){
                val (nx,ny)= arrayOf(x+dx[i],y+dy[i])
                if(check[nx][ny]) continue
                if(arr[nx][ny]=='*') continue
                when {
                    arr[nx][ny]=='.' -> {
                        q.offer(Pair(nx,ny))
                    }
                    arr[nx][ny]=='$' -> {
                        answer++
                        q.offer(Pair(nx,ny))
                    }
                    arr[nx][ny] in 'A'..'Z' -> {
                        if(key[arr[nx][ny]-'A']){
                            q.offer(Pair(nx,ny))
                        }else{
                            doors[arr[nx][ny]-'A'].offer(nx)
                            doors[arr[nx][ny]-'A'].offer(ny)
                        }
                    }
                    arr[nx][ny] in 'a'..'z' -> {
                        q.offer(Pair(nx,ny))
                        if(!key[arr[nx][ny]-'a']){
                            key[arr[nx][ny]-'a']=true
                            while (doors[arr[nx][ny]-'a'].isNotEmpty()){
                                val xx=doors[arr[nx][ny]-'a'].poll()
                                val yy=doors[arr[nx][ny]-'a'].poll()
                                q.offer(Pair(xx,yy))
                            }
                        }
                    }
                }
                check[nx][ny]=true
            }
        }
        bw.write("${answer}\n")
    }
    bw.flush()
}