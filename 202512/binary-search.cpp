/**

bin_search_(sorted_arr, target)
    start_idx
    end_idx
    while(start < end)
        mid_idx = start + | sub_arr_size / 2 | : sub_arr_size = end-start
        if arr[mid] == target : ret arrmid
        elif arrmid < target : right half : start_idx = mid + 1, cont
        elif arrmid > target : left half : end_idx = mid - 1, cont

    ret -1

 */

// implement it in C++