let arr = [3, 7, 3, 2, 1, 5, 1, 2, 2, -2, 2];

for(let i = 0; i < arr.length; i++)
{
    if(arr[i] === arr[i+2])
    console.log(arr.slice(i,i+3));

}