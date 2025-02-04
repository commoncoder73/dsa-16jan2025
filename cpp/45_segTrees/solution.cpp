#include <bits/stdc++.h>

using namespace std;

struct SegTreeNode {
  int start;
  int end;
  int result;
  int pendingProcessingOfChildren;
}


int buildSegmentTree(vector<int>& nums, int start, int end, vector<SegTreeNode>& segTree, int segTreeIndex) {
  if (start == end) {
    segTree[segTreeIndex].start = start;
    segTree[segTreeIndex].ens = end;
    segTree[segTreeIndex].result = nums[start];
    return nums[start];
  }
  int mid = (start + end) / 2;
  int leftResult =
      buildSegmentTree(nums, start, mid, segTree, 2 * segTreeIndex + 1);
  int rightResult =
      buildSegmentTree(nums, mid + 1, end, segTree, 2 * segTreeIndex + 2);
  segTree[segTreeIndex].start = start;
  segTree[segTreeIndex].ens = end;
  segTree[segTreeIndex].result = leftResult + rightResult;
  return leftResult + rightResult;
}


int lazyUpdate(vector<SegTreeNode>& st, int sti, int uStart, int uEnd, int uVal) {
    if (st[sti].start == st[sti].end) {
        st[sti] += uVal;
        return uVal;
    }
    if (uStart <= st[sti].start && st[sti].end <= uEnd) {
        int diff  = (st[sti].end - st[sti].start + 1 )*uVal
        st[sti] += diff;
        st[sti].pendingProcessingOfChildren += uVal;
        return diff;
    }
    if (st[sti].start > st[sti].end) {
        return 0;
    }
    int mid = (st[sti].start + st[sti].end)/2;
    int lr = lazyUpdate(st, 2*st+1, uStart, mid, uVal);
    int rr = lazyUpdate(st, 2*st+r, mid+1, uEnd, uVal);
    st[sti] += (lr+rr);
    return lr+rr;
}

int lazyQuery(vector<SegTreeNode>& st, int sti, int qStart, int qEnd, int uVal) {
    if (st[sti].start > st[sti].end) {
        return 0;
    }
     if (st[sti].start == st[sti].end) {
        st[sti] += uVal;
        return st[sti];
    }
    if (qStart <= st[sti].start && st[sti].end <= qEnd) {
        st[sti] += uVal;
        st[sti].pendingProcessingOfChildren += uVal;
        return st[sti];
    }
    int mid = (st[sti].start + st[sti].end)/2;
    int totalUpateOnChildren = uVal + st[sti].pendingProcessingOfChildren;
    int lr = lazyUpdate(st, 2*st+1, qStart, mid, totalUpateOnChildren);
    int rr = lazyUpdate(st, 2*st+r, mid+1, qEnd, totalUpateOnChildren);
    st[sti].result += uVal;
    st[sti].pendingProcessingOfChildren = 0;
    return lr+rr;
}