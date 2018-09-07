int Min(int* numbers, int length) {
    if (numbers == nullptr || length <= 0)
        throw "Invalid parameters.";
    
    int index1 = 0;
    int index2 = length - 1;
    int indexMid = index1;
    while (numbers[index1] >= numbers[index2]) {
        if (index2 - index1 == 1) {
            indexMid = index2;
            break;
        }
        indexMid = (index1 + index2) / 2;
        
        if (numbers[index1] == numbers[index2] && numbers[indexMid] == numbers[index1])
            return; //顺序查找
        
        if (numbers[indexMid] >= numbers[index1])
            index1 = indexMid;
        else if (numbers[indexMid] <= numbers[index2])
            index2 = indexMid;
        else
            throw "Valid input.";
    }
    return numbers[indexMid];
}