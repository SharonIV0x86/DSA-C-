// The formula used in quadratic probing is based on quadratic equations. 
// It determines the offset or the number of slots to skip to find the next available slot.
//  The offset is calculated by squaring the number of attempts made and adding it to the original hash index.

// For example, if the initial hash index is 5 and
//  it's already occupied, quadratic probing would calculate the offset by squaring 1 
//  (since it's the first attempt) and adding it to the original index. So, the offset would be 1^2 + 5 = 6. 
//  The algorithm would then check the slot at index 5 + 6 = 11. If that slot is occupied, it would continue to the next slot based on a new offset calculation.