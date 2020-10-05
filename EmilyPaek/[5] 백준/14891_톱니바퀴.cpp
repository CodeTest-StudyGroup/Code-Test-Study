#include <cstdio>
#include <deque>
#include <cmath>
using namespace std;

deque<int> sawtooth[4];
int K;
bool isCheck[4];
int answer = 0;
void Input(){
    char dir;
    for(int i=0; i<4; i++){
        for(int j=0; j<8; j++){
            scanf("%c", &dir);
            if(j==7) getchar();
            sawtooth[i].push_back(dir - '0');
        }
    }
    scanf("%d", &K);
}

void Rotate(int Num, int rotation){
    int right, left;
    right = sawtooth[Num][2];   
    left = sawtooth[Num][6];
    isCheck[Num] = true;

    if(rotation == -1){
        int front = sawtooth[Num].front();
        sawtooth[Num].pop_front();
        sawtooth[Num].push_back(front);
    }  
    else{
        int back = sawtooth[Num].back();
        sawtooth[Num].pop_back();
        sawtooth[Num].push_front(back);
    }

    if(Num < 3 && !isCheck[Num+1] && right!=sawtooth[Num+1][6])
        Rotate(Num+1, -rotation);

    if(Num > 0 && !isCheck[Num-1] && left!=sawtooth[Num-1][2])
        Rotate(Num-1, -rotation);
}

void Solution(){
    int Num, rotation, score;
    for(int i=0; i<K; i++){
        scanf("%d %d", &Num, &rotation);
        Num--;
        for(int i=0; i<4; i++)
            isCheck[i] = false;
        Rotate(Num, rotation);      
    }

    for(int i=0; i<4; i++){
        score = sawtooth[i].front();
        if(score == 1)
            answer += pow(2, i);
    }
    printf("%d\n", answer);
}

int main(){
    Input();
    Solution();
}