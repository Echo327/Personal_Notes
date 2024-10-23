const { processMove, SaveGameData, ReadGameData } = require("./janken");

module.exports = {
    processMessage: function(DateTime, command_prefix, message){
        // ignore any message from bots
        if (message.author.bot){
            console.log("A bot has spoken.");
            return
        }
        // ignore specific channel until slash commands are supported
        else if (message.channel.name == "bot-test-channel"){
            // To-Do: support slash commands 
            return
        }
	    else {
            // Log username and timestamp for user messages
            console.log(DateTime.ms_to_date(message.createdTimestamp, "ms"), "New message was written by", message.author.globalName+".");
        }
        
        // user message pre-processing
        const userMessage = message.content.toLowerCase();

        // process user message
        if (message.content[0] == command_prefix){
            if (annoying){ message.reply("Let me think... 1%...2%...5% processed... ... ..."); }

            // process command
            switch(userMessage){
                case "!help":
                    // Displays general help documentation
                    message.reply("I am here to help!\n \
                    Available commands: !help !morehelp !toggleannoying\n \
                    !serverage !userage\n \
                    !janken\n \
                    (in progress) !poll \n\n \
                    Current mode: "+mode);
                    break;
                case "!morehelp":
                    message.reply(
                        "Help (with Description)\n\
                        !serverage : How old this server is.\n\
                        !userage : How long since you've been on this server.\n\
                        !janken : Rock, Paper, Scissors."
                    );
                    break;
                case "!serverage":
                    // Displays server age
                    let server_create = message.guild.createdTimestamp;
                    let request_date = message.createdTimestamp;
                    let server_age = DateTime.ms_to_age(request_date - server_create, "ms");
                    message.reply("Server created on "+ DateTime.ms_to_date(message.guild.createdTimestamp, "ms")+".\n\
                    "+message.guild.name+" is "+server_age+" old.");
                    break;
                case "!userage":
                    // Displays user join age
                    message.guild.members.fetch().then(
                        (value) => {
                            value.forEach((user) => {
                                if (user.user.id == message.author.id){
                                    let user_joined_on = user.joinedTimestamp;
                                    let request_date = message.createdTimestamp;
                                    let user_age = DateTime.ms_to_age(request_date - user_joined_on, "ms");
                                    message.reply(user.user.tag+", you joined on "+ DateTime.ms_to_date(user_joined_on, "ms")+".\n\
                                    You've been here for "+user_age+".");
                                }
                            });
                        }, (error) => {
                            console.log("Userage Error: "+error);
                        }
                    );
                    break;
                case  "!toggleannoying":
                    if (annoying){
                        annoying = false;
                        message.reply("Sorry for being annoying!...");
                    }
                    else {
                        annoying = true;
                        message.reply("muahahahaha");
                    }
                    break;
                case "!janken":
                    // Switch to rock-paper-scissors mode
                    mode = "janken";
                    janken_data["game_id"]++;
                    janken_data.nb_draw = 0;
                    janken_data.nb_win = 0;
                    janken_data.nb_loss = 0;
                    message.reply("Welcome to unlimited Rock, Paper, Scissors.\n  \
                        Possible moves: **Rock**, **Paper**, **Scissors**.\n \
                        Type \"**results**\" to compare previous game results to current one. \n \
                        Type \"**end**\" to stop the current game and save results.\n \
                        Type \"**ragequit**\" to quit without saving")
                    break;
                default:
                    if (annoying){ message.reply("You don't make sense, jackass.")}
                    else{
                        message.reply("Sorry, I did not understand your request...");
                    }
            }
        }
        // Rock-Paper-Scissors mode
        else if (mode == "janken"){
            switch(userMessage){
                case "rock":
                case "paper":
                case "scissors":
                    // To-Do: only process if game in right server and by right user
                    // To-Do: else either say game in progress elsewhere or by other user
                    processMove(userMessage, message);
                    break;
                case "results":
                    let save_data = ReadGameData(message);
                    if (save_data.length == 0) {
                        message.reply("No previous game data found.");
                        break;
                    }
                    // To-Do: only display data from this server
                    let reply = "";
                    for (let i = 0; i < save_data.length; i++){
                        reply += save_data[i].time +
                        " ; Started by "+save_data[i].name+
                        " ; Win-Lose-Draw : "+save_data[i].WinLoseDraw+"\n"
                    }
                    reply += "Current Game (Win-Lose-Draw) : "+janken_data.nb_win+"-"+janken_data.nb_loss+"-"+janken_data.nb_draw;
                    message.reply(reply);
                    break;
                case "end":
                    SaveGameData(message);
                case "ragequit":
                    mode = "command";
                    message.reply("Game ended.");
                    break;
                default:
                    // allows regular messages during play
                    break;
                    // message.reply("Janken move not recognised.")
            }
        }
        else{
            // reply to non-bot message
            if (annoying){ message.reply("Hello human! You're the best!! I love you!!! <3"); }
        }

        return 0;
    }
}
