
type Index = number;
type NumOfIterations = number;

function binarySearch(list: number[], item: number): [Index | null, NumOfIterations]{
    let numOfIterations = 0;

    if (list.length == 0){
        return [null, numOfIterations];
    }

    let low = 0;
    let high = list.length - 1;

    while (low < high) {
        numOfIterations += 1;

        const mid = Math.floor((low + high) / 2);
        const itemAtMid = list[mid];
        console.log(`mid item: ${itemAtMid}`)
        if (itemAtMid == undefined){
            return [null, numOfIterations];
            // will actually never be null since 'high' will always be valid
        }

        if (itemAtMid > item) {
            high = mid - 1;
        } else if (itemAtMid < item) {
            low = mid + 1;
        } else {
            return [mid, numOfIterations];
        }
    }

    if (list[low] == item){
        return [low, numOfIterations];
    }else {
        return [null, numOfIterations];
    }
}

const inputList = [1, 2, 3, 4, 5, 6, 8, 10, 11, 12, 13];
const item = 13;
const [res, iters] = binarySearch(inputList, item);
console.log(`index of ${item}: ${res} (with ${iters} iters)`);
