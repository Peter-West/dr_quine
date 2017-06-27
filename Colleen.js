/*
	first
*/
function yop(){
	var i;
	for(i = 0; i < 8; i++) {
		alert("Chalut");
	}
}
function falsh(){
	/*
		second
	*/
	process.stdout.write("/*\n\tfirst\n*/\n"+yop.toString()+"\n"+falsh.toString()+"\n"+"falsh();\n");
	return ;
}
falsh();
