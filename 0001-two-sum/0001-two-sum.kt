class Solution {
    fun twoSum(nums: IntArray, target: Int): IntArray {
        val map = HashMap<Int, Int>()

        for (i in nums.indices) {
            val diff = target - nums[i]

            if (map.containsKey(diff)) {
                return intArrayOf(map[diff]!!, i)
            }

            map[nums[i]] = i
        }

        return intArrayOf()
    }
}