class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function singleNumber($nums) {
        
        $numbers = [];
        
        foreach ($nums as $num) {
            ++$numbers[$num];
        }
        
        return array_search(min($numbers), $numbers);        
        
    }
}
