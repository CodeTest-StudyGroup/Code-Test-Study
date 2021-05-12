import java.io.*;
import java.util.*;

public class Main {  
   public static void main(String[] args) throws IOException{
      BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
      
      HashMap<String,Integer> map = new HashMap<>();
      int total=0;
      while(true) {
    	  String name = br.readLine();
    	  if(name == null || name.length() == 0) {
    		  break;
    	  }
    	  
    	  if(!map.containsKey(name))
    		  map.put(name, 1);
    	  else
    		  map.put(name,map.get(name)+1);
    	  
    	  total++;
      }
      ArrayList<Data> all = new ArrayList<>();
      for(String cur : map.keySet()) {
    	  all.add(new Data(cur,(double)map.get(cur)/total));
      }
      
      Collections.sort(all, new Comparator<Data>() {
    	  @Override
    	  public int compare(Main.Data a, Main.Data b) {
    		  return a.name.compareTo(b.name);
    	  }
      });
      
      StringBuilder sb = new StringBuilder();
      for(Data cur : all) {
    	  sb.append(cur.name+" "+String.format("%.4f",cur.num*100)+'\n');
      }
      
      System.out.println(sb.toString());
   }
   
   static class Data{
	   String name;
	   double num;
	   Data(String name, double num){
		   this.name = name;
		   this.num = num;
	   }
   }
   
}