type IterationCount = usize;
type ItemIndex = Option<usize>;

pub fn binary_search(list: Vec<i32>, item: i32) -> (ItemIndex, IterationCount) {
    let mut low: usize = 0;
    let mut high: usize = list.len() - 1;
    let mut iteration_count: usize = 0;
    while low < high {
        iteration_count += 1;
        let mid = (low + high) / 2;
        let item_at_mid = list[mid];
        if item_at_mid > item {
            high = mid - 1;
        } else if item_at_mid < item {
            low = mid + 1;
        } else {
            return (Some(mid), iteration_count);
        }
    }
    // here, low == high
    if list[low] == item {
        return (Some(low), iteration_count);
    }
    return (None, iteration_count);
}
