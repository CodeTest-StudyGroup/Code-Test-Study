package 백준

import kotlin.system.exitProcess

private val arr=Array(9){IntArray(9)}
private val check=Array(3){Array(9){BooleanArray(10)}}
private val bw=System.out.bufferedWriter()
fun main() {
    val br=System.`in`.bufferedReader()
    val bw=System.out.bufferedWriter()
    for(i in 0 until 9){
        arr[i]=br.readLine().split(" ").map { it.toInt() }.toIntArray()
        for(j in arr[i].indices){
            if(arr[i][j]==0) continue
            else{
                check[0][i][arr[i][j]]=true //행
                check[1][j][arr[i][j]]=true //열
                check[2][(i/3)*3+(j/3)][arr[i][j]]=true //i번째 사각형
            }
        }
    }
    solve(0)

}
private fun solve(cnt:Int){
    if(cnt==81){ //base
        for(i in 0 until 9){
            for(j in 0 until 9){
                bw.write("${arr[i][j]} ")
            }
            bw.write("\n")
        }
        bw.flush()
        exitProcess(0)
    }
    val x=cnt/9
    val y=cnt%9
    //println("$x $y")
    if(arr[x][y]!=0){
        solve(cnt+1)
    }else{
        for(i in 1..9){
            if(!check[0][x][i]&& !check[1][y][i]&&!check[2][(x/3)*3+(y/3)][i]){
                check[0][x][i]=true
                check[1][y][i]=true
                check[2][(x/3)*3+(y/3)][i]=true
                arr[x][y]=i
                solve(cnt+1)
                arr[x][y]=0
                check[0][x][i]=false
                check[1][y][i]=false
                check[2][(x/3)*3+(y/3)][i]=false
            }
        }
    }
}