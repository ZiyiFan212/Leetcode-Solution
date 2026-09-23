class Solution {
    fun majorityElement(nums: IntArray): Int {
        if (nums.isEmpty()) return 0
        val n : Int = nums.size / 2

        val frequencyMap: HashMap<Int, Int> = HashMap()// bitwise, voting algo, or hashmap
        for (num in nums) {
            frequencyMap[num] = frequencyMap.getOrDefault(num, 0) + 1
            if (frequencyMap[num]!! > n) return num
        }

        return 0
    }
}