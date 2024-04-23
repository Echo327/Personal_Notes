// Tested with Node.js v21.7.1

const basicsLog = require('./basics_log');
const jsonPrep = require('./json_prep');
const temperatureConverter = require('./temperature_converter')
const DateTime = require('./date_and_time')

let my_input_undef = undefined;
// Object
let Mido = {
    hero_name : "Deku", // hero_name is a property within this object
    height : 166,
    power : "One For All",
    quirks: ["Gearshift", "Fa Jin", "Danger Sense", "Blackwhip", "Smokescreen", "Float"] 
}
// Array
let heroes = [
    {
        name: "Midoriya",
        age: 16
    },
    {
        name: "Kacchan",
        age: 17
    }
]

// basics_log.js
basicsLog.basics_log(my_input_undef);

// json_prep.js
jsonPrep.json_prep(Mido, heroes);

// temperature_converter.js
console.log("---------- Temperature conversion test ----------");
let temperature = 0;
temperatureConverter.temperature_converter(temperature, "C", "F");
temperature = 56;
temperature = temperatureConverter.temperature_converter(temperature, "C", "F");
temperatureConverter.temperature_converter(0, "F", "C");
// Math.floor rounds to lower bound integer
console.log(Math.floor(temperatureConverter.temperature_converter(temperature, "F", "C")));
temperature = temperatureConverter.temperature_converter(5, "R", "F");
console.log(temperature); // undefined is returned when nothing is returned

// Date and Time
console.log("---------- Date and Time conversion test ----------");
console.log("0 ms after Unix Epoch is", DateTime.ms_to_date(0, "ms")); // Reference
console.log("1 hour after Unix Epoch is", DateTime.ms_to_date(1, "h")); // Reference + 1 hour
console.log("400 days after Unix Epoch is", DateTime.ms_to_date(400, "d")); // Reference + 400 days

// forEach syntax
// Note: forEach only works on an array.
console.log("---------- forEach syntax ----------")
let rando_nums = [6, 5, 2];
rando_nums.forEach((item => {
    console.log(item);
}));
