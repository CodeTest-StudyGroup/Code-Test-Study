import java.io.*;
import java.util.*;

public class Main {
	
	static int n;
	static long startPower;
	static int t,a,h;
	
	static class RoomInfo{
		int t,a,h;
		RoomInfo(int t, int a, int h){
			this.t = t;
			this.a = a;
			this.h = h;
		}
	}
	
	static ArrayList<RoomInfo> room = new ArrayList<>();
	
	public static void main(String[] args) throws IOException {
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringTokenizer st = new StringTokenizer(br.readLine());
		
		n = Integer.parseInt(st.nextToken());
		startPower = Long.parseLong(st.nextToken());
		for(int i=0; i<n; i++) {
			st = new StringTokenizer(br.readLine());
			t= Integer.parseInt(st.nextToken());
			a= Integer.parseInt(st.nextToken());
			h= Integer.parseInt(st.nextToken());
			room.add(new RoomInfo(t,a,h));
		}
		
		long l,r;
		long mid;
		l =1; r = (long)Math.pow(10, 17);
		long ans=0;
		long curPower=0;
		
		while(l<=r) {
			curPower = startPower;
			mid = (l+r)/2;
			long monsterHP;
			long playerHP = mid;
			for(RoomInfo tmp : room) {
				if(tmp.t==1) {
					monsterHP = tmp.h;
					long atkCnt = monsterHP/curPower; 
					if(monsterHP%curPower==0)
						atkCnt--;
					playerHP -= (tmp.a*atkCnt);
						
					if(playerHP<=0)
						break;
				}
				else {
					curPower += tmp.a;
					playerHP = Math.min(mid,playerHP+tmp.h);
				}
			}
			if(playerHP<=0) {
				l=mid+1;
			}
			else
			{
				ans=mid;
				r=mid-1;
			}
		}
		System.out.println(ans);
		
	}

}
