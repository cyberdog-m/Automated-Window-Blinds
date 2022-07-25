#include <Arduino.h>

char webpage[] PROGMEM = R"=====(
<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Automated Window Blinds</title>
</head>
<style>
    * {
    box-sizing: border-box;
    background-color: #2b2d30;
    }

    h1 {
    color: white;
    font: 1.5em "Dosis", sans-serif;
    font-size: 2em;
    letter-spacing: 1px;
    text-align: center;
    }

    .container {
    display: flex;
    flex-wrap: wrap;
    justify-content: center;
    }

    .container .buttons {
    display: flex;
    flex-direction: column;
    }

    .container a {
    padding: 15px 20px;
    font: 13px "Montserrat", sans-serif;
    font-weight: 700;
    letter-spacing: 2px;
    text-transform: uppercase;
    text-decoration: none;
    text-align: center;
    margin: 1em;
    }

    .button {
    color: white;
    background-color: #2d7eff;
    border: 5px solid transparent;
    transition: 0.2s ease;
    border-radius: 50px;
    }

    input[type=text]{
    width:50%;
    border:2px solid #aaa;
    border-radius:4px;
    margin:8px 0;
    outline:none;
    padding:8px;
    box-sizing:border-box;
    transition:.3s;
    }
</style>
<body>
    <h1>Automated Window Blinds</h1>
    <div class="container">
        <div class="buttons">
            <a class="button" onclick="window.location = 'http://'+location.hostname+'/blind/up'">Move Up</a>
            <a class="button" onclick="window.location = 'http://'+location.hostname+'/blind/down'" style="background-color: #119598;">Move Down</a>
	    </div>
    </div>
</body>
</html>
)=====";