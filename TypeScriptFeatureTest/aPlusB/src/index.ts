import readline = require('readline');

let rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
rl.setPrompt("a+b");
rl.prompt();