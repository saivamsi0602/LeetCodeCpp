#include "../include/FenwickTree.h"

namespace DataStructures
{
    namespace Trees
    {
        void FenwickTree::updateTillRoot(int index, int diff)
        {
            for(int i=index;i<arr.size();i+=(i&-i))
                arr[i]+=diff;
        }

        int FenwickTree::getPointQuery(int index)
        {
            int res = 0;
            for(int i=index;i>0;i-=(i&-i))
                res+=arr[i];
            return res;
        }

        FenwickTree::FenwickTree(std::vector<int>& nums): nums(nums), arr(nums.size()+1,0){

        }
        void Trees::FenwickTree::update(int index, int val) {
            updateTillRoot(index+1, val-nums[index]);
            nums[index]=val;
        }
        
        int Trees::FenwickTree::getSum(int l, int r)
        {
            return getPointQuery(r+1)-getPointQuery(l);
        }
    } // namespace Trees

} // namespace DataStructures
