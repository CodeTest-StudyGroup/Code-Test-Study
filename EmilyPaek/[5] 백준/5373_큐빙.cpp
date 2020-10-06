#include <iostream>
#include <string>
using namespace std;

int TC;
char Cube[6][3][3];
string Color = "wyrogb";
char temp[3];
char copyface[3][3];

void printTop(){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            cout << Cube[0][i][j];
        }
        cout << '\n';
    }
}

void InitCube(){
    for(int n=0; n<6; n++){
        for(int i=0; i<3; i++){
            for(int j=0; j<3; j++){
                Cube[n][i][j] = Color[n];
            }
        }   
    }
}

void RotateUp(char secdir){
    if(secdir == '+'){
        for(int i=0; i<3; i++) temp[i] = Cube[4][0][i];
        for(int i=0; i<3; i++) Cube[4][0][i] = Cube[2][0][i];
        for(int i=0; i<3; i++) Cube[2][0][i] = Cube[5][0][i];
        for(int i=0; i<3; i++) Cube[5][0][i] = Cube[3][0][i];
        for(int i=0; i<3; i++) Cube[3][0][i] = temp[i];
    }
    else{ 
        for(int i=0; i<3; i++) temp[i] = Cube[3][0][i];
        for(int i=0; i<3; i++) Cube[3][0][i] = Cube[5][0][i];
        for(int i=0; i<3; i++) Cube[5][0][i] = Cube[2][0][i];
        for(int i=0; i<3; i++) Cube[2][0][i] = Cube[4][0][i];
        for(int i=0; i<3; i++) Cube[4][0][i] = temp[i];
    }
}

void RotateDown(char secdir){
    if(secdir == '+'){
        for(int i=0; i<3; i++) temp[i] = Cube[4][2][i];
        for(int i=0; i<3; i++) Cube[4][2][i] = Cube[3][2][i];
        for(int i=0; i<3; i++) Cube[3][2][i] = Cube[5][2][i];
        for(int i=0; i<3; i++) Cube[5][2][i] = Cube[2][2][i];
        for(int i=0; i<3; i++) Cube[2][2][i] = temp[i];
    }
    else{
        for(int i=0; i<3; i++) temp[i] = Cube[2][2][i];
        for(int i=0; i<3; i++) Cube[2][2][i] = Cube[5][2][i];
        for(int i=0; i<3; i++) Cube[5][2][i] = Cube[3][2][i];
        for(int i=0; i<3; i++) Cube[3][2][i] = Cube[4][2][i];
        for(int i=0; i<3; i++) Cube[4][2][i] = temp[i];
    }
}

void RotateFront(char secdir){
    if(secdir == '+'){
        for(int i=0; i<3; i++) temp[i] = Cube[4][i][2];
        for(int i=0; i<3; i++) Cube[4][i][2] = Cube[1][0][i]; 
        for(int i=0; i<3; i++) Cube[1][0][i] = Cube[5][2-i][0];
        for(int i=0; i<3; i++) Cube[5][i][0] = Cube[0][2][i];
        for(int i=0; i<3; i++) Cube[0][2][i] = temp[2-i];
    }
    else{
        for(int i=0; i<3; i++) temp[i] = Cube[0][2][i];
        for(int i=0; i<3; i++) Cube[0][2][i] = Cube[5][i][0];
        for(int i=0; i<3; i++) Cube[5][i][0] = Cube[1][0][2-i];
        for(int i=0; i<3; i++) Cube[1][0][i] = Cube[4][i][2];
        for(int i=0; i<3; i++) Cube[4][i][2] = temp[2-i];
    }
}

