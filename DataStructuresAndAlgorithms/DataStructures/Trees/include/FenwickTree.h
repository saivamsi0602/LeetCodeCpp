#include <vector>
namespace DataStructures
{
    namespace Trees
    {
        class FenwickTree
        {
        private:
            /* data */
            std::vector<int> arr, tree;
            void updateTree(int index, int diff){
                for(int i=index;i<tree.size();i+=(i&-i))
                    tree[i]+=diff;
            }
            int pointQuery(int index){
                int res = 0;
                for(int i=index;i>0;i-=(i&-i)){
                    res+=tree[i];
                }
                return res;
            }
        public:
            FenwickTree(const std::vector<int>& nums): arr(nums){
                int n = arr.size();
                tree.resize(n+1,0);
                for(int i=0;i<n;i++)
                    updateTree(i+1,arr[i]);
            }
            void update(int index, int val){
                updateTree(index+1,val-arr[index]);
                arr[index]=val;
            }
            int rangeQuery(int left, int right){
                return pointQuery(right+1)-pointQuery(left);
            }
        };
    } // namespace Trees
} // namespace DataStructures
