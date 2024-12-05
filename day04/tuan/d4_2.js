const fs = require('fs');
const fileContent = fs.readFileSync('input.txt', 'utf-8');

const a = fileContent.trim().split('\n').map(row => row.split('').map(i=>i));

let m = a.length
let n = a[0].length

let ans2 =0
const checkQ2 = (i,j) => {
    if(a[i-1][j-1] =='M' && a[i+1][j-1] =='M' && a[i-1][j+1] =='S' &&a[i+1][j+1] == 'S') ans2++
    if(a[i-1][j-1] =='S' && a[i+1][j-1] =='S' && a[i-1][j+1] =='M' &&a[i+1][j+1] == 'M') ans2++
    if(a[i-1][j-1] =='M' && a[i+1][j-1] =='S' && a[i-1][j+1] =='M' &&a[i+1][j+1] == 'S') ans2++
    if(a[i-1][j-1] =='S' && a[i+1][j-1] =='M' && a[i-1][j+1] =='S' &&a[i+1][j+1] == 'M') ans2++
}

const q2 = () => {
    for(let i =1;i<m-1;i++){
        for(let j =1;j< n-1;j++){
            if(a[i][j] === 'A') checkQ2(i,j)
        }
    }
}

q2()
console.log(ans2)