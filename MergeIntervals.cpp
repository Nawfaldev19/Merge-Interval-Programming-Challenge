#include <iostream>
#include<vector>

using namespace std;

//-----------------------------------------------------Merge Intervals---------------------------------------------------------------------------------------------------

//+++++++++++++
bool BubbleUpForIntervals(vector<pair<int,int>>& vectArr, int ei)//helper function for BubbleSortForIntervals
{
    bool CH = false;// Change happen
    for (int i = 0; i <= ei; i++)
    {
        if (vectArr[i].second > vectArr[i + 1].second)//sorting after the second value in pairs
        {
            swap(vectArr[i], vectArr[i + 1]);
            CH = true;
        }
    }
    return CH;
}

void BubbleSortForIntervals(vector<pair<int, int>>& vectArr)
{
    int ei = vectArr.size() - 1;
    while (BubbleUpForIntervals(vectArr, --ei));// return when there is no change
}
//+++++++++++++

vector<pair<int, int>> MergeIntervals(vector<pair<int, int>>& vectArr)
{
    BubbleSortForIntervals(vectArr);//sorting after the second value in pairs
    vector<pair<int, int>> resArr{ pair<int, int>{vectArr[0].first, vectArr[0].second }};// default first value after sort
    for (int i = 0; i < vectArr.size()-1; i++)
    {
        if (resArr.back().second >= vectArr[i + 1].first)// if interval exists in current pair
        {
            pair<int, int> tempPair{ resArr.back().first, vectArr[i + 1].second};
            resArr.pop_back();
            resArr.push_back(tempPair);
        }
        else {
            resArr.push_back(pair<int, int>{vectArr[i + 1].first, vectArr[i + 1].second});// if there was no interval in the pair
        }
    }
    return resArr;
}

void PrintInterval(vector<pair<int, int>>& pairArr)//printing specifically intervals of pairs
{
    for (auto i = pairArr.begin(); i != pairArr.end(); i++)
    {
        cout <<"["<< i[0].first << "," << i[0].second << "]"<< '\t';
    }
    cout << endl;
}

//-----------------------------------------------------Merge Intervals---------------------------------------------------------------------------------------------------


int main()
{
    vector<pair<int, int>> pairArr{ pair<int, int> {1,2},pair<int, int> {3,8},pair<int, int> {9,10},pair<int, int> {7,9}};
    PrintInterval(pairArr);
    vector<pair<int, int>> res=MergeIntervals(pairArr);
    PrintInterval(res);//after merging intervals
}
