import java.util.*;

class Solution {
    
    class Data implements Comparable<Data> {
        int id, play;
        String genre;
        
        Data(int id, int play, String genre){
            this.id = id;
            this.play = play;
            this.genre = genre;
        }
        
        @Override
        public int compareTo(Data o){
            if(this.play == o.play){
                return this.id - o.id;
            } else {
                return o.play - this.play;
            }
        }
    }
    
    ArrayList<Integer> bestAlbum;
    ArrayList<Data> songs;
    HashMap<String, Integer> genreMap;
    HashMap<String, Integer> albumMap;
    
    public int[] solution(String[] genres, int[] plays) {
        bestAlbum = new ArrayList<>();
        songs = new ArrayList<>();
        genreMap = new HashMap<>();
        albumMap = new HashMap<>();
        
        for(int i=0; i<genres.length; i++){
            songs.add(new Data(i, plays[i], genres[i]));
            genreMap.put(genres[i], genreMap.getOrDefault(genres[i], 0) + plays[i]);
        }
        
        Collections.sort(songs, new Comparator<Data>(){
            @Override
             public int compare(Data s1, Data s2){
                 if(s1.genre.equals(s2.genre)){
                     return s2.play - s1.play;
                 } else {
                     return genreMap.get(s2.genre) - genreMap.get(s1.genre);
                 }
             }
         });
        
        for(Data song : songs){
            if(!albumMap.containsKey(song.genre)){
                albumMap.put(song.genre, 1);
                bestAlbum.add(song.id);
            } else {
                int genreCnt = albumMap.get(song.genre);
                
                if(genreCnt >= 2) continue;
                else {
                    albumMap.put(song.genre, genreCnt + 1);
                    bestAlbum.add(song.id);
                }
            }
        }
        
        int[] answer = new int[bestAlbum.size()];
        for(int i = 0 ; i < answer.length ; ++i){
            answer[i] = bestAlbum.get(i);
        }
        
        return answer;
    }
}

public class Main {
	
	public static void main(String[] args){
		String[] genres = {"classic","pop","classic","classic","pop"};
		int[] plays = {500,600,150,800,2500};
		System.out.println(new Solution().solution(genres, plays));
	}
	
}