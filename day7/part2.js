const fs = require('node:fs');

fs.readFile("./input.txt", 'ASCII', (err, data) => {
	if (err) {
		console.log(err);
		return;
	}
	console.log(start(data.split('\n').map(s => s.split(''))));
});

function start(data) {
	var i = data[0].indexOf('S');

	var counts = new Array(data.length);
	for (var j = 0; j < counts.length; j++) {
		counts[j] = new Array(data[0].length);
	}

	return traces(i, 0, counts, data);
}

function traces(i, j, counts, data) {	
	if(j + 1 > data.length - 1) {
		counts[j][i] = 1;
		return 1;
	}
	if (counts[j][i] != undefined) {
		return counts[j][i];
	}
	if (data[j+1][i] == '^') {
		counts[j][i] = traces(i-1, j+1, counts, data) + traces(i+1, j+1, counts, data);
		return counts[j][i];
	}
	counts[j][i] = traces(i, j+1, counts, data);
	return counts[j][i];
}
