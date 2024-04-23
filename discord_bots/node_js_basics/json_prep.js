module.exports = {
    json_prep: function(hero, roster){
        // Will be used in discord bots later
        console.log(hero.hero_name);
    
        for (let i=0; i < roster.length; i++){
            console.log(roster[i].name);
        }
    }
}
