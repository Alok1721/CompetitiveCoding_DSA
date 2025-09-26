/* let name="alok";
let age=21;
console.log(name,age); */

//! 1)creating function to print name and age + add timeout  + make function async
/* function printNameAndAge(name,age){
    setTimeout(() => {
        console.log(name, age);
    }, 2000);
}
function printNameAndAge2(name,age){
    setTimeout(() => {
        console.log(name, age);
    }, 1000);
}
printNameAndAge("alok",21);
printNameAndAge2("dhiraj",19); */

//! 2)print 1-100 numbers
/* for(let i=1;i<=100;i++)
{
    console.log(i);
} */

//! 3)print 1-100 without using loop

/* function printNumbers(start,end)
{
    console.log(start);
    if(start==end)
    {
        return ;
    }
    printNumbers(start+1,end);
}
printNumbers(1,100); */
//! 4)do summation of array
/* function sumArray(arr)
{
    if(arr.length==0)
    {
        return 0;
    }
    return arr[0]+sumArray(arr.slice(1));
}
console.log(sumArray([1,2,3,4,5])); */
//*using reduce
/* function sumArray(arr)
{
    return arr.reduce((a,b)=>a+b,0);
}
console.log(sumArray([1,2,3,4,5])); */
//*using for loop
/* function sumArray(arr)
{
    let sum=0;
    for(let i=0;i<arr.length;i++)
    {
        sum+=arr[i];
    }
    return sum;
}
console.log(sumArray([1,2,3,4,5])); */

//! 5) find max,min,number of unique element
/* function findMaxMinUnique(arr)
{
    let max=arr[0];
    let min=arr[0];
    for(let i=0;i<arr.length;i++)
    {
        if(arr[i]>max)
        {
            max=arr[i];
        }
        if(arr[i]<min)
        {
            min=arr[i];
        }
    }
    let unique=new Set(arr);
    return {max,min,unique};
}
console.log(findMaxMinUnique([1,2,3,4,5,6,6])); */

//! 6) add mising ele in array
/* const months=["Jan","Feb","Apr","May","Jun","Jul","Aug","Sep","Oct","Nov","Dec"];
months.splice(2,0,"Mar");
console.log(months);
 */
//! 7) second larget in array
/* function secondLargest(arr)
{
    let first=arr[0];
    let second=arr[0];
    for(let i=0;i<arr.length;i++)
    {
        if(arr[i]>first)
        {
            second=first;
            first=arr[i];
        }
        else if(arr[i]<first && arr[i]>second)
        {
            second=arr[i];
        }
    }
    return second;
}
console.log(secondLargest([1,2,3,4,5,6,6])); */

//! 8) sort the array
function sortArray(arr)
{
    return arr.sort((a,b)=>a-b);
}
console.log(sortArray([1,21,3,14,5,6,6]));  
