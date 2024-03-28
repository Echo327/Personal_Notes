module.exports = {
    json_prep: function(hero, roster){
        console.log(hero.hero_name);
    
        for (let i=0; i < roster.length; i++){
            console.log(roster[i].name);
        }
    }
}
