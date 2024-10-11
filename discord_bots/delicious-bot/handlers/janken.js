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
            reply += "Draw.\n( ˶°ㅁ°) !!"
            nb_draw += 1;
        }
        else if (
            Player_Move == "rock" && CPU_Move == "scissors" ||
            Player_Move == "paper" && CPU_Move == "rock" ||
            Player_Move == "scissors" && CPU_Move == "paper"
        ){
            reply += "Player wins.\n♪♪＼\(^ω^＼\)( /^ω^)/♪♪"
            nb_win += 1;
        }
        else{
            reply += "Player loses.\n(◞‸◟；)"
            nb_loss += 1;
        }
        message.reply(reply);
    },
    SaveGameData: function(msg){
        let data = {
            ID : 0,
            userId : msg.author.id,
            name : msg.author.tag,
            WinLoseDraw : nb_win+"-"+nb_loss+"-"+nb_draw,
            Rounds : nb_win+nb_loss+nb_draw,
            time : new Date().toString()
        };
        fs.writeFileSync(path, JSON.stringify(data));
    },
    ReadGameData: function(){
        return JSON.parse(fs.readFileSync(path, encoding));
    }
}