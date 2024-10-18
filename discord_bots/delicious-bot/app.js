const Discord = require("discord.js"); // discord node module
const DateTime = require('./date_and_time')
const msgCreateHandler = require('./handlers/messageCreate')

const bot_id = require("../private/delicious_bot.json"); // delicious-bot configuration
const { processMessage } = require("./handlers/messageCreate");

global.rootdir = process.cwd();

// variables
const command_prefix = "!";
global.annoying = false;
global.mode = "command";
janken_game_id = 0;

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

    // Bot Status
    Delicious.user.setActivity("!help", {type: Discord.ActivityType.Watching});
});

// When a message is created/posted
Delicious.on("messageCreate", (message) => {
    msgCreateHandler.processMessage(DateTime, command_prefix, message);
});

// Bot login
Delicious.login(bot_id.token);
