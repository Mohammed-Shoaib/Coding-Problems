// Problem Statement: https://www.hackerrank.com/challenges/js10-loops/problem

function vowelsAndConsonants(s) {
    let cons = [];
    for (let c of s) {
        if ('aeiou'.includes(c))
            console.log(c);
        else
            cons.push(c);
    }
    console.log(cons.join('\n'));
}