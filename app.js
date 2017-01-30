var http = require('http');
var m = require('mraa');
console.log('MRAA Version: ' + m.getVersion());

var myLed = new m.Gpio(8);
myLed.dir(m.DIR_OUT);                          

var led2 = new m.Gpio(9);
led2.dir(m.DIR_OUT);

var ledState = true;

var temp = new m.Aio(0);

var alarm = new m.Gpio(7);
alarm.dir(m.DIR_OUT);




periodicActivity();

function periodicActivity(){
  var R = 1023.0 / temp.read() - 1.0;
  R = 100000.0 * R;
  var temperatureC = 1.0 / (Math.log(R/100000.0)/4275+1/298.15) - 273.15;
  var temperatureF = (temperatureC * (9/5)) + 32;

  console.log(temperatureC);
  console.log(temperatureF);
  console.log(temp.read());

  if(temperatureF > 85){
  myLed.write(ledState?1:0);
  led2.write(ledState?0:1);
  alarm.write(1);
  ledState = !ledState;
  }
  else{
  alarm.write(0);
  }
  setTimeout(periodicActivity, 1000);
}
