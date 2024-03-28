module.exports = {
    basics_log: function(my_inp){
        // console.log() + variables
        let my_str = "Welcome to Node.js!"; // scope = block
        console.log(my_str);
        console.log("This is a string: 4. This is an integer:", 4);
        var my_var = 2+3/4; // scope = function
        const my_var_2 = my_var; // cannot be reassigned
        console.log("2+3/4 =",my_var);
        // For loop
        let arrr = [];
        for (let i=0; i<10; i++){
            // If conditional
            let denominator = 2;
            if (i%denominator == 0){
                process.stdout.write("Adding "+i+" to array.\n");
                arrr[i/denominator] = i;
            }
            else if (denominator == 2){
                console.log("We do not like odd things here.")
            }
            else{
                console.log("I do nothing!")
            }

        }
        for (let i=0; i<arrr.length; i++){
            process.stdout.write("Array index "+i+" contains "+arrr[i]+".\n");
        }
        console.log("The whole array is: ", arrr);
        if (my_inp == undefined)
        {
            console.log("Everything is not defined.")
        }
    }
}
