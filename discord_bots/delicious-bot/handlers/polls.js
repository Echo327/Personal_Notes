const Discord = require("discord.js"); // discord node module
const fs = require("fs"); //filesystem
const path_polls = "./data/data_polls.json"
const encoding = "utf-8";

// To-Do : Find max_id+1 in .json file for starting ID
var poll_id = 0;
// To-Do : Ask Options when creating a poll (Wait for User Input?)
// To-Do : track individual votes using an object similar to this:
// To-Do : Allow voter to change votes if poll is not closed
// To-Do : Do not allow voter to vote more than once
var poll_data = {
    id : 0,
    title : "",
    options : ["Yes", "No"],
    open : true
// yes : 0, // option 1
// no : 0, // option 2
// votedYes : [], // option 1
// votedNo : [], // option 2
// date : new Date().toString() // date created
};
// To-Do Support custom options

module.exports = {
    pollActive: function(message){
        // To-Do : Iterate over all polls and return open polls list
        let reply = "Active polls:\n"
        reply += "Title : " + poll_data.title + "\n";
        reply += "ID : " + poll_data.id + "\n";
        reply += "Options : " + poll_data.options + "\n";
        message.reply(reply)
    },
    pollHistory: function(message){
        // To-Do : returns summary list of closed polls from a saved file
        message.reply("List of closed polls.")
    },
    pollInfo: function(message, id_requested){
        // To-Do : Check valid id
        // To-Do : Return actual Poll Data (with status : open or closed)
        let embedMessage = new Discord.EmbedBuilder()
            .setColor("#0099FF")
            .setTitle("Title") // To-Do : placeholder for poll.title
            .setTimestamp() // To-Do : new.Date(poll.date)
            .setFooter({
                text : "Footer Text" + id_requested
            });
        
        embedMessage.addFields({
                name : "yes",
                value : "2",
                inline : true
            },{
                name : "no",
                value : "1",
                inline : true
            });
        
        message.reply({
            embeds : [embedMessage]
        });

        // To-Do : Return Embedded Graph to show data in poll
        // using chart.js and canvas

    },
    pollVote: function(message, id_requested, answer){
        // To-Do : finds active poll by id and increments vote
        // To-Do : keep a list of answered users per poll so double answers are not possible
        // To-Do : Add click to vote in embed
        // Requirement : Every user only has one vote per poll.
        message.reply("You voted "+answer+" in poll #"+id_requested);
    },
    pollCreate: function(userMessage, message){
        let title = userMessage.slice(1).join(" ");
        console.log("title = "+title);
        // To-Do : add vector of active polls (1 poll_data per array item)
        poll_data.id = poll_id;
        poll_data.title = title;
        message.reply("Poll "+poll_id+" created.");
        poll_id++;
    },
    pollClose: function(message, id_requested){
        // To-Do : Iterate over open polls and close the one requested
        // To-Do : Save closed poll to data_polls.json
        message.reply("Poll #"+id_requested+" closed.");
    }
}
