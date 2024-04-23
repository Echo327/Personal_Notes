module.exports = {
    ms_to_date: function(value, unit){
        // Converts UNIX time in Date (string format)
        const dict = {
            "ms"    : 1,        // 1 millisecond
            "s"     : 1000,     // 1 second = 1000 ms
        }
        dict["m"] = 60 * dict["s"];     // 1 minute = 60 s
        dict["h"] = 60 * dict["m"];     // 1 hour = 60 m
        dict["d"] = 24 * dict["h"];     // 1 day = 24 h
        let milliseconds = value*dict[unit];
        let date = new Date(milliseconds);
        return date.toString();
    }
}