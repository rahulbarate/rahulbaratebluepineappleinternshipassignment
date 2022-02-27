// --------- BOILERPLATE -----------------------------------------------------
const _l = msg => console.log('Output ==> [' + msg + ']');
// --------- BOILERPLATE -----------------------------------------------------

const nums = [1, 2, 3, 4, 5];
/*
for(var i=0;i<nums.length;i++){
  nums[i] = nums[i] + 2;
}
_l("incremented = " + nums);
*/


//Create a new array from values such that each value = orig value + 2
// use map function

const v = function (x){
    return x+2;
}

const getInc = function(n){
  //closure
  return function(x){
    return x+n;
  }
}

/*
var newArr = [];
let incr = getInc(3);
for(var i=0;i<nums.length;i++){
  newArr.push(incr(nums[i]));
}
_l("Incremented with newArr = " + newArr);
incr = getInc(10);
newArr = [];
for(var i=0;i<nums.length;i++){
  newArr.push(incr(nums[i]));
}
_l("Incremented with newArr = " + newArr);

*/


//map -> for each value in array, apply the passed fun and push it into a new array

const f = function(p){
  return p+2;
}
const numplus2s = nums.map(f); // creates copy without changing original nums

_l('-------');
_l(numplus2s);
_l('-------');

const names = ['Pooja', 'Prathiksha', 'Renuka', 'Rishikesh'];

function nameLen(name){
    return name.length + 2;
}

//TODO - create new array with (length + 2) from names array

let newArr = names.map((name)=>nameLen(name));
_l(newArr);
