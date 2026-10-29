class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val map = HashMap<Int, Int>()

        for (i in nums.indices) {
            map[nums[i]] = i
        }

        for (j in nums.indices) {
            val diff = target - nums[j]

            if (map.containsKey(diff) && map[diff] != j) {
                return intArrayOf(map[diff]!!, j)
            }
        }

        return intArrayOf()
    }
}