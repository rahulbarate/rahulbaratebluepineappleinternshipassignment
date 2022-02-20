const getDepth = (arr)=>{
    let depth = 1
    for(ele of arr)
    {
        if(Array.isArray(ele))
        return depth+getDepth(ele);
        else
        continue;
    }
    return depth;
     
}

console.log("Depth of given array  is "+getDepth([1, 2, 3, 4]));
console.log("Depth of given array  is "+getDepth([1, [2, 3, 4]]));
console.log("Depth of given array  is "+getDepth([1, [2, [3, 4]]]));
console.log("Depth of given array  is "+getDepth([1, [2, [3, [4]]]]));