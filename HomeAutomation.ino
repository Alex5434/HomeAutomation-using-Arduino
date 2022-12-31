int distance = 0;
long readUltrasonicDistance(int triggerPin, int echoPin)
{
	pinMode(triggerPin, OUTPUT);
	digitalWrite(triggerPin, LOW);
	delayMicroseconds(2);


	digitalWrite(triggerPin, HIGH);
	delayMicroseconds(10);
	digitalWrite(triggerPin, LOW);
	pinMode(echoPin, INPUT);


	return pulseIn(echoPin, HIGH);
}
void setup()
{
	pinMode(9, OUTPUT);
}
void loop()
{
	distance = 0.01723 * readUltrasonicDistance(10, 11);
	digitalWrite(9, LOW);
	if(distance > 150)
	{
	digitalWrite(9, HIGH);
	delay(5000);
	if(distance < 30)
	{
	digitalWrite(9, LOW);
	}
    }
}
