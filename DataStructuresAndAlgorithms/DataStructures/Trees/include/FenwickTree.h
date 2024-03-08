#include <vector>
namespace DataStructures
{
    namespace Trees
    {
        class FenwickTree
        {
        private:
            std::vector<int> arr,nums;
            void updateTillRoot(int index, int diff);
            int getPointQuery(int index);
        public:
            FenwickTree(std::vector<int>& nums);
            ~FenwickTree();
            int getSum(int l, int r);
            void update(int index, int val);
        };
    } // namespace Trees
} // namespace DataStructures
