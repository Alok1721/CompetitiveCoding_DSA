//addition
function add(a,b){
    return a+b;
}

//subtraction
function sub(a,b){
    return a-b;
}

//multiplication
function mul(a,b){
    return a*b;
}
//division
function div(a,b){
    return a/b;
}

//interface for calculator
function calculator(a,b,operation){
    return operation(a,b);
}

console.log(calculator(10,20,add));
console.log(calculator(10,20,sub));
console.log(calculator(10,20,mul));
console.log(calculator(10,20,div));
