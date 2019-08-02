var ipAddress = '192.168.4.1';
var wifiSSID = 'Pignap';
var wifiAlgorithm = 'WPA';
var wifiPSK = 'hcp-technology';

function setStatusFn(status) {
    return function() {
        document.getElementById('status').innerHTML = status;
    };
}

function setStatus(status) {
    return setStatusFn(status)();
}

function tryToOpen() {
    function tryAgain() {
        new Ping().ping(
            [{query: ipAddress, timeout: 1, retry: 1, version: 'v4'}],
            function(res) {
                if (res[0].response.status === 'success')
                    cordova.InAppBrowser.open('http://' + ipAddress, '_self');
                else
                    tryAgain();
            }, tryAgain);
    }
    tryAgain();
}

window.tryToConnect = function tryToConnect() {
    setStatus('<img src="img/loading.svg" width="40" height="40">');
    WifiWizard2.scan().then(function(networks) {
        var pignapSSIDs = [];
        for (var i = 0; i < networks.length; i++)
            if (networks[i].SSID.indexOf(wifiSSID) !== -1)
            pignapSSIDs.push(networks[i].SSID);
        if (pignapSSIDs.length === 0)
            setStatus('Es ist kein Pignap-WLAN in Reichweite.' +
                '<br><a class="button" href="#" onclick="deviceready();">Erneut versuchen</a>');
        else {
            WifiWizard2.connect(pignapSSIDs[0], false, wifiPSK, wifiAlgorithm, false).then(
                tryToOpen,
                setStatusFn('Die Verbindung zum Pignap-WLAN konnte nicht hergestellt werden.' +
                    '<br><a class="button" href="#" onclick="deviceready();">Erneut versuchen</a>'));
        }
    }, setStatusFn('Verbinden Sie sich manuell mit dem Pignap-WLAN, um fortzufahren.' +
        '<br><a class="button" href="#" onclick="deviceready();">Erneut versuchen</a>'));
}

window.deviceready = function deviceready() {
    setStatus('<img src="img/loading.svg" width="40" height="40">');
    WifiWizard2.getConnectedSSID().then(function(ssid) {
        if (ssid.indexOf(wifiSSID) !== -1)
            tryToOpen();
        else
            tryToConnect();
    }, tryToConnect);
};

document.addEventListener('deviceready', deviceready);