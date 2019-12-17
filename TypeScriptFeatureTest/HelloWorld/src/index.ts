const hello: string = 'HelloWorld';
console.log(hello);
class Greeting
{
    greet(name: string | number): void
    {
        var type: string = typeof (name)
        if (type == 'string')
        {
            console.log(`Hello ${name}`);
        }
        else if (type == 'number')
        {
            for (var i: number = 0; i < name; ++i)
            {
                console.log(`Hello ${i}`);
            }
        }
    }
}
var gr: Greeting = new Greeting();
gr.greet('me');
gr.greet(5);
console.log(typeof (typeof (console)))