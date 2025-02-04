#include <bits/stdc++.h>

using namespace std;

struct PartitionedNumbers {
  int* fisrtPartLastElementOf1;
  int* secondPartFirstElementOf1;
  int* firstPartLastElementOf2;
  int* secondPartFirstElementOf2;
};

PartitionedNumbers* getPartitionedNumbers(vector<int>& nums1,
                                          vector<int>& nums2 int mid,
                                          int expectedSizeOfSinglePart) {
  int fisrtPartLastElementOf1 = mid - 1 >= 0 ? &nums1[mid - 1] : nullptr;
  int secondPartFirstElementOf1 = &nums1[mid];

  int totalFromSecond = expectedSizeOfSinglePart - mid;
  int firstPartLastElementOf2 =
      totalFromSecond - 1 >= 0 ? &nums2[totalFromSecond - 1] : nullptr;
  int secondPartFirstElementOf2 = &nums2[totalFromSecond];

  PartitionedNumbers* ans =
      new PartitionedNumbers(fisrtPartLastElementOf1, secondPartFirstElementOf1,
                             firstPartLastElementOf2, secondPartFirstElementOf2

      );
}

int medianOfTwoSortedArrays(vector<int>& nums1, vector<int>& nums2) {
  if (nums1.size() > nums2.size()) {
    vector<int>& temp = nums1;
    nums1 = nums2;
    nums2 = temp;
  }
  bool isEven = (nums1.size() + nums2.size()) % 2 == 0;
  int expectedSizeOfSinglePart = (nums1.size() + nums2.size()) / 2;
  if (!isEven) {
    expectedSizeOfSinglePart++;
  }
  int start = 0;
  int end = nums1.size();

  while (start <= end) {
    int mid = (start + end) / 2;

    PartitionedNumbers* pn =
        getPartitionedNumbers(mid, expectedSizeOfSinglePart);

    bool validFirstPartition =
        pn->fisrtPartLastElementOf1 == nullptr ||
        pn->fisrtPartLastElementOf1 <= pn->secondPartFirstElementOf2;
    bool validSecondPartition =
        firstPartLastElementOf2 == nullptr ||->firstPartLastElementOf2 <=
                                                 pn->secondPartFirstElementOf1;

    if (!validFirstPartition || (validFirstPartition && validSecondPartition)) {
      end = mid - 1;
    } else {  // !validSecondPartition
      start = mid + 1;
    }
  }

  // start will be our lower bound

  if (start == 0) {
    return isEven ? (nums2[expectedSizeOfSinglePart - 1] +
                     nums2[expectedSizeOfSinglePart]) /
                        2
                  : nums2[expectedSizeOfSinglePart - 1];
  }
  if (start > nums1.size()) {
    int startValFromSecond = expectedSizeOfSinglePart - nums1.size();
    return isEven
               ? (nums2[startValFromSecond - 1] + nums2[startValFromSecond]) / 2
               : nums2[startValFromSecond - 1];
  }

  PartitionedNumbers* pn =
      getPartitionedNumbers(start, expectedSizeOfSinglePart);
  if (!isEven) {
    return max(pn->fisrtPartLastElementOf1, pn->firstPartLastElementOf2);
  } else {
    return (max(pn->fisrtPartLastElementOf1, pn->firstPartLastElementOf2) +
            min(pn->secondPartFirstElementOf1, pn->secondPartFirstElementOf2)) /
           2;
  }
}