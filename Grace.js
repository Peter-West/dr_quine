function yo() {
	var fs = require('fs');
	var data = yo.toString()+"\nyo();\n";

	fs.open('./Grace_kid.js', 'wx', (err, fd)=> {
		if (err) {
			if (err.code === 'EEXIST') {
				console.error('file already exist');
				return ;
			}
			throw err;
		}
		fs.write(fd, data, 0, data.length, null, function(err){
			if (err) {
				fs.close(fd, function() {
					console.log('file written');
				});
				console.error(err + 'can\'t write');
				return ;
			}
		});
	});
}
yo();
