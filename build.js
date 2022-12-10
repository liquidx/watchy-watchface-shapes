import { program } from 'commander';
import fs from 'fs';


const main = () => {
  program
    .version('0.0.1')
    .option('-c, --city <number>', 'Open Weather City ID', 1850147) // Tokyo
    .option('-t, --timezone-offset <number>', 'GMT offset in secs', 3600 * 9) // Tokyo
    .option('-o, --output <filename>', 'Settings file', 'src/settings.h')


  program.parse();

  const { city, timezoneOffset, output } = program.opts();


  const contents = `
#ifndef SETTINGS_H
#define SETTINGS_H

watchySettings settings{
  .cityID = ${city},
  .weatherAPIKey = "f058fe1cad2afe8e2ddc5d063a64cecb",
  .weatherURL = "http://api.openweathermap.org/data/2.5/weather?id=",
  .weatherUnit = "metric",
  .weatherLang = "en",
  .weatherUpdateInterval = 30,
  .ntpServer = "pool.ntp.org",
  .gmtOffset = ${timezoneOffset},
};
#endif
  `

  console.log(contents)
  return fs.writeFileSync(output, contents)
}

main();
