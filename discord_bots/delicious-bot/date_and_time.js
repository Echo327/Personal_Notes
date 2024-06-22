// conversion rates
const dict = {
    "ms"    : 1,        // 1 millisecond
    "s"     : 1000,     // 1 second = 1000 ms
}
dict["m"] = 60 * dict["s"];     // 1 minute = 60 s
dict["h"] = 60 * dict["m"];     // 1 hour = 60 m
dict["d"] = 24 * dict["h"];     // 1 day = 24 h

module.exports = {
    ms_to_date: function(value, unit){
        // Converts UNIX time in Date (string format)
        let milliseconds = value*dict[unit];
        let date = new Date(milliseconds);
        return date.toString();
    },

    ms_to_age: function(value, unit){
        // Converts time difference into human readable format
        let milliseconds = value*dict[unit];
        let nb_days = Math.floor(milliseconds/dict["d"]);
        console.log("days ", nb_days);
        // to complete
    }
}