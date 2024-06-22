module.exports = {
    processMessage: function(DateTime, command_prefix, message){
        // if message written by user(false)/bot(true)
        if (message.author.bot){
            console.log("A bot has spoken.");
            // following line allows ignoring any message from bots
            return
        }
        else {
            console.log(DateTime.ms_to_date(message.createdTimestamp, "ms"), "New message was written by", message.author.globalName+".");
        }

        const userMessage = message.content.toLowerCase();
        // check for bot command
        if (message.content[0] == command_prefix){
            if (annoying){ message.reply("Let me think... 1%...2%...5% processed... ... ..."); }

            // process command
            switch(userMessage){
                case "!help":
                    message.reply("I am here to help!\n \
                    Available commands: !help !toggleannoying\n \
                    (in progress) !serverage !userage");
                    break;
                case "!serverage":
                    console.log(message.createdTimestamp);
                    console.log(message.guild.createdTimestamp);
                    let age = message.createdTimestamp - message.guild.createdTimestamp;
                    DateTime.ms_to_age(age);
                    message.reply("Server created on "+ DateTime.ms_to_date(message.guild.createdTimestamp, "ms"));
                    break;
                case "!userage":
                    message.guild.members.fetch().then(
                        (value) => {
                            value.forEach(user => {
                                if (user.user.id == message.author.id){
                                    console.log(user.joinedTimestamp);
                                    message.reply(user.user.tag+", you joined on "+ DateTime.ms_to_date(user.joinedTimestamp, "ms"));
                                }
                            });
                        }, (error) => {
                            console.log(error);
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
                default:
                    message.reply("Sorry, I did not understand your request...");
            }
        }
        else{
            // reply to non-bot message
            if (annoying){ message.reply("Hello human! You're the best!! I love you!!! <3"); }
        }

        return;
    }
}