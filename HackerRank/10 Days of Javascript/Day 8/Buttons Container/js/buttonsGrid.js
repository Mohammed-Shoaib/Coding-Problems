// Problem Statement: https://www.hackerrank.com/challenges/js10-buttons-container

let div = document.getElementById('btns');

for (let i = 1; i < 10; i++) {
	let button = document.createElement('button');
	button.id = 'btn' + i;
	button.textContent = i.toString();
	div.appendChild(button);
}

let btn5 = document.getElementById('btn5');

btn5.addEventListener('click', () => {
	let btns, btn, text;
	btns = [4, 7, 8, 9, 6, 3, 2, 1, 4];	
	for (i = 0; i < btns.length - 1; i++) {
		btn = document.getElementById('btn' + btns[i]);
		text = btns[btns.indexOf(parseInt(btn.textContent)) + 1];
		btn.textContent = text;
	}
});