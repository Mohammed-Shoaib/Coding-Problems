// Problem Statement: https://www.hackerrank.com/challenges/js10-binary-calculator

// Get reference to all the elements
res = document.getElementById('res');
btn0 = document.getElementById('btn0');
btn1 = document.getElementById('btn1');
btnClr = document.getElementById('btnClr');
btnEql = document.getElementById('btnEql');
btnSum = document.getElementById('btnSum');
btnSub = document.getElementById('btnSub');
btnMul = document.getElementById('btnMul');
btnDiv = document.getElementById('btnDiv');

// Adding the click event listeners

btn0.addEventListener('click', () => res.textContent += btn0.textContent);
btn1.addEventListener('click', () => res.textContent += btn1.textContent);

btnSum.addEventListener('click', () => res.textContent += '+');
btnSub.addEventListener('click', () => res.textContent += '-');
btnMul.addEventListener('click', () => res.textContent += '*');
btnDiv.addEventListener('click', () => res.textContent += '/');

btnClr.addEventListener('click', () => res.textContent = '');
btnEql.addEventListener('click', () => {
	let [op1, op, op2] = res.textContent.split(/\b/);
	[op1, op2] = [parseInt(op1, 2), parseInt(op2, 2)];
	res.textContent = Math.floor(eval(op1 + op + op2)).toString(2);
});