const fs = require('fs');
const fileContent = fs.readFileSync('input.txt', 'utf-8');

const a = fileContent.trim().split('\n').map(row => row.split('').map(i=>i));

let m = a.length
let n = a[0].length
let ans1 =0

const checkQ1 = (i,j) => {
    if( i < m-3 &&             `${a[i+1][j]}${a[i+2][j]}${a[i+3][j]}`       === 'MAS') ans1++
    if( i > 2 &&               `${a[i-1][j]}${a[i-2][j]}${a[i-3][j]}`       === 'MAS') ans1++
    if( j < n-3 &&             `${a[i][j+1]}${a[i][j+2]}${a[i][j+3]}`       === 'MAS') ans1++
    if( j > 2 &&               `${a[i][j-1]}${a[i][j-2]}${a[i][j-3]}`       === 'MAS') ans1++
    if( i < m-3 && j < n-3 &&  `${a[i+1][j+1]}${a[i+2][j+2]}${a[i+3][j+3]}` === 'MAS') ans1++
    if( i > 2 && j > 2 &&      `${a[i-1][j-1]}${a[i-2][j-2]}${a[i-3][j-3]}` === 'MAS') ans1++
    if( i > 2 && j < n-3 &&    `${a[i-1][j+1]}${a[i-2][j+2]}${a[i-3][j+3]}` === 'MAS') ans1++
    if( i < m-3 && j>2 &&      `${a[i+1][j-1]}${a[i+2][j-2]}${a[i+3][j-3]}` === 'MAS') ans1++
}

const q1 = () => {

    for(let i =0;i<m;i++){
        for(let j =0;j< n;j++){
            if(a[i][j] === 'X') checkQ1(i,j)
        }
    }
}

q1()
console.log(ans1)