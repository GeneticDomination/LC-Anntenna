//anntenna software con ops
//purpose is to deploy the annetnnas one and to ensure they are deployed properly
//Programmer: Genevieve Cooper, Jaime Dela Vega, Christopher McCormick
//date 10/5/2022

//TODO
//Change Pin Names
//Make into state machine
//Add testing cases (using #ifdef)
void setup()
{
  //int Timer = millis();
}

void loop()
{
  int D2 = 2, D3 = 3;
  if (D2 && D3 == HIGH){ //are positive
    Deploy_A();
  }
  if (Deploy_A() == true){
      Serial.print("anntenna's deployed successfully");
  }
  else if (Deploy_A() == false)
    {
      Serial.print("anntennas not deployed, Deploying B doors");
      Deploy_B();
      if (Deploy_B() == true)
        {
           Serial.print("anntenna's deployed successfully after a second burn");
        }
        else
          Serial.print("anntenna's deployment failure after second burn");
     }
  }
bool Deploy_A()
{
  //deplays A doors
  //want to deploy sequencially
  //each burn resistor should be on for 3 seconds
  //turn anntenna 1 burn resistor on for 3 seconds
  //wait for 5 seconds
  //turn anntenna 2 burn resistor on for for 3 seconds
  //wait 5 seconds , do anntenna 3 wait, anntenna 4 wait
  //if 4 feedback swithch is high
  //then depolyed is true
  //if d3 (deployA) then d11 turn high.
  int y = 0, Timer = millis(), D11 = 11;
          if (millis() - Timer >= 5000 && y <= 7) // 5 second break
  {
    Burn(11 - y); //not sure if this will work, trying to change the pin that is needed
    y += 2;
    Timer = millis(); //reset timer
  }
  if (CheckBurn(14) == HIGH && CheckBurn(15) == HIGH && CheckBurn(16) == HIGH && CheckBurn(17) == HIGH)
  {
    return true;
  }
  else
    return false;
}
bool Deploy_B()
{
  //deploys b swithches all of them sequentially
  int z = 0; 
  int Timer = millis();
  if (millis() - Timer >= 5000 && z <= 7) // 5 second break
  {
    Burn(12 - z); //not sure if this will work, trying to change the pin that is needed
    z += 2;
    Timer = millis(); //reset timer
  }
  if (CheckBurn(14) == HIGH && CheckBurn(15) == HIGH && CheckBurn(16) == HIGH && CheckBurn(17) == HIGH)
  {
    return true;
  }
  else
    return false;
  
}
void Burn(int x) {
  int Timer2 = millis();
  while (millis() - Timer2 >= 3000) //wait 3 seconds
  {
    x == HIGH;
    Timer2 = millis(); //reset timer
  }
  //once signal is recieved , send burn signal
}
bool CheckBurn(int x)
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
