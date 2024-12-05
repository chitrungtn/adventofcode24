const fs = require('fs');

const fileContent = fs.readFileSync('input.txt', 'utf-8');

const q2 = () => {
    const regex = /(mul\(\d{1,3},\d{1,3}\)|do\(\)|don't\(\))/g;
    const matches = fileContent.match(regex);
    let ans = 0
    let ignore= false
    for (let i of matches) {
        if(i === 'do()'){
            ignore = false
        }
        else if(i ==="don't()"){
            ignore = true
        }
        else if(!ignore){
            const a = i.slice(4, -1);
            const num = a.split(',');
            ans += num[0] * num[1]
        }
    }
    return ans
}

console.log(q2());

