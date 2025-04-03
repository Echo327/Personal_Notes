const Discord = require("discord.js"); // discord node module
const DateTime = require('./date_and_time')
const msgCreateHandler = require('./handlers/messageCreate')

// To-Do: add robustness to path variables
// global.rootdir = process.cwd();

// To-Do: Discord Bot Template

const bot_id = require("../private/delicious_bot.json"); // delicious-bot configuration

// variables
const command_prefix = "!";     // will only process commands with this prefix
global.annoying = false;
global.mode = "command";
// To-Do : Persistence of ID after bot reboot
global.janken_data = {
    game_id : 0,
    nb_draw : 0,
    nb_win : 0,
    nb_loss : 0,
    player : "",    // current player
    server: ""  // current server
}
// To-Do : idea for specific cases
// maybe a boolean + which service is waiting for user input to jump to service using router
// global.waiting_user_input = false;

// Main hub for interacting with Discord API
// Intents : which events bots receives
// Partials : receive full data of events
const Delicious = new Discord.Client({
    intents: [
        Discord.GatewayIntentBits.GuildMessages,
        Discord.GatewayIntentBits.GuildMembers,
        Discord.GatewayIntentBits.DirectMessages,
        Discord.GatewayIntentBits.MessageContent,
        Discord.GatewayIntentBits.Guilds
    ],
    partials: [
        Discord.Partials.Message,
        Discord.Partials.Channel,
        Discord.Partials.GuildMember,
        Discord.Partials.User,
        Discord.Partials.GuildScheduledEvent
    ]
});

// When the bot goes online
Delicious.on("ready", (client) => {
    console.log(client.user.tag, "has arrived. This server is now delicious!");

    // Bot Status - Regular
    Delicious.user.setActivity("!help", {type: Discord.ActivityType.Watching});
    
    // Bot Status - In Debug/Maintenance
    // Delicious.user.setPresence({
    //     activities: [{ name: "Maintenance" }],
    //     status: Discord.PresenceUpdateStatus.DoNotDisturb
    // });
});

// When a message is created/posted
Delicious.on("messageCreate", (message) => {
    msgCreateHandler.processMessage(DateTime, command_prefix, message);
});

// Bot login
Delicious.login(bot_id.token);
