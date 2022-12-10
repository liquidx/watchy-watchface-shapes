
#ifndef SETTINGS_H
#define SETTINGS_H

watchySettings settings{
    .cityID = 1850147,
    .weatherAPIKey = "f058fe1cad2afe8e2ddc5d063a64cecb",
    .weatherURL = "http://api.openweathermap.org/data/2.5/weather?id=",
    .weatherUnit = "metric",
    .weatherLang = "en",
    .weatherUpdateInterval = 30,
    .ntpServer = "pool.ntp.org",
    .gmtOffset = 32400,
};
#endif
