const fs = require('fs');
const fileContent = fs.readFileSync('input.txt', 'utf-8');

const input = fileContent.split('\n')
.filter(line => line.trim() !== '')
.map(line => line.split('|').map(num => parseInt(num, 10)));

const fileContent2 = fs.readFileSync('input2.txt', 'utf-8');
const input2 = fileContent2.split('\n')
.map(line => line.split(',').map(num => parseInt(num, 10)));

let map = new Map()
for(let i of input){
    if(map.has(i[0])) map.set(i[0], [...map.get(i[0]), i[1]])
    else map.set(i[0],[i[1]])
}

const q2 = () => {
    let ans =0

    for(let arr of input2){
        let check = true
        for (let i=0; i<arr.length-1;i++){
            if(!(map.has(arr[i]) && map.get(arr[i]).includes(arr[i+1]))){
                check = false
                break
            }
        }
        if(!check){
            arr.sort((a, b) => (map.has(a) && map.get(a).includes(b)) ? -1 : 1)
            ans += arr[Math.floor(arr.length/2)]
        } 
    }
    return ans
}

console.log(q2())