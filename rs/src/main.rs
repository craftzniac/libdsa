mod binary_search;

fn main() {
    let sorted_list = vec![2, 3, 4, 5, 6, 7];
    // let sorted_list = vec![1, 2, 3, 4, 5, 6, 8, 10, 11, 12, 13];
    let item = 13;
    let res = binary_search::binary_search(sorted_list, item);

    let (index_opt, iter_count) = res;
    if let Some(index) = index_opt {
        println!(
            "Index of {}: {}, IteractionCount: {}",
            item, index, iter_count
        );
    } else {
        println!("{} was not found, iterationCount: {}", item, iter_count);
    }
}
