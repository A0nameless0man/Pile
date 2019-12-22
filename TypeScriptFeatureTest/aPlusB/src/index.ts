import readline = require('readline');

let rl = readline.createInterface({
  input: process.stdin,
  output: process.stdout
});
rl.setPrompt("a+b");
rl.prompt();
rl.question("", (input: string) =>
{
  let inputs: string[] = input.split(" ");
  let a: number[] = [];
  inputs.forEach(ele =>
  {
    a.push(parseInt(ele));
  });
  let sum :number = 0;
  a.forEach(
    ele=>
    {
      sum+=ele;
    }
  )
  console.log(sum);
})
rl.close();