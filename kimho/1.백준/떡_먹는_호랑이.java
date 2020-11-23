import java.util.*;

class Test {
    public static void main(String[] args){
        Scanner std = new Scanner(System.in);
        int D,K;
        D = std.nextInt();
        K = std.nextInt();
        int[] A = new int[D+1];
        int[] B = new int[D+1];

        A[3] = B[3] = 1;

        for(int i=4; i<=D; i++){
            A[i] = B[i-1];
            B[i] = A[i-1] + B[i-1];
        }
        for(int b=1; b<K; b++){
            for(int a=1; a<=b; a++){
                if(a*A[D] + b*B[D] == K){
                    System.out.printf("%d\n%d",a,b);
                    return;
                }
            }
        }
    }
}
