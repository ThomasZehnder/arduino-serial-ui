var shell = require("shelljs");

console.log("Start to load node-red")
shell.exec("node-red  --settings ./node-red/settings.json --title ARDUINO-UI --userDir ./node-red test-flow-UART.json");