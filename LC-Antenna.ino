/*Antenna software con ops
Purpose is to deploy the anetnnas once and ensure deployment
Programmer: Genevieve Cooper, Jaime Dela Vega, Christopher McCormick
date 10/5/2022
*/

//TODO
//Make into state machine - maybe not
//Add testing cases (using #ifdef)

void setup()
{
  
}

void loop()
{
  if (2 && 3 == HIGH){ //are positive
    deployA();
  }
  if (deployA() == true){
      Serial.println("Antennas successfully deployed");
  }
  else if (deployA() == false)
    {
      Serial.println("Antennas not deployed, Deploying B doors");
      deployB();
      if (deployB() == true)
        {
           Serial.println("antennas deployed successfully after a second burn");
        }
        else
          Serial.println("antennas' deployment failure after second burn");
     }
  }
bool deployA()
{
  /*deploys A doors
  //want to deploy sequencially
  //each burn resistor should be on for 3 seconds
  //turn anntenna 1 burn resistor on for 3 seconds
  //wait for 5 seconds
  //turn anntenna 2 burn resistor on for for 3 seconds
  //wait 5 seconds , do anntenna 3 wait, anntenna 4 wait
  //if 4 feedback swithch is high
  //then deployed is true */
  int y = 0, Timer = millis(), D11 = 11;
          if (millis() - Timer >= 5000 && y <= 7) // 5 second break
  {
    Burn(11 - y); //not sure if this will work, trying to change the pin that is needed
    y += 2;
    Timer = millis(); //reset timer
  }
  if (checkBurn(14) == HIGH && checkBurn(15) == HIGH && checkBurn(16) == HIGH && checkBurn(17) == HIGH)
  {
    return true;
  }
  else
    return false;
}
bool deployB()
{
  //deploys b swithches all of them sequentially
  int y = 0; 
  int Timer = millis();
  if (millis() - Timer >= 5000 && y <= 7) // 5 second break
  {
    Burn(12 - y); //change used pin that is needed
    y += 2;
    Timer = millis(); //reset timer
  }
  if (checkBurn(14) == HIGH && checkBurn(15) == HIGH && checkBurn(16) == HIGH && checkBurn(17) == HIGH)
  {
    return true;
  }
  else
    return false;
  
}
void Burn(uint8_t x) {
  int Timer2 = millis();
  while (millis() - Timer2 >= 3000) //wait 3 seconds
  {
    x == HIGH;
    Timer2 = millis(); //reset timer
  }
  //once signal is recieved , send burn signal
}
bool checkBurn(uint8_t x)
{
  //check the feedback switches for high or low, returns true if high
  if (x == HIGH)
  {
    return true;
  }
  else
  {
    Serial.print(x);
    Serial.print("did not burn properly.");
    return false;
  }
}
void Testing() {
  //test for burn
  //instead of burn, blink led for when the resistor should be burned
}
