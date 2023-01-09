function onButton() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "on", true);
    xhttp.send()
}

function offButton() {
    var xhttp = new XMLHttpRequest();
    xhttp.open("GET", "off", true);
    xhttp.send()
}

function getData() {
    var xhttp = new XMLHttpRequest();

    xhttp.onreadystatechange = function() {
        if(this.readyState == 4 && this.status == 200) {
            document.getElementById("valeurLuminosite").innerHTML = this.responseText;
        }
    };

    xhttp.open("GET", "lireLuminosite", true);
    xhttp.send();
}

setInterval(getData, 2000);