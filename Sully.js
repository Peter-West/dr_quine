var nb = 5;
function yo() {
	var fs = require('fs');
	var strToMatch = './Sully_' + nb + '.js';
	process.stdout.write(strToMatch + '\n');
	if (fs.existsSync(strToMatch)) {
			process.stdout.write("yo");
			nb = nb - 1;
	}		
	var data = 'var nb = ' + nb + ';\n' + yo.toString()+"\nyo();\n";
	var path = 'Sully_' + nb + '.js';

	fs.open(path, 'wx', (err, fd)=> {
		if (err) {
			if (err.code === 'EEXIST') {
				console.error('file already exist');
				return ;
			}
			throw err;
		}
		fs.write(fd, data, 0, data.length, null, function(err){
			if (err) {
				throw 'error writing file: ' + err;
			}
			fs.close(fd, function() {
					console.log('file written');
			});
		});
	});
	if (nb > 0) {
		var exec = require('child_process').exec;
		var cmd = 'node ' + path;

		exec(cmd, function(err, stdout, stderr) {
			if (err) {
				console.error(stdout + ' ' + stderr);
			}
		});
	}
}
yo();
