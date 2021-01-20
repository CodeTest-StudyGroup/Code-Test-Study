
import java.util.*;

/**
 * 투 포인터를 사용한다.
 * lo와 end를 이용하는데, 각 포인터를 이동시킬 때 마다 해당 위치의 보석이름을 map에서 빼거나 더해준다.
 * 그리고 매번 map에서 보석들의 개수를 확인한다.
 * minLeft와 minSize를 이용해 최저 시작점과 최저 길이를 메모리한다.
 */

class Solution {

    public int[] solution(String[] gems) {
        int[] answer = new int[2];
        Map<String, Integer> gemBucket = new HashMap<>();

        for (String gem : gems) {
            gemBucket.putIfAbsent(gem, 0);
        }

        int totalGems = gemBucket.size();
        gemBucket.clear();

        int lo = 0;
        int hi = 0;
        int minLeft = Integer.MAX_VALUE;
        int minSize = Integer.MAX_VALUE;

        while (true) {
            if (gemBucket.size() >= totalGems) {
                gemBucket.computeIfPresent(gems[lo++], (__, val) -> val - 1 == 0 ? null : val - 1);
            } else if (hi == gems.length) {
                break;
            } else {
                gemBucket.putIfAbsent(gems[hi], 0);
                gemBucket.computeIfPresent(gems[hi++], (__, val) -> val + 1);
            }

            // 모든 보석을 가지고 있다면 갱신
            if (gemBucket.size() == totalGems) {
                if ((hi - lo < minSize)
                        || (hi - lo == minSize && lo < minLeft)) {
                    minLeft = lo;
                    minSize = hi - lo;
                }
            }
        }

        answer[0] = minLeft + 1;
        answer[1] = minLeft + minSize;

        return answer;
    }
}