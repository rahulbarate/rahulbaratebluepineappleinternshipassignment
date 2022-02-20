const sumProd = (...allvals) => {
    let sum = allvals.reduce((sum, val) => sum + val);
    let sumstr = sum+"";

    let digits = getDigits(sumstr);
    let prod =""+getProd(digits);

    while(prod.length > 1) 
        prod = ""+getProd(getDigits(prod));

    
    console.log(`For values ${""+allvals} single digit product is ${prod}`);
}
const getDigits = (numstr)=>{
    digits = [];
    numstr = (+numstr)
    while(numstr!=0)
    {
        digits.push(Math.trunc(numstr%10));
        numstr = Math.trunc(numstr/10);
    }
    return digits;
}

const getProd = (arr)=>{
    return arr.reduce((prod,curr)=> prod*curr);
}

// sumProd(1,2,3);
// sumProd(1,2,3,4);
sumProd(12,15,20);