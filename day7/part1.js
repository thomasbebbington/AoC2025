const fs = require('node:fs');

fs.readFile("./input.txt", 'ASCII', (err, data) => {
	if (err) {
		console.log(err);
		return;
	}
	console.log(start(data.split('\n').map(s => s.split(''))));
});

function start(data) {
	var curr = data[0];
	curr = curr.map((e) => {
		switch (e) {
			case 'S':
				return '|';
			default: 
				return '.';
		}
	});
	
	var total = 0;
	var tmp = new Array(curr.length);

	for (let line of data.slice(1)) {
		tmp.fill('.');
		
		if (curr[0] == '|') {
			if (line[0] == '^') {
				tmp[1] = '|';
				total++;
			} else {
				tmp[0] = '|';
			}
		} 

		for (let i = 1; i < line.length - 1; i++) {
			if (curr[i] == '|') {
				if (line[i] == '^') {
					tmp[i-1] = '|';
					tmp[i+1] = '|';
					total++;
				} else {
					tmp[i] = '|';
				}
			}
		}

		if (curr[line.length - 1] == '|') {
			if (line[line.lenth - 1] == '^') {
				tmp[line.length - 2] = '|';
				total++;
			} else {
				tmp[line.length - 1] = '|';
			}
		}
		curr = tmp.slice();
	}

	return total;
}
