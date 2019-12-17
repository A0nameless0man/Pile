const hello: string = 'HelloWorld';
console.log(hello);
class Greeting
{
    greet(name: string | number|string[]): void
    {
        var type: string = typeof (name)
        if (type == 'string')
        {
            console.log(`Hello ${name}`);
            for(let c of <string>name)
            {
                console.log(c);
            }
        }
        else if (type == 'number')
        {
            for (var i: number = 0; i < name; ++i)
            {
                console.log(`Hello ${i}`);
            }
        }
        else if(type == 'array')
        {
            
        }
    }
}
var gr: Greeting = new Greeting();
gr.greet('me');
gr.greet(5);
console.log(typeof(['a']));
console.log(typeof (typeof (console)));