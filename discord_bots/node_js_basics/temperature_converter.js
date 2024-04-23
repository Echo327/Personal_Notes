// if - else if
// module.exports = {
//     temperature_converter: function(value, start_unit, end_unit){
//         let converted_value;
//         if (start_unit == "C"){
//             if (end_unit == "F"){
//                 converted_value = (value * 9/5) + 32;
//             }
//         }
//         else if (start_unit == "F"){
//             if (end_unit == "C"){
//                 converted_value = (value - 32) * 5/9;
//             }
//         }
//         console.log("Converted", value, "°"+start_unit, "to", converted_value, "°"+end_unit, ".");
//         return converted_value;
//     }
// }

// switchcase
module.exports = {
    temperature_converter: function(value, start_unit, end_unit){
        // Converts value temperature from start_unit to end_unit
        // Example: 50°C -> °F (value = 50, start_unit = C, end_unit = F)
        let converted_value = undefined;
        switch (start_unit){
            case "C":
                if (end_unit == "F"){
                    converted_value = (value * 9/5) + 32;
                }
                break;
            case "F":
                if (end_unit == "C"){
                    converted_value = (value - 32) * 5/9;
                }
                break;
            default:
                console.log("Unrecognised conversion:", "°"+start_unit, "to", "°"+end_unit+".");
        }
        if (converted_value != undefined){
            console.log("Converted", value, "°"+start_unit, "to", converted_value, "°"+end_unit+".");
            return converted_value;
        }
    }
}
