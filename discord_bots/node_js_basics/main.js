
const basicsLog = require('./basics_log');
const jsonPrep = require('./json_prep');
const temperatureConverter = require('./temperature_converter')

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
let temperature = 0;
temperatureConverter.temperature_converter(temperature, "C", "F");
temperature = 56;
temperature = temperatureConverter.temperature_converter(temperature, "C", "F");
temperatureConverter.temperature_converter(0, "F", "C");
temperatureConverter.temperature_converter(temperature, "F", "C");
temperature = temperatureConverter.temperature_converter(5, "R", "F");
console.log(temperature); // undefined is returned when nothing is returned
