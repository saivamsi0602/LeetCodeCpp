#include <vector>

namespace DataStructures
{
    namespace Trees
    {
        class SegmentTree{
        private:
            std::vector<int> arr, nums;
            void buildTree(int pos, int sl, int sr){
                if(sl==sr) arr[pos] = nums[sl];
                else{
                    int mid = (sl+sr)/2;
                    buildTree(2*pos+1,sl,mid);
                    buildTree(2*pos+2,mid+1,sr);
                    arr[pos] = std::min(arr[2*pos+1], arr[2*pos+2]);
                }
            }
            void updateTree(int pos, int sl, int sr, int index, int val){
                if(sl==sr){
                    arr[pos]=val;
                }else{
                    int mid = (sl+sr)/2;
                    if(index<=mid) updateTree(2*pos+1, sl, mid,index,val);
                    else updateTree(2*pos+2,mid+1,sr,index,val);
                    arr[pos] = std::min(arr[2*pos+1],arr[2*pos+2]);
                }
            }
            int getRangeQuery(int pos, int sl, int sr, int l, int r){
                if(l==sl && r==sr) return arr[pos];
                int mid = (sl+sr)/2;
                if(l>mid) return getRangeQuery(2*pos+2,mid+1,sr,l,r);
                else if(r<=mid) return getRangeQuery(2*pos+1,sl,mid,l,r);
                return std::min(getRangeQuery(2*pos+2,mid+1,sr,mid+1,r),getRangeQuery(2*pos+1,sl,mid,l,mid));
            }
        public:
            SegmentTree(std::vector<int>& pNums): nums(pNums){
                int n = nums.size(), sz = n;
                sz |= sz>>1;
                sz |= sz>>2;
                sz |= sz>>4;
                sz |= sz>>8;
                sz |= sz>>16;
                sz |= (sz<<1);
                arr.resize(sz, INT_MAX);
                buildTree(0,0,n-1);
            }

            int getMin(int l, int r){
                return getRangeQuery(0,0,nums.size()-1,l,r);
            }

            void update(int index, int val){
                updateTree(0,0,nums.size()-1,index,val);
                nums[index]=val;
            }
        };
    } // namespace Trees
    
} // namespace DataStructures
