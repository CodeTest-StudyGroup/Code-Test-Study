#14499 삼성기출 주사위 굴리기
import copy

dy = [0,0,0,-1,1]#우 좌 상 하
dx = [0,1,-1,0,0]
if __name__ == "__main__":
    N,M,y,x,K = map(int,input().split())
    MAP = [list(map(int,input().split())) for _ in range(N)]
    command = list(map(int,input().split()))
    dice = [0 for _ in range(7)]

    for i in range(0,K):
        newy = y+dy[command[i]]
        newx = x+dx[command[i]]

        if 0<=newy<N and 0<=newx<M:
            if command[i] == 1:
                temp = [0,dice[1],dice[6],dice[2],dice[3],dice[5],dice[4]]
                dice = copy.deepcopy(temp)
            elif command[i] == 2: 
                temp = [0,dice[1],dice[3],dice[4],dice[6],dice[5],dice[2]]
                dice = copy.deepcopy(temp)
            elif command[i] == 3: 
                temp = [0,dice[3],dice[2],dice[5],dice[4],dice[6],dice[1]]
                dice = copy.deepcopy(temp)
            elif command[i] == 4: 
                temp = [0,dice[6],dice[2],dice[1],dice[4],dice[3],dice[5]]
                dice = copy.deepcopy(temp)

            y = newy
            x = newx
            if MAP[y][x] == 0:
                MAP[y][x] = dice[6]
            else:
                dice[6] = MAP[y][x]
                MAP[y][x] = 0

            print(dice[3])
        else:
            continue
    