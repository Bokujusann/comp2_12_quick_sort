#define WIN32_LEAN_AND_MEAN             // Windows ヘッダーからほとんど使用されていない部分を除外する
#include "Windows.h"                    // Windows API の機能定義

#include "../include/lib_func.h"

void swap(item* a, item* b)
{
    item temp = *a;
    *a = *b;
    *b = temp;

}

item* partition(item* low, item* high)
{
    int a = high->key;
    item* i = low - 1;

    for (item* j = low; j < high; ++j)
    {
        if (j->key <= a)
        {
            ++i;
            swap(i, j);


            /**/
        }
    }
    swap(i + 1, high);
    return i + 1;
}

void quickSortRecursive(item* low, item* high)
{
    if (low < high)
    {

        item* pi = partition(low, high);

        quickSortRecursive(low, pi - 1);
        quickSortRecursive(pi + 1, high);
    }
}

bool quick_sort(item* begin, const item* end)
{
	// ToDo: クイックソートで並び替えてください
    
    if (begin == NULL || end == NULL || begin >= end)
    {
        return false; // 無効な引数の場合は false を返す
    }

    quickSortRecursive(begin, (item*)(end - 1));
    return true;
}
