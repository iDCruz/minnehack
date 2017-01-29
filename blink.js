var m = require('mraa');
console.log('MRAA Version: ' + m.getVersion());

var myLed = new m.Gpio(8);
myLed.dir(m.DIR_OUT);

var led2 = new m.Gpio(9);
led2.dir(m.DIR_OUT);

var ledState = true;

var temp = new m.Aio(0);


periodicActivity();

function periodicActivity(){
console.log(temp.read());
myLed.write(ledState?1:0);
led2.write(ledState?0:1);
ledState = !ledState;
setTimeout(periodicActivity, 1000);
}

































