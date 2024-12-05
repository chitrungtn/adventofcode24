const fs = require('fs');

const fileContent = fs.readFileSync('input.txt', 'utf-8');

const q1 = () => {
    const regex = /mul\(\d{1,3},\d{1,3}\)/g;
    const matches = fileContent.match(regex);
    let ans = 0
    for (let i of matches) {
        const a = i.slice(4, -1);
        const num = a.split(',');
        ans += num[0] * num[1]
    }
    return ans
}

console.log(q1());

