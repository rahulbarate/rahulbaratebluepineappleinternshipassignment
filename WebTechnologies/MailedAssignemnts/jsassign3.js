const loneOnes = (arrStr) => {
    let oneCnts = {};
    for (let str of arrStr) 
    {
        let cnt = 0;
        let lastIndex = str.indexOf("1");
        for (let i = 0; i < str.length; i++) 
        {
            let char = str.charAt(i);

            if (char !== "1") 
            {
                continue;
            } 
            else if (char === "1" && Math.abs(lastIndex - i) !== 1) 
            {
                if (i === str.length - 1) 
                {
                    cnt += 1;
                } 
                else if (str.charAt(i + 1) !== "1") 
                {
                    lastIndex = i;
                    cnt += 1;
                }
                else
                {
                    i += 1;
                    lastIndex = i;
                }
            }
            
        }
        oneCnts[str]=cnt;
        // oneCnts.push(cnt);
    }
    return oneCnts;
};

let arr = [
    "0101011010",
    "10119021101",
    "10119020111",
    "1011102110101",
    "110",
    "011",
    "010",
    "101",
    "0110",
    "1101",
    "0101",
    "1001",
];
console.log("Lone ones in given strings : ");
console.table(loneOnes(arr));
