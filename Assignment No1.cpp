// Assignment No1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

//1:First Unique Character in a string
int UniqueCharacter(string s)
{
    int  count[26]{};
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;    
    }
    for (int i = 0; i < s.length(); i++)
    {
        if (count[s[i] - 'a'] == 1)
            return i;
    }
    return -1;
}

//2:valid Anagram
bool IsValid(string s, string t)
{
    if (s.length() != t.length())
        return false;
    sort(begin(s), end(s));
    sort(begin(t), end(t));
    return s == t;
}
bool IsValidAnnagram(string s, string t)
{
    if (s.length() != t.length())
        return false;
    vector<int>count(26, 0);
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']++;
    }
    for (int i = 0; i < s.length(); i++)
    {
        count[s[i] - 'a']--;
        if (count[s[i] - 'a'] < 0)
            return false;
    }
    return true;     
}
//3:Find the first Accurance in the string
int strStr(string haystack, string needle)
{
    int n = haystack.length();
    for (int i = 0; i < n; i++)
    {
        if (haystack[i] == needle[0])
                if (haystack.substr(i, needle.length() + i) == needle)
                {
                    return i;
                }
    }
    return -1;
}
//4:Search Insert Position 
int searchInsert(vector<int>& nums, int target) 
{
    int start = 0;
    int end = nums.size() - 1;
    while (start <= end)
    {
         int mid = start + (end-start)/ 2;
         if (nums[mid] == target)
             return mid;
         else if (nums[mid] > target)
             end = mid - 1;
         else if(nums[mid]<target)
         {
             start = mid + 1;
         }
         return start;

    }
}
//5:Two Sums
vector<int> twoSum(vector<int>& nums, int target) {
    unordered_map<int, int>num1;
    vector<int>r;
    for (int i = 0; i < nums.size(); ++i) {
        int complement = target - nums[i];
        if (num1.find(complement) != num1.end()) {
            r.push_back(num1[complement]);
            r.push_back(i);
            break;
        }
        num1[nums[i]] = i;
    }
    return r;

}
//6:Happy Number
bool IsHappy(int n)
{
    unordered_map<int, bool >map;
    while (n != 1 && map.find(n) == map.end()) {
        map[n] = true; 
        int sum = 0; 
        while (n > 0) {
            int digit = n % 10;
            sum += digit * digit;
            n /= 10;
        }
        n = sum;
    }
    return n == 1;
}
//7:Reverse Integer
int reverse(int x)
{
    int rev = 0;
    while (x != 0)
    {
        int digit = x % 10;
        x /= 10;
        if (rev > INT_MAX / 10 || (rev == INT_MAX / 10 && digit > 7)) return 0;
        if (rev < INT_MIN / 10 || (rev == INT_MIN / 10 && digit < -8)) return 0;

        rev = rev * 10 + digit;
    }
    return rev;
}
//8:Rotate an array
void rotate(vector<int>& nums, int k) 
{
    int n = nums.size();
    k = k % n; 
    reverse(nums.begin(), nums.end()); 
    reverse(nums.begin(), nums.begin() + k); 
    reverse(nums.begin() + k, nums.end()); 


}
//9:Find the Peak Element 
int findPeakElement(vector<int>& nums) 
{
    int left = 0;
    int right = nums.size() - 1;
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] < nums[mid + 1]) {
            left = mid + 1;
        }
        else {
            right = mid;
        }
    }
    return left;
}
//10:Color Sorting
bool BubbleSort(vector<int>& VS) 
{
    bool CH = false;
    for (int i = 0; i < VS.size() - 1; i++) {
        if (VS[i] > VS[i + 1]) {
            swap(VS[i], VS[i + 1]);
            CH = true;
        }
    }
    return CH;
}

void BubbleUp(vector<int>& VS) {
    while (BubbleSort(VS));
}
void sortColors(vector<int>& nums) {
    BubbleUp(nums);
}




int main()
{
    string s;
    s = "lleetcode";
    cout << "The First Unique Character is:" << UniqueCharacter(s) << endl;
    string first, second;
    first = "code";
    second = "code";
    cout << IsValid(first, second)<<endl;
    cout << IsValidAnnagram(first, second) << endl;
    string f, d;
    f = "sadbutsad";
    d = "sad";
    cout << strStr(f, d) << endl;
    vector<int>nums = {1,3,5,6};
    int target = 5;
    int target2 = 6;
    int target3 = 2;
    cout << "The Target element of the index is" << searchInsert(nums, target)<<endl;
    cout << "Index of 5 in [1, 3, 5, 6]: " << searchInsert(nums, target) << endl;
    cout << "Index of 6 in [1,3,5,6]:" << searchInsert(nums, target2) << endl;
    cout << "Index of 8 in [1,3,5,6]:" << searchInsert(nums, target3) << endl;
    int HappyNumber;
    HappyNumber = 4;
    cout << IsHappy(HappyNumber) << endl;
    int digit = 345;
    cout << reverse(digit) << endl;
    vector<int>nums2 = { 1, 2, 3, 4, 5, 6, 7 }; 
    int k = 3; 
    rotate(nums2, k);

    cout << "Rotated array: ";
    copy(nums2.begin(), nums2.end(), ostream_iterator<int>(cout, " "));
    cout << endl;

    vector<int> Nums1 = { 1, 2, 3, 1 };
    cout << "Peak element index: " << findPeakElement(Nums1) << endl; 

    vector<int> Nums2 = { 1, 2, 1, 3, 5, 6, 4 };
    cout << "Peak element index: " << findPeakElement(Nums2) << endl; 

    vector<int> colors= { 2, 0, 2, 1, 1, 0 }; 
    sortColors(colors);
    cout << "Sorted Colors: ";
    for (int color : colors) {
        cout << color << " ";
    }
    cout << endl;





    return 0;

    
       

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
