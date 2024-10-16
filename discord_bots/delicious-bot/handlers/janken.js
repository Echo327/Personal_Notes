const fs = require("fs"); //filesystem
// const path = rootdir+"/data/data_janken.json"
const path = "./data/data_janken.json"
const encoding = "utf-8";

// janken moves
const moves = {
    0    : "rock",
    1    : "paper",
    2    : "scissors"
}

module.exports = {
    processMove: function(Player_Move, message){
        let reply = "Player plays "+Player_Move+".";
        // x 2.99 ensures near equal chances for any of the 3 moves
        CPU_Move = moves[Math.floor(Math.random() * 2.99)];
        reply += " CPU plays "+CPU_Move+". Result: ";
        if (Player_Move == CPU_Move){
            reply += "Draw.\n( ˶°ㅁ°) !!";
            janken_data["nb_draw"]++;
        }
        else if (
            Player_Move == "rock" && CPU_Move == "scissors" ||
            Player_Move == "paper" && CPU_Move == "rock" ||
            Player_Move == "scissors" && CPU_Move == "paper"
        ){
            reply += "Player wins.\n♪♪＼\(^ω^＼\)( /^ω^)/♪♪";
            janken_data["nb_win"]++;
        }
        else{
            reply += "Player loses.\n(◞‸◟；)";
            janken_data["nb_loss"]++;
        }
        message.reply(reply);
    },
    SaveGameData: function(msg){
        // to-do: increment ID
        // to-do: save last 10 games (if array empt/if array not empty)
        let data = {
            ID : 0,
            userId : msg.author.id,
            name : msg.author.tag,
            WinLoseDraw : janken_data.nb_win+"-"+janken_data.nb_loss+"-"+janken_data.nb_draw,
            Rounds : janken_data.nb_win+janken_data.nb_loss+janken_data.nb_draw,
            time : new Date().toString()
        };
        fs.writeFileSync(path, JSON.stringify(data));
    },
    ReadGameData: function(){
        let GameData = fs.readFileSync(path, encoding);
        if (GameData == undefined || GameData == ""){
            return undefined;
        } 
        return JSON.parse(GameData);
    }
}