void RotateBack(char secdir){
    if(secdir == '+'){
        for(int i=0; i<3; i++) temp[i] = Cube[5][i][2];
        for(int i=0; i<3; i++) Cube[5][i][2] = Cube[1][2][2-i];
        for(int i=0; i<3; i++) Cube[1][2][i] = Cube[4][i][0];
        for(int i=0; i<3; i++) Cube[4][i][0] = Cube[0][0][2-i];
        for(int i=0; i<3; i++) Cube[0][0][i] = temp[i];   
    }
    else{
        for(int i=0; i<3; i++) temp[i] = Cube[0][0][i];
        for(int i=0; i<3; i++) Cube[0][0][i] = Cube[4][2-i][0];
        for(int i=0; i<3; i++) Cube[4][i][0] = Cube[1][2][i];
        for(int i=0; i<3; i++) Cube[1][2][i] = Cube[5][2-i][2];
        for(int i=0; i<3; i++) Cube[5][i][2] = temp[i];
    }
}

void RotateLeft(char secdir){
    if(secdir == '+'){
        for(int i=0; i<3; i++) temp[i] = Cube[3][i][2];
        for(int i=0; i<3; i++) Cube[3][i][2] = Cube[1][2-i][0];
        for(int i=0; i<3; i++) Cube[1][i][0] = Cube[2][i][0];
        for(int i=0; i<3; i++) Cube[2][i][0] = Cube[0][i][0];
        for(int i=0; i<3; i++) Cube[0][i][0] = temp[2-i];
    }
    else{
        for(int i=0; i<3; i++) temp[i] = Cube[0][i][0];
        for(int i=0; i<3; i++) Cube[0][i][0] = Cube[2][i][0];
        for(int i=0; i<3; i++) Cube[2][i][0] = Cube[1][i][0];
        for(int i=0; i<3; i++) Cube[1][i][0] = Cube[3][2-i][2];
        for(int i=0; i<3; i++) Cube[3][i][2] = temp[2-i];
    }
}

void RotateRight(char secdir){
    if(secdir == '+'){
        for(int i=0; i<3; i++) temp[i] = Cube[2][i][2];
        for(int i=0; i<3; i++) Cube[2][i][2] = Cube[1][i][2];
        for(int i=0; i<3; i++) Cube[1][i][2] = Cube[3][2-i][0];
        for(int i=0; i<3; i++) Cube[3][i][0] = Cube[0][2-i][2];
        for(int i=0; i<3; i++) Cube[0][i][2] = temp[i];
    }
    else{
        for(int i=0; i<3; i++) temp[i] = Cube[0][i][2];
        for(int i=0; i<3; i++) Cube[0][i][2] = Cube[3][2-i][0];
        for(int i=0; i<3; i++) Cube[3][i][0] = Cube[1][2-i][2];
        for(int i=0; i<3; i++) Cube[1][i][2] = Cube[2][i][2];
        for(int i=0; i<3; i++) Cube[2][i][2] = temp[i];
    }
}

void clockwise(int idx){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            copyface[j][2 - i] = Cube[idx][i][j];
        }
    }
}

void counterCockwise(int idx){
    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            copyface[2 - j][i] = Cube[idx][i][j];
        }
    }
}

void Rotate(string dir){
    int idx;
    switch(dir[0]){
        case 'U' : RotateUp(dir[1]); 
                   idx = 0; 
                    break;
        case 'D' : RotateDown(dir[1]); 
                    idx = 1; 
                    break;
        case 'F' : RotateFront(dir[1]);
                    idx = 2; 
                    break;
        case 'B' : RotateBack(dir[1]); 
                    idx = 3; 
                    break;
        case 'L' : RotateLeft(dir[1]); 
                    idx = 4; 
                    break;
        case 'R' : RotateRight(dir[1]); 
                    idx = 5; 
                    break;
    }

    if(dir[1] == '+') clockwise(idx);
    else counterCockwise(idx);

    for(int i=0; i<3; i++){
        for(int j=0; j<3; j++){
            Cube[idx][i][j] = copyface[i][j] ;
        }
    }
}

void Solution(){
    int N;
    string direction;
    cin >> TC;
    for(int tc=0; tc<TC; tc++){
        InitCube();
        cin >> N;
        for(int n=0; n<N; n++){
            cin >> direction;
            Rotate(direction);
        }
        printTop();
    }
}

int main(){
    Solution();
    return 0;
}