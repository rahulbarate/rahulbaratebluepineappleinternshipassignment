const demo = (p1,p2)=>{
    console.log("arrow sum: "+(p1+p2));
}
const demo2 = function(p3,p4){
    console.log("normal sub: " +(p3-p4));
}

const convertor = (funstr)=>{
    let params = funstr.slice(funstr.indexOf("(")+1,funstr.indexOf(")")).split(",");
    let body = funstr.slice(funstr.indexOf("{"),funstr.lastIndexOf("}")+1);
    funstr.startsWith("(")?convertToNormalFun(params,body):convertToArrowFun(params,body);
}
const convertToNormalFun = (params,body)=>{
    eval("function normalFun("+params.join(",")+")"+body);
    normalFun(2,3);
    console.log("After Arrow to Normal :\n"+normalFun);

}
const convertToArrowFun = (params,body)=>{
    eval("arrowFun = ("+params.join(",")+")=>"+body);

    arrowFun(4,5);
    console.log("After Normal to Arrow:"+arrowFun);
}

convertor(""+demo);
convertor(""+demo2);
